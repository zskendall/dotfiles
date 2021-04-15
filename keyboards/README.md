# keyboard configs
Code, keymaps, and configs for my custom keyboards.

## Keymaps
Migrating to community layouts where possible. All keyboards can share code and
config located in [common/](./common).

* **Canonical**
  * [Split 3x6+3](./split_3x6_3): Columnar split ergo layout with 3 thumb keys,
    preferred for working, typing, and coding. Currently used on
    [Crkbd](https://github.com/foostan/crkbd).
* **Deprecated**
  * [Iris](./iris): Columnar split ergo layout with 4 thumb keys.
    No longer used in favor of 3x6+3.

## How to use
1. Clone [QMK](https://github.com/qmk/qmk_firmware) or pull the latest updates.
2. Link the common directory into QMK users directory (substitute your username)
   ```
   ln -sf ~/dotfiles/keyboards/common/ ~/qmk_firmware/users/{{USERNAME}}
   ```
3. Link the desired subdirectory into QMK layouts (or keyboard/\*\*/keymaps)
   ```
   ln -sf ~/dotfiles/keyboards/split_3x6_3/ ~/qmk_firmware/layouts/community/split_3x6_3/{{USERNAME}}
   ```
4. Build the firmware!
   ```
   cd ~/qmk_firmware && make {{KEYBOARD}}:{{USERNAME}}[:{{target}}]
   ```
