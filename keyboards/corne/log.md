# Corne (crkbd) Build Log

<div><i>Built November-December 2019</i></div>
<div align="right"><i>Updated 28 February 2020</i></div>

<div align="center">
  <img alt="Finished Corne"
    src="https://lh3.googleusercontent.com/aXdieJyEfUKPg6uXpXnrrYNmNjxvkm_kIDea4mN7Jm7-vQBptZau74AXEGrAXLyW99i1NdojplaNK1lCA7hTFmwSOSvsml6MHLiR2XAkcxoAFq3p2bF7LeSc4CNrVaeE6VBRq7sKQg=w1920-h897-no">
</div>

## General (why a Corne)
After building a [Keebio
Iris](https://keeb.io/collections/frontpage/products/iris-keyboard-split-ergonomic-keyboard?variant=29480467267678)
rev2 earlier in the year, I found myself rarely using the number row and the
upper thumb keys as they were all relatively hard to reach. And then I stumbled
across the Corne in [this post](https://www.reddit.com/r/MechanicalKeyboards/comments/duyzy4/my_little_keyboard_in_my_temporary_tiny_office_at/)
in [r/mk](https://www.reddit.com/r/MechanicalKeyboards/); it's basically a baby
Iris, split with thumb clusters and without the keys that I wasn't even using
anyway!

Took a bit of digging, but finally ended up at the official [Github page of
designer foostan](https://github.com/foostan/crkbd). I ordered the [hotswappable
kit from Keyhive](https://keyhive.xyz/shop/hotswap-corne-helidox), without LEDs
or the OLED modules, and returned to Keebio for another TRRS cable.

In general, I followed the [English translation build
guide](https://github.com/foostan/crkbd/blob/master/corne-classic/doc/buildguide_en.md)
provided on Github, which was fairly complete. Having never used SMD components
before, I returned to reddit and searched Youtube for some guides/tutorials on
SMD soldering, which wasn't exactly covered in the build guide.

## Parts
The kit from Keyhive came with two PCBs and about 45 sockets. I also
ordered a couple pro micros and 60 diodes from [Keyhive](https://keyhive.xyz) as
well.

I had heard good things about the Zilents from several of my friends, so I
ordered some of those direct from [Zeal](https://zealpc.net) (after ordering a
test set from [NovelKeys](https://novelkeys.xyz)), 78g for the base keys and 67g
for the pinky keys.

Following my adventures in 3D printing during my Iris build, I decided against
purchasing plates for the Corne in favor of printing the cases. Not a huge fan
of low-pro cases, I returned to Google and [thingiverse](https://thingiverse.com)
to see whether any other enthusiasts had designed a 3D printable hi-pro case. At
the time, the only one I found was [this design by
mburrows](https://www.thingiverse.com/thing:3652379). However, since
Keyhive was sold out of the OLED covers when I bought parts, there was nothing
protecting my controllers and board from dust collection, so I modified
mburrows' original design to include an overhang over the microcontroller using
[Autodesk Tinkercad](https://tinkercad.com). I also increased the height by 3mm
to account for the taller M2 standoffs I had left over from the Iris.

### Purchased
General summary of costs, rounded up to the nearest dollar; note that costs may
vary due to shipping rates. Standoffs and screws were used from leftovers from
Iris, cost negligible.

| Item                                                                                   | Cost (est) |
| -------------------------------------------------------------------------------------- | ----------:|
| [1 × Corne keyboard kit](https://keyhive.xyz/shop/hotswap-corne-helidox)               | $15        |
| [2 × pro micros](https://keyhive.xyz/shop/pro-micro)                                   | $12        |
| [60 × SMD diodes](https://keyhive.xyz/shop/diodes)                                     | $3         |
| [Zeal sampler](https://novelkeys.xyz/30998088/orders/e20961cb7400a255cb5805ae74c93363) | $22        |
| [50 × Zilents v2](https://zealpc.net/collections/switches/products/zilents)            | $60        |
| [1 × TRRS cable](https://keeb.io/collections/frontpage/products/trrs-cable?variant=8139444519018)    | $3 |
| [50 × DSA 1u blank keycaps](https://www.aliexpress.com/item/32820475945.html?spm=a2g0s.9042311.0.0.79f04c4dHg8Uv9) | $28 |
| **Total**                                                                              | **$143**   |

### Made
All case parts were 3D printed from PLA on a [Prusa i3
Mk3](https://www.prusa3d.com/original-prusa-i3-mk3/), using 0.15 Quality
setting and 15% infill when sliced with
[PrusaSlicer](https://www.prusa3d.com/prusaslicer/). Supports were used
everywhere on the base shell for both the overhangs and the depressions so the
screws would end up flush with the base.

| Part                            | Filament (g) | Print Time |
| ------------------------------- | ------------:| ----------:|
| 1 × switch plate, modded        | 9.04         | 1h13m      |
| 2 × switch plate                | 16.4         | 2h3m       |
| 1 × base, right                 | 57.02        | 6h3m       |
| 1 × base, right (slim overhang) | 56.67        | 6h1m       |
| 1 × base, left (slim overhang)  | 56.61        | 6h         |
| **Total**                       | **195.74**   | **21h20m** |

As can be seen from the part count, there are more than 2 base shells and switch
plates! The original modifications I made to the base did not work as intended,
as the overhang was too large, so I had to adjust and reprint it. As for the
switch plate, I accidentally melted one of them while constructing (see more
below).

Unfortunately, I think because of the bottom chamfer of mburrows' case design,
the base prints soft failed 3-4 hours into the print when one or more corners
popped up from the bed. I let the prints continue since I had limited time, but
it resulted in a slight wobble in each piece and a ridge where the layers became
unaligned. After, I used a Gerber pocket knife to shave off the rough ridge.

## Build
This is more of a retrospective build log, and unfortunately, I didn't take
pictures at every single step of the build process.

### Diodes and Sockets
I found the SMD diodes hard to manage; they came in a strip, but when the
plastic was peeled, they tended to spill out and then were hard to reorient into
the proper direction to be picked up and placed.

Since the Zilents are MX and I chose not to use LEDs, it didn't matter which
side the diodes were soldered on. (And since the keyboard is hotswappable, it
still didn't really matter, as the switches *can* be taken out.) Even so, I
decided to solder to the back (bottom) side to allow for easier desoldering if
needed without wearing out the sockets.

<div align="center">
  <img alt="Soldered diodes and sockets"
    src="https://lh3.googleusercontent.com/yZdgQAYU2WS1nT2e3FLVsCNfPTa1LhpNKxEHWBOyrTfCu3bHeMXE38yIafanAhdRQ0QeBBn8ZvCnL9x0WF-eU_maNtXUCJsxO2VmtTabwJUDYdU63Spes_v9gdpOxRmtPGX3vMYOIA=w1302-h976-no" width="40%">
  <img alt="Soldered diodes and sockets"
    src="https://lh3.googleusercontent.com/aOGonym5fs2LGjcNRRy5BRtU8Ig1Luw1rMP8HAwr5UGb9Hr1ldT9EJydxjAfW6XnCppWmtJWDP6acOFRwhfM8N_Fv9p8ZE8rYSi8a5XKQrf8tKAmZWx7oonGv99GvgrK11QMoCje1w=w1302-h976-no" width="40%">
  <br>
  <span>Soldered diodes and sockets.</span>
</div>
<br>

The sockets included in the kit were Kailh, which are SMD components. I
definitely watched a couple videos on Youtube about soldering these, and
actually had to change solder gauge to fit. I ended up doing the sockets a few
at time, inserting tester switches into the socket from the top-side to hold the
socket in place.

### Pro Micros
Even though I didn't order the OLED module, I went ahead and soldered the jumper
pads as discussed in the official build guide, since I also didn't socket my pro
micros.

<div align="center">
  <img alt="Soldered pro micros"
    src="https://lh3.googleusercontent.com/fhBwdtntFOe5kQ3k-u-LXrjVVGagm828O21RABAYXoppczp0hC65K3Nyyhr_XVQUHcDQ0CAwzDZlzw4V4-vrSg4peGCkioMrXLX7qE4UHXFwFQhuFnVEC5vSAMXGWKzBQ4M4hgmrCg=w732-h976-no" width="80%">
  <br>
  <span>Installed pro micro, with soldered OLED jumpers below.</span>
</div>
<br>

I pre-flashed my pro micros beforehand, using a bit of wire from a breadboard.
Having simply copied my Iris configs over and removed the extra keys, the
QMK firmware took a couple tries to build, but the flashing worked perfectly
fine.

Despite having flashed and reflashed my Iris multiple times, I will admit I can
never remember how to manually reset and first-time build the firmware, so I
consulted [Keebio's Flashing Firmware
guide](https://docs.keeb.io/flashing-firmware/) and the [QMK Newbs
Guide](https://docs.qmk.fm/#/newbs_flashing?id=flash-your-keyboard-from-the-command-line).
I have thus far only ever flashed on Linux, which may require installing
`avrdude` if not already done:

```
sudo (apt-get install || pacman -S) avrdude
sudo make crkbd/rev1:zskendall:avrdude-loop
```

#### Issues
* avr-gcc not found: run `./util/qmk_install.sh` from qmk_firmware/
* tmk_core/protocol/lufa.mk:14: lib/lufa/LUFA/makefile not found: run `make
  git-submodules` from qmk_firmware/

### Base
Since the base of my cases had warped and developed a wobble while printing, I
added four rubber 3M furniture bumpers left over from my Iris build to the
bottom of the case in the approximate four corners. The extra couple millimeters
clearance removed the wobble and the bumpers help prevent slipping.

<div align="center">
  <img alt="Base"
    src="https://lh3.googleusercontent.com/LG5NFwO5gnS-rUnj8orMHl9Hkw17B4UIGZRot8y4ck04afMT-dkqNVdVMvCckupAsCma_HpiMjFORTxsDW64HCP0bsdRmmdcoMgwzUKLk4ihVdEO0hGO_4lYXWX2_fE2jt2eKUibAw=w1529-h976-no" width="80%">
  <br>
  <span>
    The 3D printed base shell, design modified from
  <a href="https://www.thingiverse.com/thing:3652379">mburrows' design</a>.
  </span>
  <img alt="Base"
    src="https://lh3.googleusercontent.com/Qsu86wr8-1l2iihkJVFD5rTlUS9H7sTKlOfAX2n97ipHLKUP45JauseauNaUJF-rYLN-BVSsMOU9Es0gwrRDuxhu4SmOVsWSkDBRMvtcWLKOayYWzv_7lHooZo9vOWANwhZCFhhDEQ=w1539-h976-no" width="80%">
  <br>
  <span>The bottom of the case with bumpers.</span>
</div>
<br>

I used 6mm M2 screws with flat heads bought from Amazon to hold the switch plate
to the base. The heads are about 4.1mm in diameter and 1.7mm tall, so I added
some depressions into the base for the heads so that they don't pop out. These
screw into 9mm round M2 standoffs. The screws and standoffs were left over from
my Iris build, which actually ended up using different standoffs.

### Keycaps
When I built my Iris, I got a set of labeled DSA PBT keycaps, but given that I
rarely look at the keys while typing, I opted for blanks this time. The one
downside of getting blanks is that I don't have any homing mechanism to easily
hit home, so I often find myself spanning the length of each half to home.

<div align="center">
  <img alt="Keycaps"
    src="https://lh3.googleusercontent.com/12C1L3GJUePi9kZqwPhFB66v9ms_l40X2J_K2LNI-TLeNdm6SPm8QG_12zlUMxHjE7e6q25m5K43W78PO7YyIzstTo45HQ7AWRBZLMIxBE191IuS-hp9_3_Xp01sj7Dl1oQpZRqpyQ=w1425-h976-no" width="80%">
  <br>
  <span>Blank double shot PBT keycaps, all 1u, added to the switches.</span>
</div>
<br>

I did not purchase 1.5u keycaps, since I would have needed to buy 10 or pay more
in shipping than the cost of two. After using my Corne as my daily driver for a
couple months, I recommend getting the 1.5us. It's slightly less comfortable
when quickly reaching for the inner thumb keys, and I find my thumbs frequently
rest the hi-pro case edge instead of the key.

### [Keymap](qmk)
To be honest, my English typing speed has gone down on my split mech keebs
compared to a normal staggered keyboard (I was using the [Microsoft
4000](https://www.microsoft.com/accessories/en-us/products/keyboards/natural-ergonomic-keyboard-4000/b2m-00012)
at work before building my own). I think there are two main causes for this:

1. I optimized my keymap for coding, as I do it near daily, placing brackets and
   parentheses in the thumb clusters and requiring multiple mods for symbols.
2. The two halves of the keyboard send my keypresses from slave to master to
   computer, so I am limited by the speed at which the two halves talk to each
   other, which isn't the case with most membrane or non-split mech keyboards.
   Maybe someday I will build a non-split like a Planck to compare :)

My custom keymap is also optimized for i3, the window manager I use instead of a
desktop environment on Linux, and vim, my editor of choice. There is no caps
lock because who uses caps lock, and the escape is next to the A. Mods other
than Ctrl are in the thumb clusters, with Alt and Numeric layer toggle on the
left and Meta and Navigation layer toggle on the right. All mods are actually
[QMK mod- and layer-tap combos](https://beta.docs.qmk.fm/features/feature_advanced_keycodes)
for extra functionality. The Nav layer includes convenience macro keys for
moving about i3 workspaces and Google Chrome tabs, and the Num layer supports
hex. Check out the keymap file for all details.

I track my keymap in my own dots, and symlink it into the cloned qmk_firmware
package to flash.

### Issues
#### Socketing
As mentioned briefly above, I melted one of my switch plates during building.
After doing all my soldering, I plugged it into my laptop to make sure it worked
as expected. Several keys did not work register when pressed.

1. I started by double-checking the continuity (that current could flow) of the
   switch with a multimeter, then trying with a different switch. The results
   were as expected: still didn't register the keypress.
2. Next I added a little more solder to each of the sockets that weren't
   working. This fixed most of my issues.
3. One key on each half was still having problems, so I added a little more
   solder to any pro micro pins that didn't see well covered. Did I end up with
   too much solder on some pins? Probably.
4. That fixed all but the meta key. Since I had a couple extra sockets, I tried
   desoldering the buggy socket and replacing it. This is when I melted my
   switch plate by stupidly heating the board with an air gun at 400C, well
   above the melting point of PLA, without considering I should remove the
   switch plate. The PLA cooled, shrunk, and annealed, and I couldn't do
   anything to fix it. So I printed a new one.
5. The meta key **still** didn't work. After maybe half an hour of being at a
   complete loss, I double-checked my keymap against the
   [QMK keycodes](https://docs.qmk.fm/#/keycodes_basic). Turns out I was using
   the complete wrong code for what I was trying to do. 

I commute with this keyboard, taking it back and forth between home and work
daily. One evening, I plugged it into my home computer and the N key suddenly
wasn't working at all.

Since I use two different primary OSes between work and home, I wondered whether
it was just a weird OS quirk, but the key didn't work the next day at work,
either. I took it apart and removed the switch, but nothing seemed wrong. Having
grown up playing a hand-me-down N64, I blew on the switch pins and into the
socket, which seemed to fix the problem.

Temporarily. The key started stuttering, for lack of a better word, a few days
later, sometimes not typing at all and other times  typing multiple. I
eventually took it back to the shop and swapped out the socket. It took another
couple visits to the shop to add more solder to finally fix the issue, though.

#### Pro Micros being Pro Micros (and why being in a rush is bad for the keeb)
It's a known fact that the pro micros are susceptible to socket shearing, where
the socket to plug in the USB micro cable pops off. I think the root cause was I
was in a rush to catch the bus to work and pulled the cable out too fast or at
an angle, but when I made it to the office, the master (right) half socket fell
off.

Okay, fine, that was to be expected, I knew it was a possibility when I chose
pro micros over the newer, USB-C Elite-Cs, which had a higher profile that
didn't fit as well in my opinion. But since I didn't install any reset hardware,
I had to completely disassemble the left (former slave) half to manually short
and reset the controller with a pair of tweezers. Switched to EE_HANDS while I
was at it, just in case. Guess if I break the other pro micro socket, I'll need
to desolder and probably move to Elite-C.

## Extras (because good enough is never enough)
### Travel Covers
So I mentioned I travel with my Corne. I had traveled with my Iris before, but
because of the tenting legs, it didn't easily fit a pre-made case; I was
carrying it around in a bulky cardboard box from a cheap TKL. But I wanted to
take the Corne on an upcoming cross-country trip, and the cardboard box wasn't
going to cut it.

So I did what any self-respecting engineer would do, I simply designed myself a
cover to go over each half of the keyboard to protect the switches and 3D
printed it. To do this, I took a cross section of the case model at its widest
from Tinkercad and imported it as a drawing to [Fusion
360](https://www.autodesk.com/products/fusion-360/overview) (also made by
Autodesk). Having watched several Youtube tutorials, I created a couple offsets
to extrude a 1.2mm thick wall around the case with 0.4mm tolerance. Back in
Tinkercad (since it's online and can be accessed from any machine), I added an
extra block where the overhang is and some bumps to help it snap onto the case.

| Part                        | Filament (g) | Print Time |
| --------------------------- | ------------:| ----------:|
| 1 × cover v1, right         | 49.83        | 4h54m      |
| 1 × cover v2, left          | 49.85        | 4h54m      |
| 1 × cover v2, right         | 49.68        | 4h54m      |
| **Total**                   | **149.36**   | **14h42m** |

I also printed the covers on a Prusa Mk3.

<div align="center">
  <img alt="Right cover v1"
    src="https://lh3.googleusercontent.com/iB0Uuw0UwvleS3Pd83uEy9ml1xoCzxtX9PXtohE5Hs_uHhUITEOVVbwZ9E1ECACHDr8khSfFC0PCHkzkuKIj0pzZa7auhpvEYhYXsoxuBJh-nt3DBag9dMvQnUHE9MZkGelHdrJ5bw=w1742-h976-no" width="80%">
  <br>
  <span>
    The keyboard with the right travel cover on. Note that the keyboard is not
    plugged into the computer in this image.
  </span>
</div>
<br>

Again, my first attempt did not work as planned. It used `r=1mm` bumps, which
were not large enough to fit snugly, so the cover rattled. However, I only had
the one day to print both covers before my cross-country trip, so I kept it and
reprinted once I returned from the trip.

I ended up using `r=1.5mm` for the bumps, which was slightly **too** snug and
required a bit of sanding. After a couple months, though, constantly putting the
covers on and taking them off has worn the case PLA a bit and there's
occassionally a tiny bit of rattle.

The original covers also didn't include a cut-out for the cable connection,
which I added in my reprint. However, since I didn't reprint the left cover,
the reprint only fixed one of my problems since I printed the same day I snapped
my pro micro socket. Instead, I went back to the knife and performed some
surgery on my left cover. I would not recommend trying :)

### Tenting Wedges
For expediency, I hadn't done anything for tenting, which I had had with my
Iris. Despite making modifications to the base case for tenting similar to my
Iris, which was itself inspired by the [Ergodox](https://ergodox-ez.com/products/tilt-tent-kit?variant=16101844419),
I decided I wasn't a huge fan of that after having to readjust my Iris legs all
the time. Instead, I took the same cross-section I used for the cover and made a
well to hold the keyboard.

I tented 5° across the Y axis and 3° across the X, meaning the T and Y keys will
be the highest points. I also added holes to allow screwing the keyboard with
case directly into the wedges, but did my maths wrong and ended up not having
the right kind of screw to do this. But allowing the keyboard to just sit in the
wedge well works fine too.

<div align="center">
  <img alt="Tenting wedges"
    src="https://lh3.googleusercontent.com/ba5YXWCfpNisquWpm7c4HIAe9XrbizhSTjvhxpbjDGkN8cXftqwBuxtFVrpxsgtdY1-TTG7kLJ7OZupGBr3zDSuKBQUP901M1dHO46wrqsXQFP5G4HKce8nSljvqigKeeO5Gt3aYiw=w1920-h837-no" width="80%">
  <br>
  <span>A side view of the right half in the wedge.</span>
</div>
<br>

For extra weight, I sliced using 25% infill; for expediency, 0.2mm SPEED. Using
0.2mm SPEED compared to 0.15mm QUALITY reduces the estimated print time on a
Prusa Mk3 from 6h to just under 3.5.

| Part                        | Filament (g)     | Print Time |
| --------------------------- | ----------------:| ----------:|
| 1 × wedge, right            | 61.03            | 3h20m      |
| 1 × failed wedge, left      | 34.23            | 2h10m      |
| 1 × wedge, left             | 61.13            | 3h22m      |
| **Total (running)**         | **156.39**       | **9h52m**  |

However, as expected, the faster print time came at the expense of lower
quality. Because it was at an angle, not all layers went all the way around the
piece, and the layers/ledges were clearly visible and rough to touch. I ran over
the wedges with some sandpaper to remove some of the texture, but since they're
just for the keyboard to sit on, I'm not too concerned with the reduced
quality.

#### Acrylics
Even though I didn't purchase LEDs, having a hotswappable board means I can take
the keyboard apart and add some later. In the event that I want to add some, I
swapped out the printed 1.5mm PLA switch plates for simple 3mm clear acrylic
plates.

Using the original plate design by foostan, I simply grabbed the svg outlines
for the switch plate and OLED covers and used [Visicut](https://visicut.org) to
make laser cutting jobs. The plates were then cut on an Epilog Legend EXT.

<div align="center">
  <img alt="Acrylic plate"
    src="https://lh3.googleusercontent.com/Twfoz_m1eYLWZjakByCeOFq4kfsfCbMo8E3tNXEbJWzBC8eXtgj7ZgUv66v_Y_P6khxNTjajqs6VhL56yGzwB_dgP_KX1gQ8eP4Lx7PaaET_LOcgn9kQs0WuK4ZCf-2zUGpQmaOeuQ=w1509-h976-no" width="80%">
  <br>
  <span>The switch plate raised with 9mm standoffs, to sit in the case.</span>
</div>
<br>

It took about an hour and a half at the cutter, mainly because I used some
leftover scrap material instead of purchasing a new sheet. In order to actually
cut, I had to make numerous dry runs with the laser off to correctly position
home so that the plate would fit within the remaining material. The actual
cutting of both switch plates and OLED covers was only about 10 minutes.

After cutting the plates, I totally disassembled the keyboard to just the
soldered board and moved the switches over to the acrylic plates. I really like
the look of it! Swapping in the acrylic OLED covers will require more case
surgery on the overhang or printing new cases altogether, though.

<div align="center">
  <img alt="Acrylic plate with switches"
    src="https://lh3.googleusercontent.com/X7fPyOG-OBtJk1tQz5EyWrhU6ACHBJpDobi-w9FAzGx3CvuDbe5OAMYy-QayBRMgzPAHwNTtssBp9BFiknqunChrS1tTCiAqsYFVItYqTrjt9b9NpDvv0CcCWVDbCrQiIIIjSNVv9w=w1690-h977-no" width="80%">
  <br>
  <span>The acrylic switch plate with switches inserted.</span>
</div>

### Future Plans
* Since I can completely take the keyboard apart, I may add OLED or LEDs in the
  future (though I've read the Corne LEDs can be a pain).
* My 3D printed case is good and all, but what would be **really** cool would be
  a metal (likely 6061 Al) case. I haven't machined anything since first year of
  college though, and that was basically an introductory walk-through, with all
  the CAM designs provided, but goals are always good.

## Conclusion
<div align="center">
  <img alt="Original right"
    src="https://lh3.googleusercontent.com/0dlhA42cFtR2rY40LV_xqDMZwXcsBI2gi78QjVygrBpc7bO3N5lG_fWbQEVxyBZ4qEqsSb6AUbNwxl1emph_SBSfWEPrD-sSvek0Vk3k3Os_x0-5WK8K5LhLngFhAbaGZUsVs4GYAw=w1302-h976-no" width="80%">
  <br>
  <span>The 2019 finished right half with no extras added yet.</span>
</div>
<br>

I'm very happy with my Corne. Despite the fact that I didn't buy professionally
made cases, several coworkers were surprised to learn that I had built it
myself!

<div align="center">
  <img alt="Finished Corne"
    src="https://lh3.googleusercontent.com/aXdieJyEfUKPg6uXpXnrrYNmNjxvkm_kIDea4mN7Jm7-vQBptZau74AXEGrAXLyW99i1NdojplaNK1lCA7hTFmwSOSvsml6MHLiR2XAkcxoAFq3p2bF7LeSc4CNrVaeE6VBRq7sKQg=w1920-h897-no" width="98%">
  <br>
  <span>
    The February 2020 final result! The mouse pictured is my home Logitech M570.
  <span>
</div>
<br>

I do find the case on the Corne looks a little less polished than the one I
built (design borrowed) for my Iris, but I think it does increase the
portability of the Corne compared to the Iris.

I don't know whether my Corne is endgame, though. I'm still on the fence about a
build with an integrated trackball, maybe a [dactyl
manuform](https://github.com/abstracthat/dactyl-manuform), and going wireless.
Regardless of whether I build one (or more) keyboard(s), I think that building
and using my Corne has firmly cemented my preference for split 40% and it will
remain a one of my go-to keebs.

<div align="center">
  <img alt="Finished Corne #2"
    src="https://lh3.googleusercontent.com/pw/ACtC-3e8soiFY-IsCcNG00ZnjXhf8qB5IelLuwYOezRPhWZlPU7XcmCe0Qq8dyaeKEuUn_H9_4x5wptGEOuWyvMKCH7IhQrxKN51ifH_bEHEJ2-fsb9YMz6lM3PuS15mfs9A4DNxqgn-F4wEu2TF8KdQoIIy=w1419-h829-no" width="98%">
  <br>
  <span>
    In fact, I built a second, super bare-bones Corne while at my parents' in
    June 2020.
  <span>
</div>
<br>
