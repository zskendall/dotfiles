#!/bin/bash

HOST=$(hostname)

# Terminate already running bar instances
killall -q polybar

# Wait until the processes have been shut down
while pgrep -x polybar >/dev/null; do sleep 1; done

# Launch and auto-hide polybar on all monitors
WIDTH=$(xdpyinfo | grep -oP 'dimensions:\s+\K\S+' | cut -d"x" -f1)
for m in $(polybar --list-monitors | cut -d":" -f1); do
  if [[ $HOST == *"laptop"* ]]; then
    MONITOR=$m polybar --reload expanded &
  else
    MONITOR=$m polybar --reload default &
  fi
  # sleep 5;
  # sh ~/dotfiles/polybar/.config/polybar/hideIt.sh --name "^polybar-tray_"$m"$" --direction top --region 0x0+$WIDTH+10 &
done
