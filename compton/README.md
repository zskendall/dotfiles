# Compositor (deprecated directory name)
Configure and start compositor:
```
stow compton
picom -b --experimental-backends --config ~/.compton.conf
```

## Debian
Cloned [tryone144's compton](https://github.com/tryone144/compton) to add
kawase blur and followed the build instructions in the repo README.

## Manjaro
```
pamac search -a picom
pamac build picom-tryone-git
```

**[July 2020 Update]**: more recent versions of picom were having trouble with
opacity of polybar not obeying rules, so used the normal version and downgraded
to 7.5 (no kawase support but it still does a good job):

```
sudo pacman -S picom
DOWNGRADE_FROM_ALA=1 && downgrade picom
```
or as done in the install script
```
sudo pacman -U https://archive.archlinux.org/packages/p/picom/picom-7.5.1-x86_64.pkg.tar.xz
```
