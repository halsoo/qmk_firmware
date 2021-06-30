# How to setup TADA68 keymap

1. `cd ../..`
2. open `rules.mk`
3. add `COMBO_ENABLE = yes`, `TAP_DANCE_ENABLE = yes`, `BACKLIGHT_ENABLE = no`, `RGBLIGHT_ENABLE = no`
4. save and exit
5. open `config.h`
6. add `#define COMBO_COUNT 7`, `#define TAPPING_TERM 200`, `#define TAPPING_TERM_PER_KEY`, `#define TAPPING_TOGGLE`
7. save and exit

`make tada68:UKGU-WIN:flashbin`