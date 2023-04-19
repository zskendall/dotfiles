# Enable mouse keys and audio/system controls on all keyboards.
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes

SRC += zskendall.c

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tap_dances.c
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	SRC += rgb.c
endif

# Diable unused options on all keyboards.
LEADER_ENABLE = no
BACKLIGHT_ENABLE = no
