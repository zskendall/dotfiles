#pragma once

// Prevent fast combos registering as mods
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD

#ifdef MOUSEKEY_ENABLE
#    define MOUSEKEY_INTERVAL 20
#    define MOUSEKEY_DELAY 0
#    define MOUSEKEY_TIME_TO_MAX 60
#    define MOUSEKEY_MAX_SPEED 7
#    define MOUSEKEY_WHEEL_DELAY 0
#endif //MOUSEKEY_ENABLE

#ifdef SPLIT_KEYBOARD
#    define USE_I2C
#    undef SPLIT_HAND_PIN
#    undef SPLIT_HAND_MATRIX_GRID
#    define EE_HANDS
#endif // SPLIT_KEYBOARD
