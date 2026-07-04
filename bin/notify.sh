#!/bin/bash

source /home/zoe/dotfiles/bin/ntfy-helpers.sh
source /home/zoe/.backup.conf

scrub_finish() {
  NTFY_TOPIC="$1"
  MSG=$(zpool status -x)
  [[ "$MSG" == *healthy* ]] && PRIORITY="default" || PRIORITY="high"
  ntfy_notify "zfs scrub completed"
}

prune_finish() {
  NTFY_TOPIC="$1"
  local count="$2"
  local fails="$3"
  local plural=$([[ "$count" -ne 1 ]] && echo "s")
  if [[ $fails -gt 0 ]]; then
    TITLE="snapshot prune failed ❌"
    TAGS="x"
    MSG=$(printf "%s\n%s" "pruned $count snapshot$plural" \
      "failed to prune $fails snapshot$([[ "$fails" -ne 1 ]] && echo "s")")
  else
    TAGS="white_check_mark"
    [[ "$count" -eq 0 ]] && MSG="nothing to prune" || MSG="pruned $count snapshot$plural"
  fi
  PRIORITY="default" ntfy_notify "${TITLE:-"snapshot prune succeeded ✅"}"
}

auto-update_finish() {
  NTFY_TOPIC="$1"
  MSG=$(journalctl --user -u podman-auto-update.service -o cat --since "10 minutes ago" | grep true)
  [[ -n "$MSG" ]] && ntfy_notify "containers updated"
}

EVENT="$1"; shift
if declare -f "${EVENT}_finish" > /dev/null; then
  ${EVENT}_finish "$@"
else
  TAGS="bangbang" ntfy_notify "Unknown event: $EVENT"
fi
