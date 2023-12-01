# i3 window manager
[User guide](https://i3wm.org/docs/userguide.html)

```
sudo apt-get install i3-wm suckless-tools
stow i3
cat ~/.i3/gaps >> ~/.i3/config
```

[i3-gaps](https://github.com/Airblader/i3) is now included in i3 by default, but
can still be built from source according to [this
guide](benjames.io/2017/09/03/installing-i3-gaps-on-ubuntu-16-04/).

## Lock screen (as needed)
The lock screen is [a branch of i3lock](https://github.com/Lixxia/i3lock) that
provides a clock and other customization. To use 24h time, the boolean use24hour
in `i3lock.c` must be set to true before making and installing.

I use a [bash wrapper](scripts/locker) around i3lock to allow specifying the
same set of args in the i3 bindsym but only using ones that are applicable for a
given host. For example, the i3 bindsym might include an image path; the locker
script will only pass that along to i3lock if the file exists.
