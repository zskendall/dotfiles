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

if [ -n "$(podman ps | grep "$CONTAINER")" ]; then
  podman exec "$CONTAINER" pg_dump -U "$POSTGRES_USER" "$POSTGRES_DB" > /tmp/dump.sql 2>/tmp/pgdump.err

  if [ $? -ne 0 ]; then
    # postgres dump failed, notify and exit
    build_embed "❌ pg_dump failed ❌"
    ~/discord-webhook-notification/discord-webhook.sh -e "$EMBED"
    exit 1
  fi

  if ! diff -q /tmp/dump.sql "$DUMP_PATH" > /dev/null 2>&1; then
    mv /tmp/dump.sql "$DUMP_PATH"
  fi
fi

# snapshot the pool
if ! zfs snapshot "$SRC@$(date +%Y-%m-%d)" 2>/tmp/snapshot.err; then
  if grep -q "already exists" /tmp/snapshot.err; then
    echo "snapshot already exists, continuing" > /tmp/snapshot.out
  else
    build_embed "❌ snapshot failed ❌"
    ~/discord-webhook-notification/discord-webhook.sh -e "$EMBED"
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

if (( $(extract_count "$CREATED") == 0 && $(extract_count "$DELETED") == 0 &&
      $(extract_count "$TRANSFERRED") == 0 )); then
  MSG="nothing to sync"
else
  MSG=$(printf "%s\n%s\n%s\n%s" "$FILES" "$CREATED" "$DELETED" "$TRANSFERRED")
fi

if [ $STATUS -eq 0 ]; then
  build_embed "✅ rsync succeeded ✅" "65280"
else
  build_embed "❌ rsync failed ❌"
  ERR=$(grep "failed" /tmp/backup.err | sed s/\"/\'/g | awk -F':' '{print $3}' | xargs)
  [ ! -z "$MSG" ] && MSG=$(printf "%s\n-----\n%s" "$ERR" "$MSG")
fi

EMBED=$(echo "$EMBED" | jq --arg status "$STATUS" --arg msg "$MSG" \
  '.fields |= [.[0]] + [{"name": ("Status: " + $status), "value": $msg}] + .[1:]')

~/discord-webhook-notification/discord-webhook.sh -e "$EMBED"
