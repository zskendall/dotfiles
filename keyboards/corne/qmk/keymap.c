#include QMK_KEYBOARD_H
#include "quantum.h"

extern keymap_config_t keymap_config;

enum user_layers {
  _QWERTY,
  _COLEMAK,
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
#define ART_TOG TG(_ART)
#define VTERM LCTL(S(KC_F1))
#define CMAK TG(_COLEMAK)
#define TERM LGUI(KC_ENT)

/** Dynamic mod-tap keycode macros. */
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_QUOT RCTL_T(KC_QUOT)
#define LALT_SPC LALT_T(KC_SPC)
#define META_RET RGUI_T(KC_ENT)
#define CTL_INS LCTL_T(KC_INS)

/** Dynamic layer-tap keycode macros. */
#define NUM_LB LT(_NUM, KC_LBRC)
#define NAV_RB LT(_NAV, KC_RBRC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /**
     * Base Layer (QWERTY): Tap on top, mod on bottom
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * | Tab  |  Q   |  W   |  E   |  R   |  T   |                 |   Y  |   U  |   I  |   O  |   P  |  Bsp |
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * | Esc  |  A   |  S   |  D   |  F   |  G   |                 |   H  |   J  |   K  |   L  |   ;  |   '  |
     * | LCtrl|      |      |      |      |      |                 |      |      |      |      |      | LCtrl|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * | ART  |  Z   |  X   |  C   |  V   |  B   |                 |   N  |   M  |   ,  |   .  |   /  |   -  |
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┐          ┌───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |  (   | Spc  |  [   |          |   ]  |  Ret |   )  |
     *                         |LShft | LAlt |*Num* |          | *Nav*| Meta | RShft|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_QWERTY] = LAYOUT(
        KC_TAB , KC_Q, KC_W, KC_E, KC_R, KC_T,                        KC_Y, KC_U, KC_I   , KC_O  , KC_P   , KC_BSPC,
        CTL_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                        KC_H, KC_J, KC_K   , KC_L  , KC_SCLN, CTL_QUOT,
        ART_TOG, KC_Z, KC_X, KC_C, KC_V, KC_B,                        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
                        KC_LSPO, LALT_SPC, NUM_LB,                NAV_RB, META_RET, KC_RSPC
    ),

    /**
     * Modified Colemak Layer
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * |//////|  Q   |  W   |  F   |  P   |  G   |                 |   J  |   L  |   U  |   Y  |   ;  |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|  A   |  S   |  R   |  T   |  D   |                 |   H  |   N  |   E  |   I  |   O  |   '  |
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * | CMAK |  Z   |  X   |  C   |  V   |  B   |                 |   K  |   M  |   ,  |   .  |   /  |   -  |
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┐          ┌───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |//////|//////|//////|          |//////|//////|//////|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_COLEMAK] = LAYOUT(
	_____, _____, _____, KC_F , KC_P , KC_G ,		      KC_J, KC_L , KC_U , KC_Y , KC_SCLN, _____,
	_____, _____, _____, KC_R , KC_T , KC_D ,		      KC_H, KC_N , KC_E , KC_I , KC_O   , _____,
	CMAK , _____, _____, _____, _____, _____,		      KC_K, _____, _____, _____, _____  , _____,
                                  _____, _____, _____,            _____, _____, _____
    ),

    /**
     * Numeric Layer
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * |//////|      |      |  E   |  `   |  _   |                 |   *  |   7  |   8  |   9  |   -  |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|//////|      |  D   |  F   |  \   |                 |   /  |   4  |   5  |   6  |   +  |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤		             ├──────┼──────┼──────┼──────┼──────┼──────┤
     * | TERM |      |      |//////|      |//////|                 |   =  |   1  |   2  |   3  |   .  |  Del |
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┐          ┌───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |//////|//////|*Pad* |          | 0    |//////|//////|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_NUM] = LAYOUT(
        _____, __x__, __x__, KC_E , KC_GRV, KC_UNDS,                    KC_PAST, KC_7 , KC_8 , KC_9  , KC_MINS, _____ ,
        _____, _____, __x__, KC_D , KC_F  , KC_BSLS,                    KC_PSLS, KC_4 , KC_5 , KC_6  , KC_PPLS, _____ ,
        TERM , __x__, _____, _____, __x__ , _____  ,                    KC_EQL , KC_1 , KC_2 , KC_3  , KC_DOT , KC_DEL,
                                  _____, _____, _____,              KC_0, _____, _____
    ),

    /**
     * Directional Navigation Layer
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * |//////| ws1  | ws2  | ws3  | ws4  | ws5  |                 |  ws6 |  ws7 |  ws8 |  ws9 |  ws0 |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////| Home | PgUp | PgDn | End  |      |                 |   ←  |   ↓  |   ↑  |  →   |      | LOCK |
     * ├──────┼──────┼──────┼──────┼──────┼──────┤		             ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////| tab1 | tab2 | tab3 | tab4 | tab5 |                 | tab6 | tab7 | tab8 | tabX |      |MS_TOG|
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┐          ┌───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |//////|//////|//////|          | *Nav*|//////|//////|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_NAV] = LAYOUT(
        _____, RGUI(KC_1), RGUI(KC_2), RGUI(KC_3), RGUI(KC_4), RGUI(KC_5),    RGUI(KC_6), RGUI(KC_7), RGUI(KC_8), RGUI(KC_9), RGUI(KC_0),  _____,
        _____, KC_HOME, KC_PGUP, KC_PGDN, KC_END, __x__,                      KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, __x__, LGUI(KC_L),
        _____, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5),    LCTL(KC_6), LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), __x__,  MS_TOG,
                                        _____, _____, _____,              _____, _____, _____
    ),

    /**
     * Mouse/Media Layer
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * |RESET |V Term|  M↑  |      | Bri+ |      |                 |  F1  |  F2  |  F6  |      | MsB3 | PrtSc|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|  M←  |  M↓  |  M→  | Bri- |//////|                 |  W←  |  W↓  |  W↑  | W→   | Vol+ |//////|
     * ├──────┼──────┼──────┼──────┼──────┼──────┤		             ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////| Prev | Play | Next | Stop |//////|                 |//////|//////|//////| Mute | Vol- |MS_TOG|
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┐          ┌───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
     *                         |//////|//////| MsB1 |          | MsB2 |//////|//////|
     *                         └──────┴──────┴──────┘          └──────┴──────┴──────┘
     */
    [_MOUSE] = LAYOUT(
        RESET, VTERM  , KC_MS_U, __x__  , KC_BRIU, __x__,                        KC_F1  , KC_F2  , KC_F6  , __x__,   KC_BTN3, KC_PSCR,
        _____, KC_MS_L, KC_MS_D, KC_MS_R, KC_BRID, _____,                        KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_VOLU, _____  ,
        _____, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _____,                        _____  , _____  , _____  , KC_MUTE, KC_VOLD, MS_TOG ,
                                        _____, _____, KC_BTN1,              KC_BTN2, _____, _____
    ),

    /**
     * Art Layer
     * Condensed layout with common Krita functions collapsed onto left half of
     * keyboard. Only fall through mod functions on right half.
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * | ART  |  N   |  W   |  E   |  O   |  T   |
     * ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |//////|  A   |  S   |  D   |  J   |  G   |
     * ├──────┼──────┼──────┼──────┼──────┼──────┤
     * |LShft |  Z   |  X   |  C   |  V   |  B   |
     * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┐
     *                         |//////|//////| Ins  |
     *                         |//////|//////|LCtrl |
     *                         └──────┴──────┴──────┘
     */
    [_ART] = LAYOUT(
        ART_TOG, KC_N, KC_W, KC_E, KC_O, KC_T,                     __x__, __x__, __x__, __x__, __x__, __x__,
        _____  , KC_A, KC_S, KC_D, KC_J, KC_G,                     __x__, __x__, __x__, __x__, __x__, _____,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                     __x__, __x__, __x__, __x__, __x__, __x__,
                                 _____, _____, CTL_INS,         _____, _____, _____
    ),
};