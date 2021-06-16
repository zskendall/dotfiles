TAP_DANCE_ENABLE = yes
RGBLIGHT_ENABLE = yes

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
	SRC += oled.c
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	SRC += rgb.c
endif
