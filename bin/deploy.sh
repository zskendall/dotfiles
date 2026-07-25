#!/bin/bash
set -e
export XDG_RUNTIME_DIR=/run/user/$(id -u)
cd ~/dotfiles
git pull --ff-only
systemctl --user daemon-reload
systemctl --user restart "$1"
