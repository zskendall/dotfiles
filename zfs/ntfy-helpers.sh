#!/bin/bash

# send a notification via ntfy
# usage: ntfy_notify <title> [tags] [message] [priority]
# requires: NTFY_TOKEN, NTFY_URL, NTFY_TOPIC
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
  curl -u :$NTFY_TOKEN -H "Title: $1" -H "Tags: $tags" -H "Markdown: yes" \
    -H "Priority: ${4:-high}" -d "$body" "$NTFY_URL/$NTFY_TOPIC"
}
