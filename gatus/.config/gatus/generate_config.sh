#!/bin/bash
for instance in main backup; do
  cp ~/.config/gatus/templates/pihole-primary.yaml "$HOME/.config/gatus/$instance/ping-pihole.yaml"
  i=1
  for replica in $PIHOLE_REPLICAS; do
    sed -e "s/%hostname%/$replica/g" -e "s/%idx%/$i/g" ~/.config/gatus/templates/pihole-replica.yaml >> "$HOME/.config/gatus/$instance/ping-pihole.yaml"
    i=$((i + 1))
  done
done
