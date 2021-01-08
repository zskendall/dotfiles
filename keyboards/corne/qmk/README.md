# Corne Layout
Modified version of my previous [Iris layout](../iris), specialized for i3 and
coding in vim. All keycaps are blank, but labeled below for reference; mod-tap
keys show the modifier on the bottom and the tap on top.

## Layers
All the layout images were made with
[KLE](http://www.keyboard-layout-editor.com/). Grey keys have no function,
otherwise, keys with no label fall through.

### Alpha
The base layer is generic QWERTY. Don't mind the layer definition for Colemak,
I was briefly dabbling and there is no longer a way to swap into this layer but
it hasn't been deleted.

[![Base layout](https://lh3.googleusercontent.com/pw/ACtC-3dLXS_2Eux6AET-Kd3fSRPqApWzFEWnx2sbOavHVsgDR01DS80R4dNZ3REDGNKrBdkmlwcUOblQiOpAv3Iq6dcvrtX2balNje7EeshQwQFKSM8ZkavpNDOBD_68ilsMgoIWduEDRLzgtM0OEaN4oWME=w830-h282-no?authuser=0)](http://www.keyboard-layout-editor.com/#/gists/d9eabc2c9c8a767cf8e48dfd4ce3662b)

### Numeric
Holding the innermost left thumb key activates the hex-compatible numeric layer
while the key is pressed.

[![Numeric layout](https://lh3.googleusercontent.com/Wcqo_oh72g7l2c3UKetVSdE_qhrtSULwlIGaOEKOEaId2u2M0qFLFYyzEmXcqPphxNzZptox5HUK2GP5lr50gJHEkpbUV9nVErtcgj5nsRPu2Cks8RpuYNkBaSVMXjJx-6L9IZ7_0A=w830-h282-no)](http://www.keyboard-layout-editor.com/#/gists/bc9bdcb085371ebac15fa6449208bab3)

### Navigation
Holding the innermost right thumb key activates the combined navigation and
adjust layer while the key is pressed.

[![Navigation
layout](https://lh3.googleusercontent.com/pw/ACtC-3dOzrN3k7GyGOtluc_g1_sSRT5I8nDQ22kssxI8GKYJNEjdFXITDCFHYShPQLYiYHQdsXYYxVg79ER91O8LKikSfI1W22cVBcOuX27Ee6kjDCxh2PmNI0DbtMNUCCuCif2K3pTBlNdaRIlZ6gezHoSH=w830-h282-no?authuser=0)](http://www.keyboard-layout-editor.com/#/gists/477ba2ba740a8949c84c1dcafca9aa75)

### Mouse and Media
This layer allows for moving the mouse with the keyboard, though only small
movements are recommended, and also includes some GUI features.

[![Mouse
layout](https://lh3.googleusercontent.com/pw/ACtC-3cE3NTJ7tn5gh0urtioHgWgZ6TD4snP56TozDNjzmCA9KlTBXrwF5h3RJX_Zhg53v1rw3qH2MGYDUY-80SKwKM-umQ1lRDe8LWG6bVriP2KJc3Xwyl4wX7tYwrdM3oziG4Vanks9Xr1iKusqQrvKy_E=w830-h282-no?authuser=0)](http://www.keyboard-layout-editor.com/#/gists/e5eaf4bfe8d2d3a86cf00d8460120ad4)

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
make crkbd:zskendall:avrdude-split-right
make crkbd:zskendall:avrdude-split-left
```

There are two ways to reset the keyboard:
1. Using the hotkey in the mouse layer
2. Disassembling case (modified from [mburrows' thingiverse
   design](https://www.thingiverse.com/thing:3652379)) and manually shorting
