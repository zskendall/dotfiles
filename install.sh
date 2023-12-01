#!/bin/sh
INSTALL="sudo apt-get install git i3wm suckless-tools "
for r in $(cat ~/dotfiles/compton/deb_reqs.txt); do
  INSTALL+="$r"
done

INSTALL+="feh stow xautomation xdotool xbindkeys rofi xfce4-terminal tmux jq "
INSTALL+="curl krita polybar mpd ncmpcpp gsimplecal gucharmap psmisc snapd "
exec $INSTALL

# install tryone144/compton from source
git clone https://github.com/tryone144/compton.git
cd compton
make
make docs
make install
cd ..

# install google chrome stable
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo dpkg -i google-chrome-stable_current_amd64.deb
sudo apt-get install -f

# install whatsdesk
sudo snap install whatsdesk
sudo ln -s /var/lib/snapd/desktop/applications/whatsdesk* /usr/share/applications

# configure!
rm -r ~/.i3 ~/.config/dunst ~/.Xresources ~/.vimrc
cd dotfiles
stow vim i3 polybar xsession compton rofi tmux dunst media
cd ..
~/.xsessionrc
bind -f ~/.inputrc

# start services
systemctl start atd.service
systemctl --user start mpd.service
