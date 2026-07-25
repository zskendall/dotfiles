# Quadlets for running Podman services

## networking
by default, podman v5+ uses pasta networking, but for homepage to be able to
correctly find and talk to other containers that may be running on different,
pod-specific networks, had to revert back to `slirp4netns` which does a
traversal

see `../containers.conf` for reverting back to `slirp4netns`

## env files
quadlet config only; need to specify any operational details in .env files at
e.g. `~/service/.env`

```
cp ~/dotfiles/quadlets/.config/containers/systemd/affine/.env.example ~/affine/.env
vim ~/affine/.env
systemctl --user daemon-reload
systemctl --user restart affine-pod
```

## data mounts
all directory bindmounts use a static path for the data. to store application
data in another location, simple create a symlink:
```
ln -s /path/to/keep/data/ ~/affine/data
```

## image updates
most container images are updated automatically via `AutoUpdate=registry` using
`podman-auto-update` user systemd timer. add notifications:
```
systemctl --user edit podman-auto-update.service
```
to add `ExecStartPost=/path/to/dotfiles/bin/notify.sh auto-update`

## running as a separate user
```
sudo useradd -m -s /bin/bash -u 1234 foouser
sudo loginctl enable-linger foouser
sudo machinectl shell foouser@.host
git clone https://github.com/zskendall/dotfiles.git
mkdir -p ~/.config/containers/systemd
ln -s ~/dotfiles/quadlets/.config/containers/containers.conf ~/.config/containers/containers.conf
ln -s ~/dotfiles/quadlets/.config/containers/systemd/gatus.container ~/.config/containers/systemd/gatus.container
(cd dotfiles && stow gatus)
mkdir -p ~/gatus/data
cp ~/.config/gatus/.env.example ~/gatus/.env
systemctl --user daemon-reload
systemctl --user start gatus
crontab -e
```
repo and services are updated weekly at 3am thu via user crontab
