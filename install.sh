INSTALL="sudo "
if [ $(command -v pacman) ]; then
  # install from AUR
  pamac build google-chrome
  pamac build gotop
  pamac build cava

  # install specific versions of packages; may need to update /etc/pacman.conf
  # to add these to IgnorePkg
  sudo pacman -U https://archive.archlinux.org/packages/p/picom/picom-7.5.1-x86_64.pkg.tar.xz
  sudo pacman -U https://archive.archlinux.org/packages/g/gutenprint/gutenprint-5.3.3-2-x86_64.pkg.tar.xz

  # install pip
  pip install grip

  INSTALL+="pacman -S xf86-input-wacom polybar mpd ncmpcpp krita "
  INSTALL+="libreoffice-still gucharmap gsimplecal "
  if [[ ! $(pacman -Q i3-gaps) ]]; then
    INSTALL+="i3-gaps "
  fi
elif [ $(command -v apt-get) ]; then
  INSTALL+="apt-get install git xsetwacom i3wm suckless-tools compton "
fi

INSTALL+="feh stow xautomation xdotool xbindkeys rofi xfce4-terminal tmux jq"
exec $INSTALL

# configure!
rm -r ~/.i3 ~/.config/dunst ~/.Xresources ~/.vimrc
cd dotfiles
stow vim i3 polybar xsession compton rofi tmux dunst media
cd ..
[ $(pacman -Q i3-gaps) ] && cat ~/.i3/gaps >> ~/.i3/config
~/.xsessionrc
bind -f ~/.inputrc

# start services
systemctl start atd.service
systemctl --user start mpd.service
