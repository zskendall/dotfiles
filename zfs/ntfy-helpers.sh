#!/bin/bash

# send a notification via ntfy
# usage: ntfy_notify <title>
# requires: NTFY_TOKEN, NTFY_URL, NTFY_TOPIC
ntfy_notify() {
  local body=$(cat <<EOF
src: $HOSTNAME
${MSG:+$MSG
}
Time ($(timedatectl show | grep Timezone | cut -d'=' -f 2))
$(date +"%Y-%m-%d %H:%M:%S")
EOF
)
  curl -u :$NTFY_TOKEN -H "Title: $1" -H "Tags: ${TAGS:-bell}" -H "Markdown: yes" \
    -H "Priority: ${PRIORITY:-high}" -d "$body" "$NTFY_URL/$NTFY_TOPIC"
}
