# Split 3x6+3 Layout
This is my favorite (and really only) layout for typing and coding, specialized
for i3 WM and vim. Originally modified from my previous [Iris layout](../iris),
but is now the primarily maintained layout. All keycaps are blank, but labeled
below for reference; mod-tap keys show the modifier on the bottom and the tap on
top.

## Layers
All the layout images were made with
[KLE](http://www.keyboard-layout-editor.com/). Grey keys have no function,
otherwise, keys with no label fall through.

Don't mind the layer definition for Colemak, I was briefly dabbling and there is
no longer a way to swap into this layer but it hasn't been deleted (just in case
I get the urge to dabble again lol).

### Alpha
[![Base layout](https://lh3.googleusercontent.com/pw/ACtC-3dLXS_2Eux6AET-Kd3fSRPqApWzFEWnx2sbOavHVsgDR01DS80R4dNZ3REDGNKrBdkmlwcUOblQiOpAv3Iq6dcvrtX2balNje7EeshQwQFKSM8ZkavpNDOBD_68ilsMgoIWduEDRLzgtM0OEaN4oWME=w830-h282-no?authuser=0)](http://www.keyboard-layout-editor.com/#/gists/d9eabc2c9c8a767cf8e48dfd4ce3662b)

The base layer is generic QWERTY.
* Esc placed conveniently for Vim.
* Shift in the thumb clusters because I don't believe in caps lock :P
* Space and Return are at the most natural resting position in thumb clusters.
* Alt on left (Space hold) and Meta on right (Ret hold) for i3 convenience.
* Ctrl on the homerow for somewhat easy macros like Ctrl+C, Ctrl+T. Non-ideal
  since that's the pinky, but generally out of the way.


### Numeric
Holding the innermost left thumb key activates the hex-compatible numeric layer
while the key is pressed.

[![Numeric layout](https://lh3.googleusercontent.com/Wcqo_oh72g7l2c3UKetVSdE_qhrtSULwlIGaOEKOEaId2u2M0qFLFYyzEmXcqPphxNzZptox5HUK2GP5lr50gJHEkpbUV9nVErtcgj5nsRPu2Cks8RpuYNkBaSVMXjJx-6L9IZ7_0A=w830-h282-no)](http://www.keyboard-layout-editor.com/#/gists/bc9bdcb085371ebac15fa6449208bab3)

* Numbers are placed in a numpad on the right half because I find that faster.
  They can be shifted to get symbols.
* Mathematical symbols (e.g., +, -) also conform closely to traditional numpads.
* Hex codes supported with valid letters on left half still available.

### Navigation
Holding the innermost right thumb key activates the combined navigation and
adjust layer while the key is pressed.

[![Navigation
layout](https://lh3.googleusercontent.com/pw/ACtC-3dOzrN3k7GyGOtluc_g1_sSRT5I8nDQ22kssxI8GKYJNEjdFXITDCFHYShPQLYiYHQdsXYYxVg79ER91O8LKikSfI1W22cVBcOuX27Ee6kjDCxh2PmNI0DbtMNUCCuCif2K3pTBlNdaRIlZ6gezHoSH=w830-h282-no?authuser=0)](http://www.keyboard-layout-editor.com/#/gists/477ba2ba740a8949c84c1dcafca9aa75)

* Arrow keys are on Vim-style HJKL keys.
* Home/End and Page Up/Down are on ASDF keys. Home is farthest left, End
  farthest right because it just felt right.
* Convenience macros to change i3 workspaces and Chrome tabs are on top and
  bottom row, respectively.
* Toggles for Ops and Art layers are also here. The former can be done with only
  the right hand, latter requires both hands since it effectively turns off half
  the keyboard (see below).

### Mouse and Media (aka Ops)
This layer allows for moving the mouse with the keyboard, though only small
movements are recommended, and also includes some GUI features.

[![Mouse
layout](https://lh3.googleusercontent.com/pw/ACtC-3cE3NTJ7tn5gh0urtioHgWgZ6TD4snP56TozDNjzmCA9KlTBXrwF5h3RJX_Zhg53v1rw3qH2MGYDUY-80SKwKM-umQ1lRDe8LWG6bVriP2KJc3Xwyl4wX7tYwrdM3oziG4Vanks9Xr1iKusqQrvKy_E=w830-h282-no?authuser=0)](http://www.keyboard-layout-editor.com/#/gists/e5eaf4bfe8d2d3a86cf00d8460120ad4)

* Mouse movement using gaming WASD keys, scroll using Vim HJKL keys.
* Mouse buttons on the big thumb keys.
* Media keys: music nav on left, volume on right.
* Also includes functions like RESET, F\* keys for virtual terminals, and print
  screen for screenshotting.

### Art
This layer moves all functionality to the left half of the keyboard so that
everything can be done while holding a pen.

* [Tap dance](../tap_dance.h) to support left and right keys.
* Set up like a sandwich, as if right half was simply slapped onto left, so keys
  use the same finger (i.e., J is tap-danced with F, etc).
* Only large thumb button is still a mod-tap: on hold, Ctrl; tap, insert.
* Shift no longer taps anything.
* To exit, 5+ dance on the lower left.
