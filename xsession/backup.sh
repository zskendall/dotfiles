#!/bin/bash

source ~/.backup.conf

extract_count() {
  echo "$1" | awk -F': ' '{print $2}' | awk '{print $1}'
}

# clean up any prior state
rm -f /tmp/backup.out /tmp/backup.err

if [ -n "$(podman ps | grep "$CONTAINER")" ]; then
  podman exec "$CONTAINER" pg_dump -U "$POSTGRES_USER" "$POSTGRES_DB" > /tmp/dump.sql 2>/tmp/pgdump.err

  if [ $? -ne 0 ]; then
    # postgres dump failed, notify and exit
    EMBED=$(cat <<EOF
    {
      "title": "**❌ pg_dump failed ❌**",
      "fields": [
        {"name": "src", "value": "$HOSTNAME"},
        {"name": "Time ($(timedatectl show | grep Timezone | cut -d'=' -f 2))", "value": "$(date +"%Y-%m-%d %H:%M:%S")"}
      ],
      "color": "16711680"
    }
EOF
)
    ~/discord-webhook-notification/discord-webhook.sh -e "$EMBED"
    exit 1
  fi

  if ! diff -q /tmp/dump.sql "$DUMP_PATH" > /dev/null 2>&1; then
    mv /tmp/dump.sql "$DUMP_PATH"
  fi
fi

/usr/bin/rsync -ah --inplace --info=progress2 --stats \
  --exclude="$EXCLUDE" "$SRC" "$DEST" > /tmp/backup.out 2>/tmp/backup.err

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
  MSG="$FILES\n$CREATED\n$DELETED\n$TRANSFERRED"
fi

if [ $STATUS -eq 0 ]; then
  TITLE="✅ rsync succeeded ✅"
  COLOR="65280"
else
  TITLE="❌ rsync failed ❌"
  COLOR="16711680"
  ERR=$(grep "failed" /tmp/backup.err | sed s/\"/\'/g | awk -F':' '{print $3}' | xargs)
  [ ! -z "$MSG" ] && MSG="$ERR\n-----\n$MSG"
fi

EMBED=$(cat <<EOF
{
  "title": "**$TITLE**",
  "fields": [
    {"name": "src", "value": "$HOSTNAME"},
    {"name": "Status: $STATUS", "value": "$MSG"},
    {"name": "Time ($(timedatectl show | grep Timezone | cut -d'=' -f 2))", "value": "$(date +"%Y-%m-%d %H:%M:%S")"}
  ],
  "color": "$COLOR"
}
EOF
)

~/discord-webhook-notification/discord-webhook.sh -e "$EMBED"
