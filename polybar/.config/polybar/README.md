# Polybar Config for Custom Statusbar

![ ](screenshot_dual.png)
*My Polybar on dual monitors*
Photo by FORREST CAVALE on Unsplash

## Installation Notes
For Debian or Ubuntu, will need to follow instructions to build from [source](https://github.com/jaagr/polybar).

Deps [[1]](https://medium.com/@tatianaensslin/install-polybar-in-3-steps-on-debian-stretch-c64ab6157fb1):

```shell
sudo apt-get install cmake cmake-data libcairo2-dev libxcb1-dev \
libxcb-ewmh-dev libxcb-icccm4-dev libxcb-image0-dev libxcb-randr0-dev \
libxcb-util0-dev libxcb-xkb-dev pkg-config python-xcbgen xcb-proto \
libxcb-xrm-dev i3-wm libasound2-dev libmpdclient-dev libiw-dev \
libcurl4-openssl-dev libpulse-dev
```

Other deps:
* libpulse0
* libcurl
* wireless_tools

Another command for deps [[2]](https://github.com/jaagr/polybar/issues/650)

```shell
sudo apt-get install python-xcbgen linxcb-ewmh-dev libxcb-icccm4-dev libxcb1-dev \
xcb-proto libxcb-util-dev libxcb-image0-dev libxcb-randr0-dev ibxcb-xkb-dev \
libalsaplayer-dev wireless-tools libcurlpp-dev  libcairo2-dev
```

Yet another command for deps [[3]](https://github.com/jaagr/polybar/issues/367)

```shell
sudo apt-get install cmake unifont libcairo2-dev libxcb-xkb-dev \
libxcb-util-dev libxcb1-dev libx11-xcb-dev libxcb-icccm4-dev libxcb-image0-dev  \
libxcb-ewmh-dev python-xcbgen
```

Super useful wiki that shows deps for various distros [[4]](https://github.com/jaagr/polybar/wiki/Compiling)

[Error 2 when attempting to build cxx object bar.cpp.o](https://github.com/jaagr/polybar/issues/644) that happened when ```sudo make install``` run on laptop.
**TLDR** xcb-proto and libxcb-randr0-dev need to be the same version.
