#!/bin/bash

# Terminate already running bar instances
killall -q polybar

# Wait until the processes have been shut down
while pgrep -x polybar >/dev/null; do sleep 1; done

# Launch normal polybar on all monitors, optionally hiding them
WIDTH=$(xdpyinfo | grep -oP 'dimensions:\s+\K\S+' | cut -d"x" -f1)
for m in $(polybar --list-monitors | cut -d":" -f1); do
  # Check for a battery power supply as indicator for displaying the expanded
  # polybar with battery and wifi status.
  if [[ $(ls /sys/class/power_supply/ | egrep -i bat | wc -l) -gt 0 ]]; then
    MONITOR=$m polybar --reload expanded &
  else
    MONITOR=$m polybar --reload default &
  fi
  # sleep 5;
  # sh ~/dotfiles/polybar/.config/polybar/hideIt.sh --name "^polybar-tray_"$m"$" --direction top --region 0x0+$WIDTH+10 &
done

# Start and hide an ipc weather watcher; based on
# https://github.com/ntcarlson/dotfiles/blob/gamma/i3/scripts/polybar_wrapper,
# linked from
# reddit.com/r/unixporn/comments/92guq6/i3polybar_animated_polybar_drop_down_menus/
MONITOR="DP-5" polybar weather &
BAR_ID=$!
echo "weather watcher id: $BAR_ID"
ln -sf /tmp/polybar_mqueue.$BAR_ID /tmp/polybar_mqueue_weather
sleep 2
echo "cmd:hide" >> /tmp/polybar_mqueue_weather
