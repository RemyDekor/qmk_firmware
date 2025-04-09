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
  KEEB,
  SET_WIN,
  SET_MAC,
  // TGL_KPD,
};
#define XXXXX KC_NO
#define _____ _______

// homerow mods
#define LSHFT_T MT(MOD_LSFT, KC_T)
#define RHSFT_N MT(MOD_RSFT, KC_N)
#define LGUI_A MT(MOD_LGUI, KC_A)
#define RGUI_O MT(MOD_RGUI, KC_O)
#define LALT_S MT(MOD_LALT, KC_S)
#define RALT_I MT(MOD_RALT, KC_I)
#define LCTL_R MT(MOD_LCTL, KC_R)
#define RCTL_E MT(MOD_RCTL, KC_E)
#define LCMCT_D MT(MOD_LCTL, KC_D) // duplicate of either CTRL or CMD (for left hand only shortcuts)
// qwerty-specific
#define LSHFT_F MT(MOD_LSFT, KC_F)
#define RSHFT_J MT(MOD_RSFT, KC_J)
#define RGUI_SCL MT(MOD_RGUI, KC_SCLN)
#define RALT_L MT(MOD_RALT, KC_L)
#define LCTL_D MT(MOD_LCTL, KC_D)
#define RCTL_K MT(MOD_RCTL, KC_K)
#define LCMCT_G MT(MOD_LCTL, KC_G) // duplicate of either CTRL or CMD (for left hand only shortcuts)

#define RSFT_ENT RSFT_T(KC_ENT)
#define LSFT_ENT LSFT_T(KC_ENT)
#define CTR_HOM LCTL_T(KC_HOME)
#define ALT_END ALGR_T(KC_END)
// #define SFT_ESC SFT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// COLEMAK // mutually exclusive with _QWERTY
[_COLEMAK] = LAYOUT(
//╭───────┬───────┬───────┬───────┬───────┬───────╮________       ________╭───────┬───────┬───────┬───────┬───────┬───────╮
//│  Tab  │   Q   │   W   │   F   │   P   │   G   │        │     │ XXXXX  │   J   │   L   │   U   │   Y   │   ;   │   =   │
   KC_TAB,  KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,    XXXXX,        XXXXX,  KC_J,   KC_L,   KC_U,   KC_Y,  KC_SCLN, KC_EQL,
//├───────┼───────┼───────┼───────┼───────┼───────┤________⎦     ⎣________├───────┼───────┼───────┼───────┼───────┼───────┤
//│   `   │   A   │   S   │   R   │   T   │   D   │ScrnShot│     │ XXXXX  │   H   │   N   │   E   │   I   │   O   │   '   │
   LT_GRV, LGUI_A, LALT_S, LCTL_R, LSHFT_T,LCMCT_D,    XXXXX,        XXXXX,   KC_H,  RHSFT_N, RCTL_E, RALT_I, RGUI_O, LT_QTE,
//├───────┼───────┼───────┼───────┼───────┼───────┤________⎦     ⎣________├───────┼───────┼───────┼───────┼───────┼───────┤
//│ LShEsc│   Z   │   X   │   C   │   V   │   B   │/  Del  /     \ Enter \│   K   │   M   │   ,   │   .   │   /   │ RShEnt│
  LSFT_ENT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_DEL,         KC_ENT,  KC_K,   KC_M, KC_COMM, KC_DOT, KC_SLSH,RSFT_ENT,
//├───────┼───────┼─────┬─┴─────┬─┴─────┬─┴──────/_______/         \_______\──────┴─┬─────┴─┬─────┴─┬─────┼───────┼───────┤
//│ LCTRL │  KEEB │     │ LGUI  │ LAlt  │  LWR  / BckSp  /         \  Space \  RSE  │   \   │       │     │       │ RALT  │
   CTR_HOM,  KEEB,      KC_LGUI, KC_LALT, LT_LWR, KC_BSPC,         KC_SPC,   LT_RSE, KC_BSLS, XXXXX,        XXXXX, ALT_END
//╰───────┴───────╯     ╰───────┴───────┴─────/________/             \________\─────┴───────┴───────╯     ╰───────┴───────╯
),

// QWERTY // mutually exclusive with _COLEMAK
[_QWERTY] = LAYOUT(
//╭───────┬───────┬───────┬───────┬───────┬───────╮________       ________╭───────┬───────┬───────┬───────┬───────┬───────╮
//│  Tab  │   Q   │   W   │   E   │   R   │   T   │        │     │ XXXXX  │   Y   │   U   │   I   │   O   │   P   │   =   │
   KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,    XXXXX,        XXXXX,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,  KC_EQL,
//├───────┼───────┼───────┼───────┼───────┼───────┤________⎦     ⎣________├───────┼───────┼───────┼───────┼───────┼───────┤
//│   `   │   A   │   S   │   D   │   F   │   G   │ScrnShot│     │ XXXXX  │   H   │   J   │   K   │   L   │   ;   │   '   │
   LT_GRV, LGUI_A, LALT_S, LCTL_D, LSHFT_F,LCMCT_G,    XXXXX,        XXXXX,   KC_H,  RSHFT_J,RCTL_K, RALT_L,RGUI_SCL, LT_QTE,
//├───────┼───────┼───────┼───────┼───────┼───────┤________⎦     ⎣________├───────┼───────┼───────┼───────┼───────┼───────┤
//│ LShEsc│   Z   │   X   │   C   │   V   │   B   │/  Del  /     \ Enter \│   N   │   M   │   ,   │   .   │   /   │ RShEnt│
  LSFT_ENT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_DEL,         KC_ENT,  KC_N,   KC_M, KC_COMM, KC_DOT, KC_SLSH,RSFT_ENT,
//├───────┼───────┼─────┬─┴─────┬─┴─────┬─┴──────/_______/         \_______\──────┴─┬─────┴─┬─────┴─┬─────┼───────┼───────┤
//│ LCTRL │  KEEB │     │ LGUI  │ LAlt  │  LWR  / BckSp  /         \  Space \  RSE  │   \   │       │     │       │ RALT  │
   CTR_HOM,  KEEB,      KC_LGUI, KC_LALT, LT_LWR, KC_BSPC,         KC_SPC,   LT_RSE, KC_BSLS, XXXXX,        XXXXX, ALT_END
//╰───────┴───────╯     ╰───────┴───────┴─────/________/             \________\─────┴───────┴───────╯     ╰───────┴───────╯
),

// LOWER
[_LWR] = LAYOUT(
//╭───────┬───────┬───────┬───────┬───────┬───────╮________       ________╭───────┬───────┬───────┬───────┬───────┬───────╮
//│  Esc  │   ,   │   7   │   8   │   9   │   *   │        │     │ XXXXX  │       │   @   │   #   │   $   │   %   │       │
   KC_ESC, KC_PCMM, KC_P7,  KC_P8,  KC_P9, KC_PAST,  XXXXX,        XXXXX,   XXXXX,  KC_AT, KC_HASH, KC_DLR,KC_PERC, _____,
//├───────┼───────┼───────┼───────┼───────┼───────┤________⎦     ⎣________├───────┼───────┼───────┼───────┼───────┼───────┤
//│ NumPad│   .   │   4   │   5   │   6   │   /   │ScrnShot│     │ XXXXX  │   ^   │   &   │   *   │   (   │   )   │       │
   KC_NUM, KC_PDOT, KC_P4,  KC_P5,  KC_P6, KC_PSLS,  XXXXX,        XXXXX,  KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN, _____,
//├───────┼───────┼───────┼───────┼───────┼───────┤________⎦     ⎣________├───────┼───────┼───────┼───────┼───────┼───────┤
//│ KEnter│   0   │   1   │   2   │   3   │   +   │/   =   /     \ Enter \│   !   │   [   │   ]   │   {   │   }   │       │
   KC_PENT, KC_P0,  KC_P1,  KC_P2,  KC_P3, KC_PPLS, KC_EQL,         _____, KC_EXLM,KC_LBRC,KC_RBRC,KC_LCBR,KC_RCBR, _____,
//├───────┼───────┼─────┬─┴─────┬─┴─────┬─┴──────/_______/         \_______\──────┴─┬─────┴─┬─────┴─┬─────┼───────┼───────┤
//│       │       │     │       │       │🁢🁢🁢🁢🁢🁢🁢🁢/        /         \        \       │       │       │     │       │       │
    _____,  _____,        _____,  _____, _____,  _____,               _____,   _____, _____,  _____,        _____,  _____
//╰───────┴───────╯     ╰───────┴───────┴─────/________/             \________\─────┴───────┴───────╯     ╰───────┴───────╯
),

// RAISE
[_RSE] = LAYOUT(
//╭───────┬───────┬───────┬───────┬───────┬───────╮________       ________╭───────┬───────┬───────┬───────┬───────┬───────╮
//│       │       │       │       │       │       │        │     │        │   ⇞   │   ⇤   │   ⬆️   │   ⇥   │       │       │
    _____,  _____,  _____,  _____,  _____,  _____,   XXXXX,        XXXXX,  KC_PGUP,KC_HOME, KC_UP,  KC_END, _____,  _____,
//├───────┼───────┼───────┼───────┼───────┼───────┤________⎦     ⎣________├───────┼───────┼───────┼───────┼───────┼───────┤
//│       │       │       │       │       │       │        │     │        │   ⇟   │   ⬅️   │   ⬇️   │   ➡️   │       │       │
    _____,  _____,  _____,  _____,  _____,  _____,   XXXXX,        XXXXX,  KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT, _____,  _____,
//├───────┼───────┼───────┼───────┼───────┼───────┤________⎦     ⎣________├───────┼───────┼───────┼───────┼───────┼───────┤
//│       │       │       │       │       │       │/       /     \       \│       │   ⏮  │   ⏯  │   ⏭  │       │       │
    _____,  _____,  _____,  _____,  _____,  _____,  _____,          _____,  _____, KC_MRWD,KC_MPLY,KC_MFFD, _____,  _____,
//├───────┼───────┼─────┬─┴─────┬─┴─────┬─┴──────/_______/         \_______\──────┴─┬─────┴─┬─────┴─┬─────┼───────┼───────┤
//│       │       │     │       │       │       /        /         \        \🁢🁢🁢🁢🁢🁢🁢🁢│       │       │     │       │       │
    _____,  _____,        _____,  _____, _____,  _____,               _____,   _____, _____,  _____,        _____,  _____
//╰───────┴───────╯     ╰───────┴───────┴─────/________/             \________\─────┴───────┴───────╯     ╰───────┴───────╯
),

// ADJUST
[_ADJ] = LAYOUT(
//╭───────┬───────┬───────┬───────┬───────┬───────╮________       ________╭───────┬───────┬───────┬───────┬───────┬───────╮
//│  Esc  │ vol + │   F7  │   F8  │   F9  │  F10  │        │     │        │Scroll⬆️│Scroll⬅️│  Mse⬆️ │Scroll➡️│Bright+│       │
    XXXXX, KC_VOLU, KC_F7,  KC_F8,  KC_F9,  KC_F10,  XXXXX,        XXXXX,  KC_WH_U,KC_WH_L,KC_MS_U,KC_WH_R,KC_BRIU, XXXXX,
//├───────┼───────┼───────┼───────┼───────┼───────┤________⎦     ⎣________├───────┼───────┼───────┼───────┼───────┼───────┤
//│🁢🁢🁢🁢🁢🁢🁢🁢│ vol - │   F4  │   F5  │   F6  │  F11  │        │     │        │Scroll⬇️│  Mse⬅️ │  Mse⬇️ │  Mse➡️ │Bright-│🁢🁢🁢🁢🁢🁢🁢🁢│
    _____, KC_VOLD, KC_F4,  KC_F5,  KC_F6,  KC_F11,  XXXXX,        XXXXX,  KC_WH_D,KC_MS_L,KC_MS_D,KC_MS_R,KC_BRID, _____,
//├───────┼───────┼───────┼───────┼───────┼───────┤________⎦     ⎣________├───────┼───────┼───────┼───────┼───────┼───────┤
//│       │  Mute │   F1  │   F2  │   F3  │  F12  │/       /     \       \│       │   ⏮  │   ⏯  │   ⏭  │       │       │
    XXXXX, KC_MUTE, KC_F1,  KC_F2,  KC_F3,  KC_F12, EE_CLR,        XXXXX,   XXXXX, KC_MPRV,KC_MPLY,KC_MFFD, XXXXX,  XXXXX,
//├───────┼───────┼─────┬─┴─────┬─┴─────┬─┴──────/_______/         \_______\──────┴─┬─────┴─┬─────┴─┬─────┼───────┼───────┤
//│       │       │     │       │       │       /        /         \        \MseBtn1│MseBtn2│MseBtn3│     │       │       │
    XXXXX,  XXXXX,       SET_WIN,SET_MAC, XXXXX,  _____,               _____, KC_BTN1,KC_BTN2,KC_BTN3,       XXXXX,  XXXXX
//╰───────┴───────╯     ╰───────┴───────┴─────/________/             \________\─────┴───────┴───────╯     ╰───────┴───────╯
),

// GAME
[_GAME] = LAYOUT( // TODO
//╭───────┬───────┬───────┬───────┬───────┬───────╮________       ________╭───────┬───────┬───────┬───────┬───────┬───────╮
//│       │       │       │       │       │       │        │     │        │       │       │       │       │       │       │
    XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,   XXXXX,        XXXXX,   XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,
//├───────┼───────┼───────┼───────┼───────┼───────┤________⎦     ⎣________├───────┼───────┼───────┼───────┼───────┼───────┤
//│       │       │       │       │       │       │        │     │        │       │       │       │       │       │       │
    XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,   XXXXX,        XXXXX,   XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,
//├───────┼───────┼───────┼───────┼───────┼───────┤________⎦     ⎣________├───────┼───────┼───────┼───────┼───────┼───────┤
//│       │       │       │       │       │       │/       /     \       \│       │       │       │       │       │       │
    XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,   XXXXX,        XXXXX,   XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,
//├───────┼───────┼─────┬─┴─────┬─┴─────┬─┴──────/_______/         \_______\──────┴─┬─────┴─┬─────┴─┬─────┼───────┼───────┤
//│       │       │     │       │       │       /        /         \        \       │       │       │     │       │       │
    XXXXX,  XXXXX,        XXXXX,  XXXXX, XXXXX,  _____,               _____,  XXXXX,  XXXXX,  XXXXX,        XXXXX,  XXXXX
//╰───────┴───────╯     ╰───────┴───────┴─────/________/             \________\─────┴───────┴───────╯     ╰───────┴───────╯
),
};

bool isQwertyActive = false;
bool isMacOs = false;
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

void sendKeyCode16(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // pressed
        register_code16(keycode);
    } else {
        // released
        unregister_code16(keycode);
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
        // LT(1, KC_TAB);
        LayerTap(1, KC_TAB, TAPPING_TERM, false, record);
        return false;

    case LT_RSE:
        // LT(2, S(KC_MINS));
        LayerTap(2, KC_MINS, TAPPING_TERM, false, record);
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
        if (record->event.pressed) {
            isQwertyActive = !isQwertyActive;
            layer_on(isQwertyActive ? _QWERTY : _COLEMAK);
            layer_off(isQwertyActive ? _COLEMAK : _QWERTY);
        }
        return false;

    case SET_WIN:
        isMacOs = false;
        return false;

    case SET_MAC:
        isMacOs = true;
        return false;

    case KC_LALT:
        if (isMacOs) {
            sendKeyCode16(KC_LGUI, record);
            return false;
        }
        return true;

    case KC_LGUI:
        if (isMacOs) {
            sendKeyCode16(KC_LALT, record);
            return false;
        }
        return true;

    case LCMCT_D:
        if (isMacOs) {
            sendKeyCode16(MT(MOD_LGUI, KC_D), record);
            return false;
        }
        return true;

    case LCMCT_G:
        if (isMacOs) {
            sendKeyCode16(MT(MOD_LGUI, KC_G), record);
            return false;
        }
        return true;


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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCMCT_D:
        case LCMCT_G:
            return TAPPING_TERM + 30;
        case LGUI_A:
        case RGUI_O:
        case RGUI_SCL:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}
