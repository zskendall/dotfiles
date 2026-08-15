#!/bin/bash

client_installs() {
  sudo xargs apt install -y < ~/dotfiles/packages/client.txt
  [ -r ~/dotfiles/compton/deb_reqs.txt ] && sudo xargs apt install -y < ~/dotfiles/compton/deb_reqs.txt

  # install whatsdesk
  sudo snap install whatsdesk
  sudo ln -s /var/lib/snapd/desktop/applications/whatsdesk* /usr/share/applications

  # install discord
  source ~/dotfiles/bin/install_discord.sh
}

setup_server() {
  sudo tailscale up --authkey=file:/tmp/ts-authkey --advertise-tags=tag:nas && shred -u /tmp/ts-authkey

  sudo xargs apt install -y < ~/dotfiles/packages/server.txt
  pipx install grip

  # start services
  (cd ~/dotfiles && stow xsession quadlets)
  find -L ~/.config/containers/systemd -name '.env.example' | while read -r example; do
    local service=$(basename "$(dirname "$example")")
    mkdir -p ~/"$service"
    cp "$example" ~/"$service"/.env
  done
  read -p "Populate .env files and set up bind mount links, then press Enter..."
  local pods=$(find -L ~/.config/containers/systemd \
    -name '*.pod' -printf '%f\n' | sed 's/\.pod//')
  local standalone=$(find -L ~/.config/containers/systemd -name '*.container' \
    -exec grep -L '^Pod=' {} + | xargs -I{} basename {} .container)
  for unit in $pods $standalone; do
    systemctl --user start "$unit"
  done
}

setup_graphical() {
  client_installs

  rm -r ~/.i3 ~/.config/dunst ~/.Xresources ~/.vimrc
  (cd ~/dotfiles && stow i3 polybar xsession picom rofi dunst)

  sudo tailscale up

  # create default ssh key
  ssh-keygen -t ed25519 -C ${HOSTNAME:-$(hostname)}
}

setup_pihole() {
  sudo tailscale up --authkey=file:/tmp/ts-authkey --advertise-tags=tag:service && shred -u /tmp/ts-authkey
  curl -sSL https://install.pi-hole.net | bash
}

setup_devenv() {
  # swap dotfiles to use ssh
  ssh-keygen -t ed25519 -f ~/.ssh/id_ed25519_github
  (cd ~/dotfiles && git remote set-url origin git@github.com:zskendall/dotfiles.git)
}

sudo xargs apt install -y < ~/dotfiles/packages/common.txt
dpkg-reconfigure -plow unattended-upgrades
curl -fsSL https://tailscale.com/install.sh | sh

echo "UMASK 027" | sudo tee -a /etc/login.defs
(cd ~/dotfiles && stow vim tmux)
setup_${1:-graphical}
setup_devenv
