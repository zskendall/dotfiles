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
sudo apt-get install i3-wm suckless-tools xfce4-terminal rofi
stow i3
```
[User guide](https://i3wm.org/docs/userguide.html)

Application launcher is rofi. Can specify width, height, and key maps in
.Xresources, and custom rasi themes `-theme <theme>` in i3 config bindsym.
```
stow rofi
```

**TODO:** information about i3lock.

## Polybar
System bar is Polybar; see
[polybar README](polybar/.config/polybar/README.md#installation-notes)
for installation information.
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

## Headphones
For desktops, will need to connect with an adapter. Have used an ASUS USB-BT400
Bluetooth 4.0 USB Adapter to connect to Bose QC35_II headphones.

### Connecting
Followed instructions in [Arch
guide](https://wiki.archlinux.org/index.php/Bluetooth_headset#Configuration_via_CLI)
to connect via bluetoothctl.
```
bluetoothctl
[bluetoothctl]# power on
[bluetoothctl]# agent on
[bluetoothctl]# default-agent
[bluetoothctl]# scan on
...
[bluetoothclt]# pair <MAC>
[bluetoothclt]# connect <MAC>
...
Connection successful
```
The Bose assistant should remark that it is connected to the host.

**as yet untested**
Adding `load-module module-switch-on-connect` to `/etc/pulse/default.pa` should
allow headphones to autoconnect. Will also require trusting the headphones via
```
bluetoothctl
[bluetoothctl]# trust <MAC>
```
And `AutoEnable=true` in `/etc/bluetooth/main.conf` should automatically power
the adapter on after reboot.

### Troubleshooting
#### bluetoothctl blocked
When trying to power on, might get the error `org.bluez.Error.Blocked`. If so,
will need to unblook with rfkill, regardless of what `rfkill list` shows:
```
$rfkill list

1: hci0: Bluetooth
  Soft blocked: no
  Hard blocked: no
```
But the bluetoothctl still reported being blocked. To unblock:
```
rfkill unblock bluetooth
```

#### No Sound
Connecting to a desktop adds an audio sink; need to switch to that sink:
```
pacmd list-sinks | grep name:
pacmd set-default-sink bluez_sink.<MAC with underscores>.a2dp_sink`
```

If `pacmd` reports the sink as not found, may need to restart pulseaudio daemon:
```
pulseaudio --start
```
and reconnect the headphones.
