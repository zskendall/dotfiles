# [Unicorne](https://github.com/yanghu/unicorne)
* Keymap: basically [split 3x6+3](../split_3x6_3), plus a bunch of extra layouts
* OLED and gclfont modified from the
  [defaults](https://github.com/yanghu/qmk_firmware/tree/unicorne/keyboards/yanghu/unicorne).
* Lots of inspiration from various [QMK
  userspaces](https://github.com/qmk/qmk_firmware/tree/master/users).

## How to build
mainline qmk didn't work, got keyboard in unusable state, so use yanghu's fork
of qmk. definitely worked at [commit 52da82f](https://github.com/yanghu/qmk_firmware/tree/52da82f592c910086f709d6aa0270ab9684abbd2)

```
git clone https//:github.com/yanghu/qmk_firmware.git unicorne_qmk
cd unicorne_qmk
git fetch -a
git switch unicorne
git checkout 52da82f592c910086f709d6aa0270ab9684abbd2
```

some of the common files updated to work in mainline will no longer work, need
to roll them back:

```
mkdir -p ~/unicorne_qmk/users/zskendall
cd ~/dotfiles
git pull
git checkout d1d3db5733290b825d1dd78ea2211eaf9c4b177f
cp ~/dotfiles/keyboards/common/tap_dances.h ~/unicorne_qmk/users/zskendall/tap_dances.h
cp ~/dotfiles/keyboards/common/tap_dances.c ~/unicorne_qmk/users/zskendall/tap_dances.c
git checkout master
cp ~/dotfiles/keyboards/common/wrappers.h ~/unicorne_qmk/users/zskendall/wrappers.h
git checkout unicorne
ln -sf ~/dotfiles/keyboards/unicorne/ ~/unicorne_qmk/keyboards/yanghu/unicorne/keymaps/zskendall
ln -sf ~/dotfiles/keyboards/common/config.h ~/unicorne_qmk/users/zskendall/config.h
ln -sf ~/dotfiles/keyboards/common/rgb.h ~/unicorne_qmk/users/zskendall/rgb.h
ln -sf ~/dotfiles/keyboards/common/rgb.c ~/unicorne_qmk/users/zskendall/rgb.c
ln -sf ~/dotfiles/keyboards/common/rules.mk ~/unicorne_qmk/users/zskendall/rules.mk
ln -sf ~/dotfiles/keyboards/common/zskendall.h ~/unicorne_qmk/users/zskendall/zskendall.h
ln -sf ~/dotfiles/keyboards/common/zskendall.c ~/unicorne_qmk/users/zskendall/zskendall.c
```
