# Corne Layout
Modified version of my previous [Iris layout](../iris), specialized for i3 and
coding in vim. All keycaps are blank, but labeled below for reference; mod-tap
keys show the modifier on the bottom and the tap on top.

## Layers
All the layout images were made with
[KLE](http://www.keyboard-layout-editor.com/).

### Alpha
The base layer is generic QWERTY. Don't mind the layer definition for Colemak,
I was briefly dabbling and there is no longer a way to swap into this layer but
it hasn't been deleted.

![Base
layout](https://lh3.googleusercontent.com/3wPjZl4bZpClQuuDOWsa85Y4pA97MOf9VsDeDE-vWlDvkUs_bGZpub1GUGZxfdIHP-bwuiB8YdBzNUYPx_HiJjlEpDg3TS7hraMXD-f5Zf1JzIK3lc2RRvj3gad9XRFjBzaRMLQppg=w830-h282-no)

### Numeric
Holding the innermost left thumb key activates the hex-compatible numeric layer
while the key is pressed. Grey keys have no function, otherwise, keys with no
label fall through.

![Numeric
layout](https://lh3.googleusercontent.com/Wcqo_oh72g7l2c3UKetVSdE_qhrtSULwlIGaOEKOEaId2u2M0qFLFYyzEmXcqPphxNzZptox5HUK2GP5lr50gJHEkpbUV9nVErtcgj5nsRPu2Cks8RpuYNkBaSVMXjJx-6L9IZ7_0A=w830-h282-no)

### Navigation
Holding the innermost right thumb key activates the combined navigation and
adjust layer while the key is pressed.

![Navigation
layout](https://lh3.googleusercontent.com/y3siTYRNB5Jzw1JuLuxmloHdpn5b0KnZ-6q88qVBi9EFX2CvxVzCiUvoJNrKMvWE0zlvXKR_xoms7CG98q-XBb3-XyncvAxckHWboCQx8ZdXL1eqIh_60039xPZDkup91YahBRVWMQ=w830-h282-no)

### Mouse and Media
This layer allows for moving the mouse with the keyboard, though only small
movements are recommended, and also includes some GUI features.

![Mouse
layout](https://lh3.googleusercontent.com/k4-5c8pwwa_baEcdl_WUfaEwuXiAFjlRMvuQulLoj6k2ZPGAyak87zBK3VQrGfbawTaXuMku6w8ej4W8wuZgLUq6omVBdJqwim83vEBST4BkMq6sr3-2-Nxz8HMLeqv9ywtWvIfnuA=w830-h282-no)

## Flashing
Currently uses pro micros, with EE_HANDS to protect agaginst shearing the socket
on one side (which has happened). I track my keymap here in my own dots and
simply symlink it into the cloned qmk_firmware to flash:

```
git clone https://github.com/qmk/qmk_firmware.git
mkdir -p ~/qmk_firmware/keyboards/crkbd/keymaps/zskendall
ln -sf ~/dotfiles/keyboards/corne/qmk/config.h ~/qmk_firmware/keyboards/crkbd/keymaps/zskendall/config.h
ln -sf ~/dotfiles/keyboards/corne/qmk/rules.mk ~/qmk_firmware/keyboards/crkbd/keymaps/zskendall/rules.mk
ln -sf ~/dotfiles/keyboards/corne/qmk/keymap.c ~/qmk_firmware/keyboards/crkbd/keymaps/zskendall/keymap.c
cd qmk_firmware
make crkbd/rev1:zskendall:avrdude
```

There are two ways to reset the keyboard:
1. Using the hotkey in the mouse layer
2. Disassembling case (modified from [mburrows' thingiverse
   design](https://www.thingiverse.com/thing:3652379)) and manually shorting
