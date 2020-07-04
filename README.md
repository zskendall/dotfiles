# linux setup
Config files versioned with git and managed by GNU stow. I use Debian on some
machines, Manjaro (Arch-based) on others; install commands for both are listed
just for completeness.
```
sudo apt-get install git stow
```
or
```
sudo pacman -S git stow
```

## X Session
Configuration for display and input devices.
```
sudo apt-get install feh compton xbindkeys xautomation xdotool xsetwacom
stow xsession compton
```
or
```
sudo pacman -S feh xbindkeys xautomation xdotool xf86-input-wacom
```

I use [tryone's fork of compton](https://github.com/tryone144/compton) to add
kawase blur. On Debian/Ubuntu, cloned the repo with git clone and followed the
build instructions in the repo README. On Arch-based (Manjaro), there's a picom
fork in the AUR:

```
pamac search -a picom
pamac build picom-tryone-git
```

To experiment with button mappings:
```
killall xbindkeys
xbindkeys -n -v
<C-c>
xbindkeys &
```

System monitoring with [gotop](https://github.com/cjbassi/gotop). Cloned the
repo into the home directory and ran cjbassi's `download.sh` script. Run the
monitor with `~/gotop -p -a`. To avoid compton auto-dimming the monitoring when
inactive, named terminal tab 'sysmon' and excluded it in compton config.

## i3 window manager
```
sudo apt-get install i3-wm suckless-tools xfce4-terminal rofi
stow i3
```
or
```
sudo pacman -S i3-gaps xfce4-terminal rofi
```
[User guide](https://i3wm.org/docs/userguide.html)

If running `i3-gaps` on Debian/Ubuntu, followed instructions to build and
install from [source](https://www.github.com/Airblader/i3) found
[here](benjames.io/2017/09/03/installing-i3-gaps-on-ubuntu-16-04/).

Application launcher is rofi. Can specify width, height, and key maps in
.Xresources, and custom rasi themes `-theme <theme>` in i3 config bindsym.
```
stow rofi
xrdb ~/.Xresources
```

Lock screen is [a branch of i3lock](https://github.com/Lixxia/i3lock) that
provides a clock and other customization. To use 24h time, the boolean use24hour
in `i3lock.c` must be set to true before making and installing.

I use a bash wrapper around i3lock. This allows specifying the same set of args
in the i3 bindsym but only using ones that are applicable for a given host. For
example, the i3 bindsym might include an image path; the locker script will only
pass that along to i3lock if the file exists.

## Polybar
System bar is Polybar; see
[polybar README](polybar/.config/polybar/README.md#installation-notes)
for installation information.
```
stow polybar fonts
```

If on an Arch-based distro:
```
sudo pacman -S polybar
```

## Tmux
```
sudo apt-get install tmux
stow tmux
```
or
```
sudo pacman -S tmux
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

## Speakers (Manjaro)
In Majaro, sometimes the sound from Chrome was cutting out. These things worked
to fix it once, so try them first!

1. Check the jacks. On older sound cards, green looks a lot like grey.
2. Read this forum post: https://forum.manjaro.org/t/no-sound-in-chrome-or-ff/3824/14,
   specifically the post by manjrob in June '16 to use `aplay -l` and `aplay -D
   plughw:X,Y /usr/share/sounds/alsa/Front_Right.wav` to determine which card is
   being used.
3. Use `pacmd` to list sinks and find the one that matches the card name found
   from #2
4. `pacmd set-default-sink` as the sink name found from #3
