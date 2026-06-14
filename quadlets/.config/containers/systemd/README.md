# Quadlets for running Podman services

## Installation Notes
```
sudo apt install podman
podman -v  # verify v5+
cd ~/dotfiles && stow quadlets
```

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
systemctl --user start affine-pod
```

## data mounts
all directory bindmounts use a static path for the data. to store application
data in another location, simple create a symlink:
```
ln -s /path/to/keep/data/ ~/affine/data
```
