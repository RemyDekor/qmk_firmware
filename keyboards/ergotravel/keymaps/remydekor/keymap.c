#include QMK_KEYBOARD_H

#define _COLEMAK 0 // default base layer
#define _LWR 1 // Lower
#define _RSE 2 // Raise
#define _ADJ 3 // Adjust
#define _QWERTY 4 // can be base layer (not stored in EEPROM) => usefull for photoshop etc.
#define _GAME 5 // can toggle ON / OFF
 

enum custom_keycodes {
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

  //   [_QWERTY] = LAYOUT(
  // //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
  //    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,          KC_EQL, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  // //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
  //    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,          KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  // //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
  //    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  // //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
  //    KC_LCTL, KC_LGUI, KC_LALT, ADJUST,           LOWER,   KC_SPC,           KC_SPC,  RAISE,            KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
  // //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  // ),

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
  KC_TAB,   KC_Q,   KC_W,   KC_F,    KC_P,    KC_G,   XXXXX,         XXXXX,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL,  \
  LT_GRV,   KC_A,   KC_S,   KC_R,    KC_T,    KC_D,   XXXXX,         XXXXX,  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    LT_QTE,  \
  KC_LSFT,  KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,   KC_DEL,        KC_ENT, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, \
  CTR_HOM,  KEEB,   KC_LGUI, KC_LALT, LT_LWR,         KC_BSPC,       KC_SPC, LT_RSE,           KC_BSLS, XXXXX,   XXXXX,   ALT_END \
),

/* QWERTY // mutually exclusive with _COLEMAK
 */
[_QWERTY] = LAYOUT( \
  KC_TAB,   KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,   XXXXX,         XXXXX,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,  \
  LT_GRV,   KC_A,   KC_S,   KC_D,    KC_F,    KC_G,   XXXXX,         XXXXX,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT_QTE,  \
  KC_LSFT,  KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,   KC_DEL,        KC_ENT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, \
  CTR_HOM,  KEEB,   KC_LGUI, KC_LALT, LT_LWR,         KC_BSPC,       KC_SPC, LT_RSE,           KC_BSLS, XXXXX,   XXXXX,   ALT_END \
),

/* LOWER
 */
[_LWR] = LAYOUT( \
  KC_ESC,  KC_PCMM, KC_P7,   KC_P8,   KC_P9,   KC_PAST, XXXXX,   XXXXX,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, \
  KC_NUM,  KC_PDOT, KC_P4,   KC_P5,   KC_P6,   KC_PSLS, XXXXX,   XXXXX,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  KC_PENT, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_EQL,  _______, KC_EXLM, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, \
  _______, _______,  _______, _______, _______,         _______, _______, _______,          _______, _______, _______, _______ \
),

/* RAISE
 */
[_RSE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,  XXXXX,   XXXXX,    KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______, \
  _______, _______, _______, _______, _______, _______,  XXXXX,   XXXXX,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, \
  _______, _______,  _______, _______, _______,          _______, _______,  _______,          _______, _______, _______, _______ \
),

/* ADJUST
 */
[_ADJ] = LAYOUT( \
  XXXXXXX, KC_VOLU, KC_F7, KC_F8,   KC_F9,   KC_F10,  XXXXX,   XXXXX,   KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_BRIU, XXXXXXX, \
  _______, KC_VOLD, KC_F4, KC_F5,   KC_F6,   KC_F11,  XXXXX,   XXXXX,   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BRID, _______, \
  XXXXXXX, KC_MUTE, KC_F1, KC_F2,   KC_F3,   KC_F12,  EE_CLR,  XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MFFD, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,       _______, _______, KC_BTN1,          KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX\
),

/* GAME
 */
[_GAME] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXX,   XXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXX,   XXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,         _______, _______, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX\
),
};
 
bool isQwertyActive = false;
static uint16_t key_timer;
bool no_other_key_pressed = true;

// layer_state_t currentLayer;

void LayerTap(int layer, uint16_t tapKeycode, int tapTerm, bool isTapFavored, keyrecord_t *record) {
  if (record->event.pressed) {
        // pressed
        layer_on(layer);
        key_timer = timer_read();
        no_other_key_pressed = true;
      } else {
        // released
        if (timer_elapsed(key_timer) < tapTerm) {
          // tapped
          if (no_other_key_pressed || isTapFavored) {
            tap_code16(tapKeycode);
          }
        } else {
          // held
        }
        key_timer = 0;
        layer_off(layer);
      }
}

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
      // LT(1, KC_MINS);
      LayerTap(1, KC_MINS, TAPPING_TERM, false, record);
      return false;

    case LT_RSE:
      // LT(2, S(KC_UNDS));
      LayerTap(2, S(KC_UNDS), TAPPING_TERM, false, record);
      return false;

    case LT_GRV:
      // LT(3, KC_GRV);
      LayerTap(3, KC_GRV, TAPPING_TERM, true, record);
      return false;

    case LT_QTE:
      // LT(3, KC_QUOT); 
      LayerTap(3, KC_QUOT, TAPPING_TERM, true, record); 
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
        no_other_key_pressed = false;
      } else {
        // released
      }
      return true; // Process all other keycodes
  }

  return true;
}
