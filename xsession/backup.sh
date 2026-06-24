#!/bin/bash

source ~/.backup.conf

extract_count() {
  echo "$1" | awk -F': ' '{print $2}' | awk '{print $1}'
}

build_embed() {
  EMBED=$(cat <<EOF
  {
    "title": "**$1**",
    "fields": [
      {"name": "src", "value": "$HOSTNAME"},
      {"name": "Time ($(timedatectl show | grep Timezone | cut -d'=' -f 2))", "value": "$(date +"%Y-%m-%d %H:%M:%S")"}
    ],
    "color": "${2:-16711680}"
  }
EOF
)
}

ntfy_notify() {
  local tags=${2:-bell}
  local body=$(cat <<EOF
src: $HOSTNAME
${3:+$3
}

Time ($(timedatectl show | grep Timezone | cut -d'=' -f 2))
$(date +"%Y-%m-%d %H:%M:%S")
EOF
)
  curl -u :$NTFY_TOKEN -H "Title: $1" -H "Tags: $tags" -H "Markdown: yes" -H "Priority: ${4:-high}" -d "$body" $NTFY_URL
}

dump_dbs() {
  for service in $DUMP_SERVICES; do
    local upper=$(echo "$service" | tr '[:lower:]' '[:upper:]')
    local container_var="${upper}_CONTAINER"
    local container="${!container_var}"
    if [ -n "$(podman ps | grep "$container")" ]; then
      local pguser_var="${upper}_USER"
      local db_var="${upper}_DB"
      podman exec "$container" pg_dump -U "${!pguser_var}" "${!db_var}" > "/tmp/$service.sql" 2>"/tmp/dump_$service.err"

      if [ $? -ne 0 ]; then
        # postgres dump failed, notify and exit
        build_embed "❌ pg_dump for $service failed ❌"
        ~/discord-webhook-notification/discord-webhook.sh -e "$EMBED"
        ntfy_notify "pg_dump for $service failed ❌" "x"
        exit 1
      fi

      local dump_path_var="${upper}_DUMP_PATH"
      local dump_path="${!dump_path_var}"
      if ! diff -q "/tmp/$service.sql" "$dump_path" > /dev/null 2>&1; then
        mv "/tmp/$service.sql" "$dump_path"
      fi
    fi
  done
}

dump_dbs

# snapshot the pool
if ! zfs snapshot "$SRC@$(date +%Y-%m-%d)" 2>/tmp/snapshot.err; then
  if grep -q "already exists" /tmp/snapshot.err; then
    echo "snapshot already exists, continuing" > /tmp/snapshot.out
  else
    build_embed "❌ snapshot failed ❌"
    ~/discord-webhook-notification/discord-webhook.sh -e "$EMBED"
    ntfy_notify "snapshot failed ❌" "x"
    exit 1
  fi
fi

# prune old snapshots
zfs list -t snapshot -o name | grep "$SRC@" | head -n -30 | xargs -r zfs destroy

/usr/bin/rsync -ah --inplace --info=progress2 --stats \
  --exclude="$EXCLUDE" "/$SRC/" "$DEST" > /tmp/backup.out 2>/tmp/backup.err

STATUS=$?

# construct informational message with file transfer stats
FILES=$(grep -m1 ^Number /tmp/backup.out)
CREATED=$(grep -m2 ^Number /tmp/backup.out | tail -n1)
DELETED=$(grep -m3 ^Number /tmp/backup.out | tail -n1)
TRANSFERRED=$(grep -m4 ^Number /tmp/backup.out | tail -n1)

if [ -z "$CREATED" ] && [ -z "$DELETED" ] && [ -z "$TRANSFERRED" ]; then
  MSG=""
elif (( $(extract_count "$CREATED") == 0 && $(extract_count "$DELETED") == 0 &&
        $(extract_count "$TRANSFERRED") == 0 )); then
  MSG="nothing to sync"
else
  MSG=$(printf "%s\n%s\n%s\n%s" "$FILES" "$CREATED" "$DELETED" "$TRANSFERRED")
fi

if [ $STATUS -eq 0 ]; then
  build_embed "✅ rsync succeeded ✅" "65280"
  ntfy_notify "rsync succeeded ✅" "white_check_mark" "$MSG" "low"
else
  build_embed "❌ rsync failed ❌"
  ERR=$(cat /tmp/backup.err | awk 'NF > 0 { print }' | head -n 1 | awk -F': ' '{print $3}' | xargs)
  [ ! -z "$MSG" ] && MSG=$(printf "%s\n-----\n%s" "$ERR" "$MSG") || MSG="$ERR"
  ntfy_notify "rsync failed ❌" "x" "$MSG"
fi

EMBED=$(echo "$EMBED" | jq --arg status "$STATUS" --arg msg "$MSG" \
  '.fields |= [.[0]] + [{"name": ("Status: " + $status), "value": $msg}] + .[1:]')

~/discord-webhook-notification/discord-webhook.sh -e "$EMBED"
