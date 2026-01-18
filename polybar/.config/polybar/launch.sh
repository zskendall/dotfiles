#!/bin/bash

set_vars() {
  export NETWORK
  export NETWORK_CONNECTED_LABEL
  export NETWORK_DISCONNECTED_LABEL
  export NETWORK_CONNECTED
  export NETWORK_DISCONNECTED

  local connected="$(nmcli device status | grep connected)"
  NETWORK="$(echo $connected | awk -F" " '{print $1}')"
  NET_TYPE="$(echo $connected | awk -F" " '{print $2}')"

  if [[ "$NET_TYPE" == *"wifi"* ]]; then
    NETWORK_CONNECTED_LABEL="%essid% %signal%%"
    NETWORK_CONNECTED="%{A1:~/.i3/scripts/wifi:} <label-connected>%{A}"
    NETWORK_DISCONNECTED_LABEL="%{F#b30000} %{F-}"
    NETWORK_DISCONNECTED="%{A1:~/.i3/scripts/wifi:}<label-disconnected>%{A}"
  fi
}

# Terminate already running bar instances
killall -q polybar

# Wait until the processes have been shut down
while pgrep -x polybar >/dev/null; do sleep 1; done

set_vars

# Launch normal polybar on all monitors, optionally hiding them
WIDTH=$(xdpyinfo | grep -oP 'dimensions:\s+\K\S+' | cut -d"x" -f1)
[[ -r "~/.polybar.$HOSTNAME.config.ini" ]] && CONFIG="~/.polybar.$HOSTNAME.config.ini" || CONFIG="~/.config/polybar/config.ini"
for m in $(polybar --list-monitors | cut -d":" -f1); do
  if [[ "$NET_TYPE" == *"wifi"* ]]; then
    MONITOR=$m polybar -c $CONFIG --reload expanded &
  else
    MONITOR=$m polybar -c $CONFIG --reload bubl &
    MONITOR=$m polybar -c $CONFIG --reload bubm &
    MONITOR=$m polybar -c $CONFIG --reload bubr &
  fi
  # sleep 5;
  # sh ~/dotfiles/polybar/.config/polybar/hideIt.sh --name "^polybar-tray_"$m"$" --direction top --region 0x0+$WIDTH+10 &
done

if [[ $(ls /sys/class/power_supply/ | egrep -i bat | wc -l) -eq 0 ]]; then
  # Start and hide an ipc weather watcher; based on
  # https://github.com/ntcarlson/dotfiles/blob/gamma/i3/scripts/polybar_wrapper,
  # linked from
  # reddit.com/r/unixporn/comments/92guq6/i3polybar_animated_polybar_drop_down_menus/
  MONITOR=$m polybar weather &
  BAR_ID=$!
  echo "weather watcher id: $BAR_ID"
  ln -sf /tmp/polybar_mqueue.$BAR_ID /tmp/polybar_mqueue_weather
  sleep 2
  echo "cmd:hide" >> /tmp/polybar_mqueue_weather
fi
