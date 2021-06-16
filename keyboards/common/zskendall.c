#include "zskendall.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CHDF:
      if (record->event.pressed) {
        uint32_t default_layer = biton32(default_layer_state);
        for (uint8_t i = 1; i < num_defaults; i++) {
          if (defaults[(default_layer + i) % num_defaults]) {
            default_layer_set(1U << (default_layer + i) % num_defaults);
            return false;
          }
        }
      }
      return false;
  }
  return true;
}
