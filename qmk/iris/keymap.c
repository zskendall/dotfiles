#include QMK_KEYBOARD_H
#include "quantum.h"

extern keymap_config_t keymap_config;

enum user_layers {
  _QWERTY,
  _NUM,
  _NAV,
  _MOUSE,
  _ART,
};

// Custom keycodes for modded mod-tap combos
enum user_keycodes {
  META_CZ,
};

/** Dynamic mod-tap keycode macros. */
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_RET RCTL_T(KC_ENT)
#define LALT_SPC LALT_T(KC_SPC)
#define RALT_SPC RALT_T(KC_SPC)
#define CTL_INS LCTL_T(KC_INS)

/** Dynamic layer-tap keycode macros. */
#define NUM_LB LT(_NUM, KC_LBRC)
#define NAV_RB LT(_NAV, KC_RBRC)

// Key aliases
#define __x__ KC_NO
#define _____ KC_TRNS
#define MS_TOG TG(_MOUSE)
#define KC_UNDS LSFT(KC_MINS)
#define ART_TOG TG(_ART)
#define VTERM LCTL(S(KC_F1))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /**
     * Base Layer (QWERTY): Tap on top, mod on bottom
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * | ART  |  1   |  2   |  3   |  4   |  5   |                 |   6  |   7  |   8  |   9  |   0  |  Bsp |
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * | Tab  |  Q   |  W   |  E   |  R   |  T   |                 |   Y  |   U  |   I  |   O  |   P  |   '  |
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * | Esc  |  A   |  S   |  D   |  F   |  G   |                 |   H  |   J  |   K  |   L  |   ;  |  Ret |
     * | LCtrl|      |      |      |      |      |                 |      |      |      |      |      | LCtrl|
     * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐   ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
     * | C-z  |  Z   |  X   |  C   |  V   |  B   | Del  |   |   =  |   N  |   M  |   ,  |   .  |   /  |MS_TOG|
     * | Meta |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┬───┘   └──┬───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |  (   | Spc  |  [   |          |   ]  |  Spc |   )  |
     *                         |LShft | LAlt |*Num* |          | *Nav*| RAlt | RShft|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_QWERTY] = LAYOUT(
        ART_TOG, KC_1, KC_2, KC_3, KC_4, KC_5,                        KC_6, KC_7, KC_8   , KC_9  , KC_0   , KC_BSPC,
        KC_TAB , KC_Q, KC_W, KC_E, KC_R, KC_T,                        KC_Y, KC_U, KC_I   , KC_O  , KC_P   , KC_QUOT,
        CTL_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                        KC_H, KC_J, KC_K   , KC_L  , KC_SCLN, CTL_RET,
        META_CZ, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DEL,        KC_EQL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MS_TOG ,
                        KC_LSPO, LALT_SPC, NUM_LB,                NAV_RB, RALT_SPC, KC_RSPC
    ),

    /**
     * Numeric Layer
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * |  F1  |  F2  |  F3  | F4   |  F5  |  F6  |                 |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|      |      |//////|  `   |  _   |                 |   *  |   7  |   8  |   9  |   -  |  Bsp |
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|//////|      |//////|//////|  \   |                 |   /  |   4  |   5  |   6  |   +  |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐   ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|      |      |//////|      |//////|//////|   |      |   =  |   1  |   2  |   3  |  Ret |//////|
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┬───┘   └──┬───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |//////|//////|*Pad* |          | 0    |//////|   .  |
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_NUM] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5 , KC_F6  ,                    KC_F7  , KC_F8, KC_F9, KC_F10, KC_F11 , KC_F12 ,
        _____, __x__, __x__, _____, KC_GRV, KC_UNDS,                    KC_PAST, KC_7 , KC_8 , KC_9  , KC_PMNS, KC_BSPC,
        _____, _____, __x__, _____, _____ , KC_BSLS,                    KC_PSLS, KC_4 , KC_5 , KC_6  , KC_PPLS, _____  ,
        _____, __x__, __x__, _____, __x__ , _____  , _____,      __x__, KC_PEQL, KC_1 , KC_2 , KC_3  , KC_PENT, _____  ,
                                  _____, _____, _____,              KC_0, _____, KC_DOT
    ),

    /**
     * Directional Navigation Layer
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * |      |  1   |  2   |  3   |  4   |  5   |                 |   6  |   7  |   8  |   9  |   0  |      |
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|  1   |  2   |  3   |  4   |  5   |                 |   6  |   7  |   8  |   9  |   0  |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////| Home | PgUp | PgDn | End  |      |                 |   ←  |   ↓  |   ↑  | →    |      |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐   ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|      |      |      |      |      |//////|   |      |      |      |      |      |      |//////|
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┬───┘   └──┬───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |//////|//////|//////|          | *Nav*|//////|(RShft|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_NAV] = LAYOUT(
        __x__, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                       KC_6,    KC_7,    KC_8,  KC_9,    KC_0,  __x__,
        _____, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                       KC_6,    KC_7,    KC_8,  KC_9,    KC_0,  _____,
        _____, KC_HOME, KC_PGUP, KC_PGDN, KC_END, __x__,                      KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, __x__, _____,
        _____, __x__,   __x__,   __x__,   __x__,  __x__, _____,        __x__, __x__,   __x__,   __x__, __x__,   __x__, _____,
                                        _____, _____, _____,              _____, _____, KC_RSPC
    ),

    /**
     * Mouse/Media Layer
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * |V Term|      |      |      |      |      |                 |      |      |      |      |      | PrtSc|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|      |  M↑  |      | Bri+ |      |                 |      |      |      |      |      |      |
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|  M←  |  M↓  |  M→  | Bri- |//////|                 |  W←  |  W↓  |  W↑  | W→   | Vol+ |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐   ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////| Prev | Play | Next | Stop |//////|//////|   | MsB3 |//////|//////|//////| Mute | Vol- |//////|
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┬───┘   └──┬───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |//////|//////| MsB1 |          | MsB2 |//////|//////|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_MOUSE] = LAYOUT(
        VTERM, __x__  , __x__  , __x__  , __x__  , __x__,                        __x__  , __x__  , __x__  , __x__,   __x__  , KC_PSCR,
        _____, __x__  , KC_MS_U, __x__  , KC_BRIU, __x__,                        __x__  , __x__  , __x__  , __x__,   __x__  , __x__  ,
        _____, KC_MS_L, KC_MS_D, KC_MS_R, KC_BRID, _____,                        KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_VOLU, _____  ,
        _____, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _____, _____,        KC_BTN3, _____  , _____  , _____  , KC_MUTE, KC_VOLD, _____  ,
                                        _____, _____, KC_BTN1,              KC_BTN2, _____, _____
    ),

    /**
     * Art Layer
     * Condensed layout with common Krita functions collapsed onto left half of
     * keyboard. Only fall through mod functions on right half.
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐       
     * | ART  |      |  N   |  L   |  I   |  O   |       
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       
     * |//////|      |  W   |  E   |      |  T   |       
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       
     * |//////|  A   |  S   |  D   |      |  G   |       
     * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐
     * |LShft |  Z   |  X   |  C   |  V   |  B   |  J   |
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┬───┘
     *                         |//////|//////| Ins  |    
     *                         |//////|//////|LCtrl |    
     *                         └──────┴──────┴──────┘    
     */
    [_ART] = LAYOUT(
        ART_TOG, __x__, KC_N , KC_L , KC_I , KC_O,                     __x__, __x__, __x__, __x__, __x__, __x__,
        _____  , __x__, KC_W , KC_E , __x__, KC_T,                     __x__, __x__, __x__, __x__, __x__, __x__,
        _____  , KC_A , KC_S , KC_D , __x__, KC_G,                     __x__, __x__, __x__, __x__, __x__, _____,
        KC_LSFT, KC_Z , KC_X,  KC_C,  KC_V , KC_B,  KC_J,       __x__, __x__, __x__, __x__, __x__, __x__, _____,
                                 _____, _____, CTL_INS,             _____, _____, _____
    ),
};

// Process record to handle custom user keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case META_CZ:
      if (record->event.pressed) {
        register_mods(MOD_LGUI);
        record->tap.interrupted = 0;
      } else {
        unregister_mods(MOD_LGUI);

        if (record->tap.count && !record->tap.interrupted) {
          add_weak_mods(MOD_LCTL);
          register_code(KC_Z);
          unregister_code(KC_Z);
          del_weak_mods(MOD_LCTL);
        }

        record->tap.count = 0;
      }
      return false;
  }
  return true;
}
