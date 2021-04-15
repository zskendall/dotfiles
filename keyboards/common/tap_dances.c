#include "tap_dances.h"

// Exits art mode if dance was long enough
void art_dance_back(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 5) {
    if (layer_state_is(_ART)) {
      layer_off(_ART);
    } else {
      layer_on(_ART);
    }
    reset_tap_dance(state);
  }
}

// Tap Dance Definitions, sets the index and the keycode
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_TAB_BSP] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_BSPC),
  [TD_QP] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_P),
  [TD_WO] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_O),
  [TD_EI] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_I),
  [TD_RU] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_U),
  [TD_TY] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_Y),

  [TD_ESC_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_QUOT),
  [TD_ASCLN] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_SCLN),
  [TD_SL] = ACTION_TAP_DANCE_DOUBLE(KC_S, KC_L),
  [TD_DK] = ACTION_TAP_DANCE_DOUBLE(KC_D, KC_K),
  [TD_FJ] = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_J),
  [TD_GH] = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_H),

  [TD_ZSLSH] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_SLSH),
  [TD_XDOT] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_DOT),
  [TD_CCOMM] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_COMM),
  [TD_VM] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_M),
  [TD_BN] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_N),

  [TD_SPC_RET] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),

  [TD_ART] = ACTION_TAP_DANCE_FN(art_dance_back),
};
