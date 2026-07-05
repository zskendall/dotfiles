# X Session Configuration
## Theming
```
~/.i3/scripts/recolor borealis
```

## Button mapping experimentation
```
killall xbindkeys
xbindkeys -n -v
<C-c>
xbindkeys &
```

## [Wacom](https://www.wacom.com/en-us) tablet
I do digital art with a Wacom drawing tablet. While it's plug-and-play to a
certain extent, I like a custom setup that configures the pen, screen mapping,
and tablet buttons/wheel. 

To configure the tablet for the first time or after a reboot, run `~/.wacom`.
Nvidia graphics cards use the `HEAD-N` notation for identifying monitors; this
can be passed to `~/.wacom` to map input to the desired monitor

### Automagically configure
To support computer hopping with a single tablet (and mitigate reboot strain), I
configured udev rules in `/etc/udev/rules.d/` so that it will auto-configure
next time the tablet is plugged in.

```
ACTION=="add", SUBSYSTEM=="input", KERNEL=="mouse*", ATTRS{idVendor}=="<VID>", ATTRS{idProduct}=="<PID>", RUN+="/home/<USER>/.wacom_udev"
ACTION=="add", SUBSYSTEM=="input", KERNEL=="mouse*", ATTRS{idVendor}=="<VID>", ATTRS{idProduct}=="<PID>", RUN+="/home/<USER>/.wacom_udev"
```

The vendor and product IDs can be found by plugging the tablet in and running:
```
lsusb | grep Wacom
Bus ... ID <vendor>:<product> Wacom Co., Ltd <product name>
```

Note that the udev rules [seem to] need the user to be hardcoded (at least, I
didn't manage to get them to execute otherwise). The scripts also assume a
single user system, such as a PC; if there isn't a single user, the user will
need to be hardcoded for root to know which one to set permissions for.
