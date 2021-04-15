#include "zskendall.h"


// Custom keycodes for modded mod-tap combos
enum keycodes {
  META_CZ,
};

/** Iris-specific dynamic mod-tap keycode macros (deprecated). */
#define CTL_RET RCTL_T(KC_ENT)
#define RALT_EQL RALT_T(KC_EQL)


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
     * | C-z  |  Z   |  X   |  C   |  V   |  B   | Del  |   |MS_TOG|   N  |   M  |   ,  |   .  |   /  |   -  |
     * | Meta |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┬───┘   └──┬───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |  (   | Spc  |  [   |          |   ]  |   =  |   )  |
     *                         |LShft | LAlt |*Num* |          | *Nav*| RAlt | RShft|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_QWERTY] = LAYOUT(
        ART_TOG, KC_1, KC_2, KC_3, KC_4, KC_5,                        KC_6, KC_7, KC_8   , KC_9  , KC_0   , KC_BSPC,
        KC_TAB , KC_Q, KC_W, KC_E, KC_R, KC_T,                        KC_Y, KC_U, KC_I   , KC_O  , KC_P   , KC_QUOT,
        CTL_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                        KC_H, KC_J, KC_K   , KC_L  , KC_SCLN, CTL_RET,
        META_CZ, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DEL,        MS_TOG, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
                        KC_LSPO, LALT_SPC, NUM_LB,                NAV_RB, RALT_EQL, KC_RSPC
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
     * |//////|      |      |//////|      |//////|//////|   |      |   =  |   1  |   2  |   3  |   .  |//////|
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┬───┘   └──┬───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |//////|//////|*Pad* |          | 0    |//////|//////|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_NUM] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5 , KC_F6  ,                    KC_F7  , KC_F8, KC_F9, KC_F10, KC_F11 , KC_F12 ,
        _____, KC_NO, KC_NO, _____, KC_GRV, KC_UNDS,                    KC_PAST, KC_7 , KC_8 , KC_9  , KC_PMNS, KC_BSPC,
        _____, _____, KC_NO, _____, _____ , KC_BSLS,                    KC_PSLS, KC_4 , KC_5 , KC_6  , KC_PPLS, _____  ,
        _____, KC_NO, KC_NO, _____, KC_NO , _____  , _____,      KC_NO, KC_PEQL, KC_1 , KC_2 , KC_3  , KC_DOT,  _____  ,
                                  _____, _____, _____,              KC_0, _____, _____
    ),

    /**
     * Directional Navigation Layer
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * |      |  1   |  2   |  3   |  4   |  5   |                 |   6  |   7  |   8  |   9  |   0  |      |
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////| ws1  | ws2  | ws3  | ws4  | ws5  |                 |  ws6 |  ws7 |  ws8 |  ws9 |  ws0 |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////| Home | PgUp | PgDn | End  |      |                 |   ←  |   ↓  |   ↑  |  →   |      |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐   ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////| tab1 | tab2 | tab3 | tab4 | tab5 |//////|   |      | tab6 | tab7 | tab8 | tabX |      |//////|
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┬───┘   └──┬───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |//////|//////|//////|          | *Nav*|//////|//////|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_NAV] = LAYOUT(
        KC_NO, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                       KC_6,    KC_7,    KC_8,  KC_9,    KC_0,  KC_NO,
        _____, RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5),    RALT(KC_6), RALT(KC_7), RALT(KC_8), RALT(KC_9), RALT(KC_0),  _____,
        _____, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO,                      KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, _____,
        _____, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), _____,    KC_NO, LCTL(KC_6), LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), KC_NO,  _____,
                                        _____, _____, _____,              _____, _____, _____
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
     * |//////| Prev | Play | Next | Stop |//////|//////|   | MsB3 |//////|//////|//////| Mute | Vol- |MS_TOG|
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┬───┘   └──┬───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |//////|//////| MsB1 |          | MsB2 |//////|//////|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_MOUSE] = LAYOUT(
        VTERM, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO,                        KC_NO  , KC_NO  , KC_NO  , KC_NO,   KC_NO  , KC_PSCR,
        _____, KC_NO  , KC_MS_U, KC_NO  , KC_BRIU, KC_NO,                        KC_NO  , KC_NO  , KC_NO  , KC_NO,   KC_NO  , KC_NO  ,
        _____, KC_MS_L, KC_MS_D, KC_MS_R, KC_BRID, _____,                        KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_VOLU, _____  ,
        _____, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _____, _____,        KC_BTN3, _____  , _____  , _____  , KC_MUTE, KC_VOLD, MS_TOG ,
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
        ART_TOG, KC_NO, KC_N , KC_L , KC_I , KC_O,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        _____  , KC_NO, KC_W , KC_E , KC_NO, KC_T,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        _____  , KC_A , KC_S , KC_D , KC_NO, KC_G,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _____,
        KC_LSFT, KC_Z , KC_X,  KC_C,  KC_V , KC_B,  KC_J,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _____,
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
