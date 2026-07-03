#!/bin/bash

source /home/zoe/dotfiles/zfs/ntfy-helpers.sh
source ~/.backup.conf

extract_count() {
  echo "$1" | awk -F': ' '{print $2}' | awk '{print $1}'
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
        ntfy_notify "pg_dump for $service failed ❌"
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

TAGS="x"

dump_dbs

# snapshot the pool
SNAP=$(date +%Y%m%d-%H%M%S)
if ! zfs snapshot "$SRC@$SNAP" 2>/tmp/snapshot.err; then
  ntfy_notify "snapshot failed ❌"
  exit 1
fi

# prune old snapshots
zfs list -t snapshot -o name | grep "$SRC@" | head -n -30 | xargs -r zfs destroy

/usr/bin/rsync -ah -e "ssh -i $SSH_KEY" --inplace --info=progress2 --stats \
  --exclude="$EXCLUDE" --exclude='.~lock.*#' --exclude='~$*' \
  "/$SRC/.zfs/snapshot/$SNAP/" "$DEST" > /tmp/backup.out 2>/tmp/backup.err

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
  TAGS="white_check_mark" PRIORITY="low" ntfy_notify "rsync succeeded ✅"
else
  ERR=$(cat /tmp/backup.err | awk 'NF > 0 { print }' | head -n 1 | awk -F': ' '{print $3}' | xargs)
  [ ! -z "$MSG" ] && MSG=$(printf "%s\n-----\n%s" "$ERR" "$MSG") || MSG="$ERR"
  ntfy_notify "rsync failed ❌"
fi
