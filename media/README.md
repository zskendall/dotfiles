# Media
For computers with music stored locally, daemon is
[mpd](https://wiki.archlinux.org/index.php/Music_Player_Daemon) using
[ncmpcpp](https://wiki.archlinux.org/index.php/ncmpcpp) as the client.
[cava](https://github.com/karlstav/cava) can be used as a visualizer.
```
sudo pacman -S mpd ncmpcpp
pamac build cava
cd ~/dotfiles && stow media && cd ~

sed "s~%music_dir%~<music_dir_here>~" ~/.config/mpd/template > ~/.config/mpd/mpd.conf
sed "s~%music_dir%~<music_dir_here>~" ~/.ncmpcpp/template > ~/.ncmpcpp/config
```
The colors of ncmpcpp are themed to go with the system. Not all themes are
supported yet.

## Headphones (Debian)
Generally use Bose QC35_II headphones, which are bluetooth. For desktops, will
need to connect with an adapter. Have used an ASUS USB-BT400 Bluetooth 4.0 USB
Adapter.

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

1. Check the jacks. On older sound cards, green looks a lot like grey. 🤦🏻‍♀️
2. Read [this forum post](https://forum.manjaro.org/t/no-sound-in-chrome-or-ff/3824/14),
   specifically the post by manjrob in June '16 to use `aplay -l` and `aplay -D
   plughw:X,Y /usr/share/sounds/alsa/Front_Right.wav` to determine which card is
   being used.
3. Use `pacmd` to list sinks and find the one that matches the card name found
   from #2
4. `pacmd set-default-sink` as the sink name found from #3

Sometimes polybar will not show the volume; this is usually because it can't
figure out which sound card to use. `aplay -l` to figure out the card number and
use `master-soundcard = hw:X` in volume module.
