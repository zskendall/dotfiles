#!/bin/bash

# Remap right Alt key to Mod3 for i3.
xmodmap ~/.xmodmap

# If at work, set up the displays.
if [ -r ~/.xsessionrc_work ]; then
  . ~/.xsessionrc_work;
fi

# Set background image. If change background, then change Polybar, i3, and Tmux.
if [ -r ~/dotfiles/images/background.jpg ]; then
  feh --bg-scale ~/dotfiles/images/background.jpg
fi

# If installed, start compton as a background process to enable compositing. See
# https://wiki.archlinux.org/index.php/compton for more information.
if [[ $(dpkg -s compton | grep "installed") ]]; then
  compton -b
fi

# If at home, configure wacom buttons
if [ ! -r ~/.xsessionrc_work ] && [ -r ~/.wacom ]; then
  . ~/.wacom
fi


