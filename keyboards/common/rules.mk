# Enable mouse keys and audio/system controls on all keyboards.
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tap_dances.c
endif

# Diable unused options on all keyboards.
LEADER_ENABLE = no
RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
