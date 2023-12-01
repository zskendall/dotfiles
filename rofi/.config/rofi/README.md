# Rofi launchers
Key maps are in .Xresources while themes are in separate `.rasi` files that can
be specified with `-theme <theme>` in i3 config bindsym.

Uses [Rofi 1.6.1-34-g53533acb](https://github.com/davatorium/rofi/tree/1.6.1).

## Launcher
![launcher](../../../assets/launcher.png)

## System menu
![system menu](../../../assets/system_menu.png)

## Installation
Rofi 1.7.3 was available in apt as of November 2023:
```
sudo apt install rofi
```

Otherwise, [build](https://github.com/davatorium/rofi/blob/next/INSTALL.md)
from source:
```
git clone https://github.com/davatorium/rofi.git
cd rofi
git submodule update --init
autoreconf -i
mkdir build && cd build
../configure
make
sudo make install
rofi -V
```
