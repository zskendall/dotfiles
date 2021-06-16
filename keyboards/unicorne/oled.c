/* Copyright 2021 Yang Hu, modified by Zoe Kendall
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "zskendall.h"

// The oled is vertical. Need to rotate 270 degrees.
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

char keylog_str[24] = {};

// clang-format off
const char code_to_name[60] = {
  ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
  'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',
  '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[',
  ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};
// clang-format on

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
}

void oled_render_keylog(void) { oled_write(keylog_str, false); }

// Some characters position:
// cmd: 80-84/a0-a4/c0-c4
// alt: 84 85 86/a..../c...
// shift:87 88 89/a.../c...
// symbol logo: 8a-8d/aa..../ca....
// qmk logos; 8e-91/ae..../ce....
// nav logo: 92-95/b2.../d2...
// ctrl: b6 b6/d.../
// numlock: 98-9b/b.../d...
// brush: 9c-9f/b.../d...
void oled_render_layer(layer_state_t state) {
    // clang-format off
    static const char PROGMEM numlock_logo[] = {
      0x98, 0x99, 0x9a, 0x9b, 10,
      0xb8, 0xb9, 0xba, 0xbb, 10,
      0xd8, 0xd9, 0xda, 0xdb, 10, 0};
    static const char PROGMEM qmk_logo[] = {
      0x8e, 0x8f, 0x90, 0x91, 10,
      0xae, 0xaf, 0xb0, 0xb1, 10,
      0xce, 0xcf, 0xd0, 0xd1, 10, 0};
    static const char PROGMEM nav_logo[] = {
      0x92, 0x93, 0x94, 0x95, 10,
      0xb2, 0xb3, 0xb4, 0xb5, 10,
      0xd2, 0xd3, 0xd4, 0xd5, 10, 0};
    static const char PROGMEM brush_logo[] = {
      0x9c, 0x9d, 0x9e, 0x9f, 10,
      0xbc, 0xbd, 0xbe, 0xbf, 10,
      0xdc, 0xdd, 0xde, 0xdf, 10, 0};
    // clang-format on
    switch (state) {
      case _QWERTY: // fall-through
      case _WORKMAN:
        oled_write_P(qmk_logo, false);
        return;
      case _NUM:
        oled_write_P(numlock_logo, false);
        return;
      case _NAV:
        oled_write_P(nav_logo, false);
        return;
      case _MOUSE:
        oled_write_ln("OPS", false);
        return;
      case _ART:
        oled_write_P(brush_logo, false);
        return;
      default:
        if (IS_LAYER_ON(_ADJUST)) {
            oled_write_ln("ADJ", false);
        } else {
            oled_write_ln("?????", false);
        }
        oled_write_ln(" ", false);
        oled_write_ln(" ", false);
        oled_write_ln(" ", false);
        return;
    }
}

// Oneshot mods status
uint8_t osmods;

void oled_render_mods(void) {
    static const char PROGMEM ctrl[]     = {0xb6, 0xb7, 10, 0xd6, 0xd7, 10, 0x20, 0x20, 10, 0};
    static const char PROGMEM shift[]    = {0x87, 0x88, 0x89, 10, 0xa7, 0xa8, 0xa9, 10, 0xc7, 0xc8, 0xc9, 10, 0};
    static const char PROGMEM alt[]      = {0x84, 0x85, 0x86, 10, 0xa4, 0xa5, 0xa6, 10, 0xc4, 0xc5, 0xc6, 10, 0};
    static const char PROGMEM ctrl_alt[] = {0xb6, 0xb7, 0x84, 0x85, 0x86, 0xd6, 0xd7, 0xa4, 0xa5, 0xa6, 0x20, 0x20, 0xc4, 0xc5, 0xc6, 0};

    static const char PROGMEM ctrl_shift[] = {0xb6, 0xb7, 0x87, 0x88, 0x89, 0xd6, 0xd7, 0xa7, 0xa8, 0xa9, 0x20, 0x20, 0xc7, 0xc8, 0xc9, 0};
    static const char PROGMEM c_a_shift[]  = {0xb6, 0xb7, 0x84, 0x85, 0x86, 0xd6, 0xd7, 0xa4, 0xa5, 0xa6, 0x20, 0x20, 0xc4, 0xc5, 0xc6, 0x87, 0x88, 0x89, 10, 0xa7, 0xa8, 0xa9, 10, 0xc7, 0xc8, 0xc9, 10, 0};
    // Now check mod status and render.
    static uint8_t mods;
    mods = get_mods() | osmods;
    if ((mods & MOD_MASK_CTRL) && (mods & MOD_MASK_ALT) && (mods & MOD_MASK_SHIFT)) {
        oled_write_P(c_a_shift, false);
    } else if ((mods & MOD_MASK_CTRL) && (mods & MOD_MASK_ALT)) {
        oled_write_P(ctrl_alt, false);
    } else if ((mods & MOD_MASK_CTRL) && (mods & MOD_MASK_SHIFT)) {
        oled_write_P(ctrl_shift, false);
    } else if ((mods & MOD_MASK_SHIFT) && (mods & MOD_MASK_ALT)) {
        oled_write_P(alt, false);
        oled_write_P(shift, false);
    } else if (mods & MOD_MASK_CTRL) {
        oled_write_P(ctrl, false);
    } else if (mods & MOD_MASK_ALT) {
        oled_write_P(alt, false);
    } else if (mods & MOD_MASK_SHIFT) {
        oled_write_P(shift, false);
    } else {
        for (int i = 0; i < 6; ++i) {
            oled_write_ln(" ", false);
        }
    }
    return;
}

void oneshot_mods_changed_user(uint8_t mods) { osmods = mods; }

void oled_task_user(void) {
    /* oled_render_keylog(); */
    oled_render_layer(get_highest_layer(layer_state));
    oled_render_mods();
}
