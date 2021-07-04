#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

enum layer_number {
  _COLEMAK = 0, // default base layer
  _LWR = 1, // Lower
  _RSE = 2, // Raise
  _ADJ = 3, // Adjust
  _QWERTY = 4, // can be base layer (not stored in EEPROM) => usefull for photoshop etc.
  _GAME = 5, // can toggle ON / OFF
};

enum my_keycodes {
  LT_LWR = SAFE_RANGE,
  LT_RSE,
  LT_GRV,
  LT_QTE,
  KEEB
  // TGL_KPD,
};
#define XXXXX KC_NO
#define _____ _______
// #define SFT_ESC SFT_T(KC_ESC)
#define SFT_ENT RSFT_T(KC_ENT)
#define CTR_HOM LCTL_T(KC_HOME)
#define ALT_END ALGR_T(KC_END)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK // mutually exclusive with _QWERTY
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  |   ;  |  =   |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |   `  |   A  |   S  |   R  |   T  |   D  |                              |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |LShEsc|   Z  |   X  |   C  |   V  |   B  |-------.              ,-------|   K  |   M  |   ,  |   .  |   /  |RShEnt|
 * |------+------+------+------+------+------|  Del  |              | Enter |------+------+------+------+------+------|
 * | LCTRL|      |      | LGUI | LAlt |  LWR |-------|              |-------|  RSE |   \  |      |      |      | RALT |
 * `-----------------------------------------/       /              \       \-----------------------------------------'
 *                   |      |      |      | /  BS   /                \ Space \ |      |      |      |
 *                   |      |      |      |/       /                  \       \|      |      |      |
 *                   `--------------------'-------'                    `-------'--------------------'
 */
[_COLEMAK] = LAYOUT( \
  KC_TAB,   KC_Q,   KC_W,   KC_F,    KC_P,    KC_G,                          KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL,  \
  LT_GRV,   KC_A,   KC_S,   KC_R,    KC_T,    KC_D,                          KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    LT_QTE,  \
  KC_LSFT,  KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,                          KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, \
  CTR_HOM,  KEEB,   XXXXX,  KC_LGUI, KC_LALT, LT_LWR,KC_DEL,         KC_ENT, LT_RSE,  KC_BSLS, XXXXX,   XXXXX,   XXXXX,   ALT_END, \
                            XXXXX,   XXXXX,   XXXXX,  KC_BSPC,       KC_SPC, XXXXX,   XXXXX,   XXXXX \
),

/* QWERTY // mutually exclusive with _COLEMAK
 */
[_QWERTY] = LAYOUT( \
  KC_TAB,   KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,  \
  LT_GRV,   KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT_QTE,  \
  KC_LSFT,  KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, \
  CTR_HOM,  KEEB,   XXXXX,  KC_LGUI, KC_LALT, LT_LWR,KC_DEL,         KC_ENT, LT_RSE,  KC_BSLS, XXXXX,   XXXXX,   XXXXX,   ALT_END, \
                            XXXXX,   XXXXX,   XXXXX,  KC_BSPC,       KC_SPC, XXXXX,   XXXXX,   XXXXX \
),

/* LOWER
 */
[_LWR] = LAYOUT( \
  KC_ESC,  KC_PCMM, KC_P7,   KC_P8,   KC_P9,   KC_PAST,                   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, \
  KC_NLCK, KC_PDOT, KC_P4,   KC_P5,   KC_P6,   KC_PSLS,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  KC_PENT, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PPLS,                   KC_EXLM, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, \
  _______, _______, _______, _______, _______, _______, KC_EQL,  _______, _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______, _______, _______, _______, _______, _______\
),

/* RAISE
 */
[_RSE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______, \
  _______, _______, _______, _______, _______, _______,                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______,                     _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, \
  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),

/* ADJUST
 */
[_ADJ] = LAYOUT( \
  XXXXXXX, KC_VOLU, KC_F7, KC_F8,   KC_F9,   KC_F10,                    KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_BRIU, XXXXXXX, \
  _______, KC_VOLD, KC_F4, KC_F5,   KC_F6,   KC_F11,                    KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BRID, _______, \
  XXXXXXX, KC_MUTE, KC_F1, KC_F2,   KC_F3,   KC_F12,                    XXXXXXX, KC_MPRV, KC_MPLY, KC_MFFD, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX,\
                           _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* GAME
 */
[_GAME] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______, _______, _______, _______ \
),
};

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool isQwertyActive = false;
// static uint16_t key_timer;
// bool no_other_key_pressed = true;
// layer_state_t currentLayer;

// void LayerTap(int layer, uint16_t tapKeycode, keyrecord_t *record, bool tapFavored) {
//   if (record->event.pressed) {
//         // pressed
//         layer_on(layer);
//         key_timer = timer_read();
//         no_other_key_pressed = true;
//       } else {
//         // released
//         if (timer_elapsed(key_timer) < tapMaxDuration) {
//           // tapped
//           if (no_other_key_pressed || tapFavored) {
//             tap_code16(tapKeycode);
//           }
//         } else {
//           // held
//         }
//         key_timer = 0;
//         layer_off(layer);
//       }
// }

// runs every time a layer is changed
layer_state_t layer_state_set_user(layer_state_t state) {
  // currentLayer = get_highest_layer(state);
  return state;
}

// runs every time a key is pressed/released
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    // case TGL_KPD:
    //   if (record->event.pressed) {
    //     // pressed
    //     isKeypadActive = !isKeypadActive;
    //       if (currentLayer == _LWR || currentLayer == _KPD) {
    //         layer_off(isKeypadActive ? _LWR : _KPD);
    //         layer_on(isKeypadActive ? _KPD : _LWR);
    //       }
    //   } else {
    //     // released
    //   }
    //   return false;

    case LT_LWR:
      LT(_LWR, KC_MINS);
      return false;

    case LT_RSE:
      LT(_RSE, KC_UNDS);
      return false;

    case LT_GRV:
      LT(_ADJ, KC_GRV);
      return false;

    case LT_QTE:
      LT(_ADJ, KC_QUOT);
      return false;

    case KEEB:
      isQwertyActive = !isQwertyActive;
      layer_off(isQwertyActive ? _COLEMAK : _QWERTY);
      layer_on(isQwertyActive ? _QWERTY : _COLEMAK);
      return false;

    case KC_SPC:
      return true;

    default:
      if (record->event.pressed) {
        // pressed
        // no_other_key_pressed = false;
      } else {
        // released
      }
      return true; // Process all other keycodes
  }

  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}