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

// Key aliases
#define __x__ KC_NO
#define _____ KC_TRNS
#define MS_TOG TG(_MOUSE)
#define KC_UNDS LSFT(KC_MINS)
#define VTERM LCTL(S(KC_F1))

/** Dynamic mod-tap keycode macros. */
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_QUOT RCTL_T(KC_QUOT)
#define LALT_LB LALT_T(KC_LBRC)
#define RALT_RB RALT_T(KC_RBRC)
#define CTL_INS LCTL_T(KC_INS)

/** Dynamic layer-tap keycode macros. */
#define NUM_SPC LT(_NUM, KC_SPC)
#define NAV_RET LT(_NAV, KC_RET)

#define METART LGUI(MS_TOG)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /**
     * Base Layer (QWERTY): Tap on top, mod on bottom
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * | Tab  |  Q   |  W   |  E   |  R   |  T   |                 |   Y  |   U  |   I  |   O  |   P  |  Bsp |
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * | Esc  |  A   |  S   |  D   |  F   |  G   |                 |   H  |   J  |   K  |   L  |   ;  |   '  |
     * | LCtrl|      |      |      |      |      |                 |      |      |      |      |      | LCtrl|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |  MS  |  Z   |  X   |  C   |  V   |  B   |                 |   N  |   M  |   ,  |   .  |   /  |   -  |
     * | Meta |      |      |      |      |      |                 |      |      |      |      |      |      |
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┐          ┌───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |  (   |  [   | Spc  |          |  Ret |   ]  |   )  |
     *                         |LShft | LAlt |*Num* |          | *Nav*| RAlt | RShft|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_QWERTY] = LAYOUT(
        KC_TAB , KC_Q, KC_W, KC_E, KC_R, KC_T,                        KC_Y, KC_U, KC_I   , KC_O  , KC_P   , KC_BSPC,
        CTL_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                        KC_H, KC_J, KC_K   , KC_L  , KC_SCLN, CTL_QUOT,
        METART , KC_Z, KC_X, KC_C, KC_V, KC_B,                        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
                        KC_LSPO, LALT_LB, NUM_SPC,                NAV_RET, RALT_RB, KC_RSPC
    ),

    /**
     * Numeric Layer
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * |//////|      |      |//////|  `   |  _   |                 |   *  |   7  |   8  |   9  |   -  |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|//////|      |//////|//////|  \   |                 |   /  |   4  |   5  |   6  |   +  |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤		   ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|      |      |//////|      |//////|                 |   =  |   1  |   2  |   3  |   .  |//////|
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┐          ┌───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |//////|//////|*Pad* |          | 0    |//////|//////|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_NUM] = LAYOUT(
        _____, __x__, __x__, _____, KC_GRV, KC_UNDS,                    KC_PAST, KC_7 , KC_8 , KC_9  , KC_PMNS, KC_BSPC,
        _____, _____, __x__, _____, _____ , KC_BSLS,                    KC_PSLS, KC_4 , KC_5 , KC_6  , KC_PPLS, _____  ,
        _____, __x__, __x__, _____, __x__ , _____  ,                    KC_PEQL, KC_1 , KC_2 , KC_3  , KC_DOT,  _____  ,
                                  _____, _____, _____,              KC_0, _____, _____
    ),

    /**
     * Directional Navigation Layer
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * |//////| ws1  | ws2  | ws3  | ws4  | ws5  |                 |  ws6 |  ws7 |  ws8 |  ws9 |  ws0 |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////| Home | PgUp | PgDn | End  |      |                 |   ←  |   ↓  |   ↑  |  →   |      |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤		   ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////| tab1 | tab2 | tab3 | tab4 | tab5 |                 | tab6 | tab7 | tab8 | tabX |      |//////|
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┐          ┌───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |//////|//////|//////|          | *Nav*|//////|//////|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_NAV] = LAYOUT(
        _____, RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5),    RALT(KC_6), RALT(KC_7), RALT(KC_8), RALT(KC_9), RALT(KC_0),  _____,
        _____, KC_HOME, KC_PGUP, KC_PGDN, KC_END, __x__,                      KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, __x__, _____,
        _____, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5),    LCTL(KC_6), LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), __x__,  _____,
                                        _____, _____, _____,              _____, _____, _____
    ),

    /**
     * Mouse/Media Layer
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * |//////|V Term|  M↑  |      | Bri+ |      |                 |      |      |      |      | MsB3 | PrtSc|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|  M←  |  M↓  |  M→  | Bri- |//////|                 |  W←  |  W↓  |  W↑  | W→   | Vol+ |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤		   ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////| Prev | Play | Next | Stop |//////|                 |//////|//////|//////| Mute | Vol- |MS_TOG|
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┐          ┌───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |//////|//////| MsB1 |          | MsB2 |//////|//////|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_MOUSE] = LAYOUT(
        _____, VTERM  , KC_MS_U, __x__  , KC_BRIU, __x__,                        __x__  , __x__  , __x__  , __x__,   KC_BTN3, KC_PSCR,
        _____, KC_MS_L, KC_MS_D, KC_MS_R, KC_BRID, _____,                        KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_VOLU, _____  ,
        _____, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _____,                        _____  , _____  , _____  , KC_MUTE, KC_VOLD, MS_TOG ,
                                        _____, _____, KC_BTN1,              KC_BTN2, _____, _____
    ),
};
