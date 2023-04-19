#include "tap_dances.h"

// Hyphen on one, underscore on two, or exits art mode if dance long enough
void dance_hyundexit(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code16(KC_MINS);
    unregister_code16(KC_MINS);
  } else if (state->count == 2) {
    register_code16(KC_UNDS);
    unregister_code16(KC_UNDS);
  } else if (state->count >= 5) {
    if (layer_state_is(_ART)) {
      layer_off(_ART);
    } else {
      layer_on(_ART);
    }
  }
  reset_tap_dance(state);
}

// Tap Dance Definitions, sets the index and the keycode
tap_dance_action_t tap_dance_actions[] = {
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

    [TD_HYUND_EXIT] = ACTION_TAP_DANCE_FN(dance_hyundexit),
    [TD_ZSLSH] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_SLSH),
    [TD_XDOT] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_DOT),
    [TD_CCOMM] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_COMM),
    [TD_VM] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_M),
    [TD_BN] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_N),

    [TD_SPC_RET] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
};
