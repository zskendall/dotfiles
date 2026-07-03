#!/bin/bash

source /etc/zfs/secrets/ntfy

LOGFILE=/tmp/prune.err
> "$LOGFILE"

CUTOFF=$(date -d "30 days ago" +%Y%m%d)
COUNT=0
FAILS=0
while read snap; do
  SNAP_DATE=$(echo "$snap" | grep -oP '\d{4}-?\d{2}-?\d{2}' | tr -d '-')
  if [[ "$SNAP_DATE" < "$CUTOFF" ]]; then
    ERR=$(zfs destroy "$snap" 2>&1)
    if [[ $? -ne 0 ]]; then
      echo "$snap : $ERR" >> $LOGFILE
      ((FAILS++))
    else
      ((++COUNT))
    fi
  fi
done < <(zfs list -t snapshot -o name -H)

runuser -u zoe -- /home/zoe/dotfiles/zfs/notify.sh prune "$NTFY_TOPIC" "$COUNT" "$FAILS"
