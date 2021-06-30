#include QMK_KEYBOARD_H

#define _BL 0
#define _FL 1
#define _CL 2

enum tap {
  TD_CAPS
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _BL: (Base Layer) Default Layer
     * ,----------------------------------------------------------------.
     * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
     * |----------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
     * |----------------------------------------------------------------|
     * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
     * |----------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
     * |----------------------------------------------------------------|
     * |Ctrl|Win |Alt |        Space          |FN2|FN1|Ctrl|Lef|Dow|Rig |
     * `----------------------------------------------------------------'
     */
    [_BL] = LAYOUT_65_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_CAPS,
        TD(TD_CAPS), KC_A,KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
        KC_LGUI, KC_LALT, KC_LCTL,                            KC_SPC,                    TT(_CL), MO(_FL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Keymap _FL: Function Layer
     * ,----------------------------------------------------------------.
     * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
     * |----------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |Hme |
     * |----------------------------------------------------------------|
     * |      |   |   |   |   |   |   |PRV|PLY|NXT|   |   |        |End |
     * |----------------------------------------------------------------|
     * |        |   |   |   |   |   |   |VU-|VU+|MUT|   |   McL|MsU|McR |
     * |----------------------------------------------------------------|
     * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
     * `----------------------------------------------------------------'
     */
    [_FL] = LAYOUT_65_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  KC_SLEP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_PGUP, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, KC_HOME, KC_PGDN, KC_END  
    ),

    /* Keymap _CL: Secondary Function Layer
     * ,----------------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |    |
     * |----------------------------------------------------------------|
     * |     |McL|MsU|McR|MwU|   |   |   |   |   |   |   |   |     |    |
     * |----------------------------------------------------------------|
     * |      |MsL|MsD|MsR|MwD|   |   |   |   |   |   |   |        |    |
     * |----------------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |      |   |    |
     * |----------------------------------------------------------------|
     * |    |    |    |                       |   |   |    |   |   |    |
     * `----------------------------------------------------------------'
     */
    [_CL] = LAYOUT_65_ansi(
        KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, _______, _______, _______, _______,          _______, _______, 
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    )
};

enum combos {
    PREV,
    NEXT,
    SHOW,
    HOME,
    ENDK,
    WORDF,
    WORDB
};

const uint16_t PROGMEM prev_combo[] = {KC_RCTL, KC_LEFT, COMBO_END};
const uint16_t PROGMEM next_combo[] = {KC_RCTL, KC_RGHT, COMBO_END};
const uint16_t PROGMEM show_combo[] = {KC_RCTL, KC_UP, COMBO_END};
const uint16_t PROGMEM home_combo[] = {KC_LCTL, KC_LEFT, COMBO_END};
const uint16_t PROGMEM end_combo[] = {KC_LCTL, KC_RGHT, COMBO_END};
const uint16_t PROGMEM wordf_combo[] = {KC_LALT, KC_RGHT, COMBO_END};
const uint16_t PROGMEM wordb_combo[] = {KC_LALT, KC_LEFT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [PREV] = COMBO_ACTION(prev_combo),
    [NEXT] = COMBO_ACTION(next_combo),
    [SHOW] = COMBO_ACTION(show_combo),
    [HOME] = COMBO_ACTION(home_combo),
    [ENDK] = COMBO_ACTION(end_combo),
    [WORDF] = COMBO_ACTION(wordf_combo),
    [WORDB] = COMBO_ACTION(wordb_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {

  switch(combo_index) {
    case PREV:
      if (pressed && combo_pressed < 1) {
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        register_code(KC_LEFT);
        clear_keyboard_but_mods();
      } else {
        clear_keyboard();
      }
      break;
    
    case NEXT:
      if (pressed) {
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        register_code(KC_RGHT);
        clear_keyboard();
      }
      break;
    
    case SHOW:
      if (pressed) {
        register_code(KC_LGUI);
        register_code(KC_TAB);
        clear_keyboard();
      }
    break;

    case HOME:
      if (pressed) {
        register_code(KC_HOME);
        clear_keyboard();
      }
    break;

    case ENDK:
      if (pressed) {
        register_code(KC_END);
        clear_keyboard();
      }
    break;

    case WORDF:
      if (pressed) {
        register_code(KC_LCTL);
        register_code(KC_RGHT);
        clear_keyboard();
      }
    break;

    case WORDB:
      if (pressed) {
        register_code(KC_LCTL);
        register_code(KC_LEFT);
        clear_keyboard();
      }
    break;
  }
};