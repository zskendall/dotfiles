#include QMK_KEYBOARD_H
#include "keymap_common.h"
#include "action_tapping.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NAV 3
#define _GUI 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NAV,
  GUI,
};

// Modifier-delimiter hold-tap macros
#define LSFT_BRACE 0
#define RSHFT_BRACE 1
#define LALT_PAREN 2
#define RALT_PAREN 3

// Key aliases
#define _______ KC_TRNS
#define ___x___ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /**
   * Base Layer (QWERTY): Tap on top, hold-mod on bottom
   * ┌──────┬──────┬──────┬──────┬──────┬──────┐                          ┌──────┬──────┬──────┬──────┬──────┬──────┐
   * |  `   |  1   |  2   |  3   |  4   |  5   |                          |   6  |   7  |   8  |   9  |   0  |  Bsp |
   * ├──────┼──────┼──────┼──────┼──────┼──────┤                          ├──────┼──────┼──────┼──────┼──────┼──────┤
   * | Tab  |  Q   |  W   |  E   |  R   |  T   |                          |   Y  |   U  |   I  |   O  |   P  |   '  |
   * ├──────┼──────┼──────┼──────┼──────┼──────┤                          ├──────┼──────┼──────┼──────┼──────┼──────┤
   * | Esc  |  A   |  S   |  D   |  F   |  G   |                          |   H  |   J  |   K  |   L  |   ;  |  Ret |
   * | LCtrl|      |      |      |      |      |                          |      |      |      |      |  Fn3 | LCtrl|
   * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐            ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   * |  {   |  Z   |  X   |  C   |  V   |  B   | Del  |            |   =  |   N  |   M  |   ,  |   .  |   /  |   }  |
   * | LShft|      |      |      |      |      |      |            |      |      |      |      |      |      | RShft|
   * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┬───┘            └──┬───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
   *                         | Fn2  |  (   | Fn1  |                   | Spc  |   )  |  Fn2 |              |
   *                         |      | LAlt |      |                   |      | RAlt |      |         Fn3 = Nav Layer
   *                         └──────┴──────┴──────┘                   └──────┴──────┴──────┘
   *      Fn2 = GUI Layer ______/            /                                          \______ Fn2 = GUI Layer
   *                      Fn1 = Lower ______/
   * SBSP, Z  , X  , C  , V  , B  ,LALT,     RALT, N  , M  ,COMM,DOT ,SLSH,SENT,
   */
  [_QWERTY] = LAYOUT(
     KC_GRV,  KC_1 ,  KC_2 ,  KC_3 ,  KC_4 ,  KC_5 ,                KC_6 ,  KC_7 ,  KC_8 ,  KC_9 ,  KC_0 ,KC_BSPC,
     KC_TAB,  KC_Q ,  KC_W ,  KC_E ,  KC_R ,  KC_T ,                KC_Y ,  KC_U ,  KC_I ,  KC_O ,  KC_P ,KC_QUOT,
     F()   ,  KC_A ,  KC_S ,  KC_D ,  KC_F ,  KC_G ,                KC_H ,  KC_J ,  KC_K ,  KC_L ,  F()  , F(),
     F()   ,  KC_Z ,  KC_X ,  KC_C ,  KC_V ,  KC_B , KC_DEL, KC_EQ, KC_N ,  KC_M , KC_COMM, KC_DOT, KC_SLSH, F(),
                                   F()   , F(),   F(),             KC_SPC,  F(),   F()
  ),

  /**
   * Numeric Layer
   * ┌──────┬──────┬──────┬──────┬──────┬──────┐                          ┌──────┬──────┬──────┬──────┬──────┬──────┐
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                          |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * ├──────┼──────┼──────┼──────┼──────┼──────┤                          ├──────┼──────┼──────┼──────┼──────┼──────┤
   * |      |  1   |  2   |  3   |  4   |  5   |                          |   6  |   7  |   8  |   9  |   0  |      |
   * ├──────┼──────┼──────┼──────┼──────┼──────┤                          ├──────┼──────┼──────┼──────┼──────┼──────┤
   * |//////|  -   |  =   |  `   |  \   |  a   |                          |   b  |   c  |   d  |   e  |   f  |//////|
   * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐            ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   * |//////|      |      |      |      |      |      |            |      |      |      |      |      |      |//////|
   * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┬───┘            └──┬───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
   *                         |//////|//////|*Fn1* |                   |      |//////|//////|
   *                         └──────┴──────┴──────┘                   └──────┴──────┴──────┘
   *
  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, _______, _______, _______, KC_DOWN, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  /**
   * Directional Navigation Layer
   * ┌──────┬──────┬──────┬──────┬──────┬──────┐                          ┌──────┬──────┬──────┬──────┬──────┬──────┐
   * |      |      |      |      |      |      |                          |      |      |      |      |      |      |
   * ├──────┼──────┼──────┼──────┼──────┼──────┤                          ├──────┼──────┼──────┼──────┼──────┼──────┤
   * |      |      |      |      |      |      |                          |      |      |      |      |      |      |
   * ├──────┼──────┼──────┼──────┼──────┼──────┤                          ├──────┼──────┼──────┼──────┼──────┼──────┤
   * |//////|      | Home | PgUp | PgDn | End  |                          |   ←  |   ↓  |   ↑  |   →  | *Fn3*|//////|
   * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐            ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   * |//////|      |      |      |      |      |      |            |      |      |      |      |      |      |//////|
   * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┬───┘            └──┬───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
   *                         |//////|//////|//////|                   |      |//////|//////|
   *                         └──────┴──────┴──────┘                   └──────┴──────┴──────┘
   *
  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  /**
   * GUI/Media Layer
   * ┌──────┬──────┬──────┬──────┬──────┬──────┐                          ┌──────┬──────┬──────┬──────┬──────┬──────┐
   * |      |      |      |      |      |      |                          |      |      |      |      |      |      |
   * ├──────┼──────┼──────┼──────┼──────┼──────┤                          ├──────┼──────┼──────┼──────┼──────┼──────┤
   * |      |      |  M↑  |      | Bri+ |      |                          |      |      |      |      |      |      |
   * ├──────┼──────┼──────┼──────┼──────┼──────┤                          ├──────┼──────┼──────┼──────┼──────┼──────┤
   * |//////|  M←  |  M↓  |  M→  | Bri- |      |                          |  W←  |  W↓  |  W↑  |  W→  | Vol+ |//////|
   * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐            ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
   * |//////| Prev | Play | Next | Stop |      |Sleep?|            | MsB3 |      |      |      | Mute | Vol- |      |
   * └──────┴──────┴──────┴──┬───┴──┬───┴──┬───┴──┬───┘            └──┬───┴──┬───┴──┬───┴──┬───┴──────┴──────┴──────┘
   *                         |*Fn2* |//////| MsB1 |                   | MsB2 |//////| *Fn2*|
   *                         └──────┴──────┴──────┘                   └──────┴──────┴──────┘
   *
  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};
*/

const uint16_t PROGMEM fn_actions[] = {
  // Layer Switching
  [0] = ACTION_LAYER_TAP_TOGGLE(_LOWER),
  [1] = ACTION_LAYER_TAP_TOGGLE(_GUI),
  [2] = ACTION_LAYER_TAP_KEY(_NAV, KC_SCOLON),

  // Modifiers
  [3] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [4] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),

  [5] = ACTION_MACRO_TAP(LSFT_BRACE),
  [6] = ACTION_MACRO_TAP(RSFT_BRACE),
  [7] = ACTION_MACRO_TAP(LALT_PAREN),
  [8] = ACTION_MACRO_TAP(RALT_PAREN),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    // Note: You must change the "magic" key combo in config.h to avoid issues
    // with shfit tap keys, which is LSFT + RSFT by default. (???)
    case LSFT_BRACE:
      if (record->event.pressed) {
        register_code(MOD_LSFT);
        record->tap.interrupted = 0;
      } else {
        if (record->tap.count && !record->tap.interrupted) {
          register_code(KC_LBRACKET);
          unregister_code(KC_LBRACKET);
        }

        unregister_mods(MOD_LSFT);
        record->tap.count = 0;
      }
      break;
    case RSFT_BRACE:
      if (record->event.pressed) {
        register_code(MOD_LSFT);
        record->tap.interrupted = 0;
      } else {
        if (record->tap.count && !record->tap.interrupted) {
          register_code(KC_RBRACKET);
          unregister_code(KC_RBRACKET);
        }

        unregister_mods(MOD_LSFT);
        record->tap.count = 0;
      }
      break;
    case LALT_PAREN:
      if (record->event.pressed) {
        register_mods(MOD_LALT);
        record->tap.interrupted = 0;
      } else {
        unregister_mods(MOD_LALT);

        if (record->tap.count && !record->tap.interrupted) {
          add_weak_mods(MOD_LSFT);
          register_code(KC_9);
          unregister_code(KC_9);
          del_weak_mods(MOD_LSFT);
        }

        record->tap.count = 0;
      }
      break;
    case RALT_PAREN:
      if (record->event.pressed) {
        register_mods(MOD_RALT);
        record->tap.interrupted = 0;
      } else {
        unregister_mods(MOD_RALT);

        if (record->tap.count && !record->tap.interrupted) {
          add_weak_mods(MOD_LSFT);
          register_code(KC_9);
          unregister_code(KC_9);
          del_weak_mods(MOD_LSFT);
        }

        record->tap.count = 0;
      }
      break;
  }
  return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    /*case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;*/
  }
  return true;
}
