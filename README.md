# linux setup
Config files versioned with git and managed by GNU stow.
```
sudo apt-get install git stow
```

## X Session
Configuration for display and input devices.
```
sudo apt-get install feh compton xbindkeys xautomation xdotool xsetwacom
stow xsession
```

To experiment with button mappings:
```
killall xbindkeys
xbindkeys -n -v
<C-c>
xbindkeys &
```

## i3 window manager
```
sudo apt-get install i3-wm suckless-tools xfce4-terminal
stow i3
```
[User guide](https://i3wm.org/docs/userguide.html)

**TODO:** information about i3lock.

## Polybar
System bar is Polybar; see [polybar README](polybar/.config/polybar/README.md)
for more information.
```
stow polybar fonts
```

## Tmux
```
sudo apt-get install tmux
stow tmux
```

## Other
Themes: `stow local`

Convenience navigation mappings:
```
stow input
bind -f ~/.inputrc
```
