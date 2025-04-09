#include QMK_KEYBOARD_H

#define _COLEMAK 0 // default base layer
#define _QWERTY 1 // can be base layer (not stored in EEPROM) => usefull for photoshop etc.
#define _MAC 2 //
#define _GAME 3 // can toggle ON / OFF
#define _LWR 4 // Lower
#define _RSE 5 // Raise
#define _ADJ 6 // Adjust // TODO: split left and right hand ?

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

// layer-taps / mod-taps
#define FUNC_Z LT(_ADJ, KC_Z)
#define ADJ_SL LT(_ADJ, KC_SLSH)

#define LCTL_ENT MT(MOD_LCTL, KC_ENT)

// alpha mod-taps
#define LSHFT_A MT(MOD_LSFT, KC_A)
#define LCTL_X MT(MOD_LCTL, KC_X)
#define LGUI_C MT(MOD_LGUI, KC_C)
#define LALT_V MT(MOD_LALT, KC_V)
#define LCTL_B MT(MOD_LCTL, KC_B) // duplicate of either CTRL or CMD (for left hand only)

#define RSFT_O MT(MOD_RSFT, KC_O)
#define RALT_M MT(MOD_RALT, KC_M)
#define RGUI_COM MT(MOD_RGUI, KC_COMM)
#define RCTL_DOT MT(MOD_RCTL, KC_DOT)

// mac  specific
#define LCMD_ENT MT(MOD_LGUI, KC_ENT)

#define LCMD_X MT(MOD_LGUI, KC_X)
#define LALT_C MT(MOD_LALT, KC_C)
#define LCTL_V MT(MOD_LCTL, KC_V)
#define LCMD_B MT(MOD_LGUI, KC_B) // duplicate of either CTRL or CMD (for left hand only)

#define RCTL_M MT(MOD_RCTL, KC_M)
#define RALT_COM MT(MOD_RALT, KC_COMM)
#define RCMD_DOT MT(MOD_RGUI, KC_DOT)


// qwerty-specific
#define RSFT_SCL MT(MOD_RSFT, KC_SCLN)

#define RSFT_ENT RSFT_T(KC_ENT)
#define LSFT_ENT LSFT_T(KC_ENT)
#define CTR_HOM LCTL_T(KC_HOME)
#define ALT_END ALGR_T(KC_END)
// #define SFT_ESC SFT_T(KC_ESC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// COLEMAK // mutually exclusive with _QWERTY
[_COLEMAK] = LAYOUT(
//╭───────┬───────┬───────┬───────┬───────╮                                        ╭───────┬───────┬───────┬───────┬───────╮
//│   Q   │   W   │   F   │   P   │   G   │                                        │   J   │   L   │   U   │   Y   │   ;   │
    KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,                                            KC_J,   KC_L,   KC_U,   KC_Y,  KC_SCLN,
//├───────┼───────┼───────┼───────┼───────┤                                        ├───────┼───────┼───────┼───────┼───────┤
//│   A   │   S   │   R   │   T   │   D   │                                        │   H   │   N   │   E   │   I   │   O   │
   LSHFT_A, KC_S,   KC_R,   KC_T,   KC_D,                                            KC_H,   KC_N,   KC_E,   KC_I,  RSFT_O,
//├───────┼───────┼───────┼───────┼───────┤                                        ├───────┼───────┼───────┼───────┼───────┤
//│   Z   │   X   │   C   │   V   │   B   │                                        │   K   │   M   │   ,   │   .   │   /   │
   FUNC_Z, LCTL_X, LGUI_C, LALT_V, LCTL_B,                                           KC_K, RALT_M,RGUI_COM,RCTL_DOT,ADJ_SL,
//╰───────┴───────┴───────┴───────┴───────╯                                        ╰───────┴───────┴───────┴───────┴───────╯
//              ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮    ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮
//              │       │ │  LWR  │ BckSp │Ctl|Ent│ │       │    │       │ │   \   │ Space │  RSE  │ │       │
                  KC_1,    LT_LWR,KC_BSPC,LCTL_ENT,   KC_2,        KC_3,    KC_BSLS,KC_SPC, LT_RSE,     KC_4
//              ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯    ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯
),

// QWERTY // mutually exclusive with _COLEMAK
[_QWERTY] = LAYOUT(
//╭───────┬───────┬───────┬───────┬───────╮                                        ╭───────┬───────┬───────┬───────┬───────╮
//│   Q   │   W   │   E   │   R   │   T   │                                        │   Y   │   U   │   I   │   O   │   P   │
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                            KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,
//├───────┼───────┼───────┼───────┼───────┤                                        ├───────┼───────┼───────┼───────┼───────┤
//│   A   │   S   │   D   │   F   │   G   │                                        │   H   │   J   │   K   │   L   │   ;   │
   LSHFT_A, KC_S,   KC_D,   KC_F,   KC_G,                                            KC_H,   KC_H,   KC_K,   KC_L, RSFT_SCL,
//├───────┼───────┼───────┼───────┼───────┤                                        ├───────┼───────┼───────┼───────┼───────┤
//│   Z   │   X   │   C   │   V   │   B   │                                        │   N   │   M   │   ,   │   .   │   /   │
   FUNC_Z, LCTL_X, LGUI_C, LALT_V, LCTL_B,                                           KC_N, RALT_M,RGUI_COM,RCTL_DOT,ADJ_SL,
//╰───────┴───────┴───────┴───────┴───────╯                                        ╰───────┴───────┴───────┴───────┴───────╯
//              ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮    ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮
//              │       │ │  LWR  │ BckSp │Ctl|Ent│ │       │    │       │ │   \   │ Space │  RSE  │ │       │
                  KC_1,    LT_LWR,KC_BSPC,LCTL_ENT,   KC_2,        KC_3,    KC_BSLS,KC_SPC, LT_RSE,     KC_4
//              ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯    ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯
),

[_MAC] = LAYOUT(
//╭───────┬───────┬───────┬───────┬───────╮                                        ╭───────┬───────┬───────┬───────┬───────╮
//│       │       │       │       │       │                                        │       │       │       │       │       │
    _____,  _____,  _____,  _____,  _____,                                           _____,  _____,  _____,  _____,  _____,
//├───────┼───────┼───────┼───────┼───────┤                                        ├───────┼───────┼───────┼───────┼───────┼
//│       │       │       │       │       │                                        │       │       │       │       │       │
    _____,  _____,  _____,  _____,  _____,                                           _____,  _____,  _____,  _____,  _____,
//├───────┼───────┼───────┼───────┼───────┤                                        ├───────┼───────┼───────┼───────┼───────┼
//│       │       │       │       │       │                                        │       │       │       │       │       │
    _____, LCMD_X, LALT_C, LCTL_V, LCMD_B,                                           _____, RCTL_M,RALT_COM,RCMD_DOT,_____,
//╰───────┴───────┴───────┴───────┴───────╯                                        ╰───────┴───────┴───────┴───────┴───────╯
//              ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮    ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮
//              │       │ │       │       │       │ │       │    │       │ │       │       │       │ │       │
                  KC_1,     _____,  _____,  _____,    KC_2,        KC_3,     _____,  _____,  _____,     KC_4
//              ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯    ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯
),

// LOWER
[_LWR] = LAYOUT(
//╭───────┬───────┬───────┬───────┬───────╮                                        ╭───────┬───────┬───────┬───────┬───────╮
//│  Esc  │   7   │   8   │   9   │   -   │                                        │       │   @   │   #   │   $   │   %   │
   KC_ESC,  KC_P7,  KC_P8,  KC_P9, KC_MINS,                                          XXXXX,  KC_AT, KC_HASH, KC_DLR,KC_PERC,
//├───────┼───────┼───────┼───────┼───────┤                                        ├───────┼───────┼───────┼───────┼───────┼
//│   .   │   4   │   5   │   6   │   +   │                                        │   ^   │   &   │   *   │   (   │   )   │
   KC_PDOT, KC_P4,  KC_P5,  KC_P6, KC_PPLS,                                         KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,
//├───────┼───────┼───────┼───────┼───────┤                                        ├───────┼───────┼───────┼───────┼───────┼
//│   0   │   1   │   2   │   3   │   =   │                                        │   !   │   [   │   ]   │   {   │   }   │
    KC_P0,  KC_P1,  KC_P2,  KC_P3,  KC_EQL,                                         KC_EXLM,KC_LBRC,KC_RBRC,KC_LCBR,KC_RCBR,
//╰───────┴───────┴───────┴───────┴───────╯                                        ╰───────┴───────┴───────┴───────┴───────╯
//              ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮    ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮
//              │       │ │🁢🁢🁢🁢🁢🁢🁢🁢│  Del  │       │ │       │    │       │ │       │       │       │ │       │
                  KC_1,     _____, KC_DEL,   _____,   KC_2,        KC_3,     _____,  _____,  _____,     KC_4
//              ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯    ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯
),

// RAISE
[_RSE] = LAYOUT(
//╭───────┬───────┬───────┬───────┬───────╮                                      ╭───────┬───────┬───────┬───────┬───────╮
//│       │       │       │       │       │                                      │   ⇞   │   ⇤   │   ⬆️   │   ⇥   │       │
    _____,  _____,  _____,  _____,  _____,                                        KC_PGUP,KC_HOME, KC_UP,  KC_END, _____,
//├───────┼───────┼───────┼───────┼───────┤                                      ├───────┼───────┼───────┼───────┼───────┼
//│       │       │       │       │       │                                      │   ⇟   │   ⬅️   │   ⬇️   │   ➡️   │
    _____,  _____,  _____,  _____,  _____,                                        KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT, _____,
//├───────┼───────┼───────┼───────┼───────┤                                      ├───────┼───────┼───────┼───────┼───────┼
//│       │       │       │       │       │                                      │       │   ⏮  │   ⏯  │   ⏭  │       │
    _____,  _____,  _____,  _____,  _____,                                         _____, KC_MRWD,KC_MPLY,KC_MFFD, _____,
//╰───────┴───────┴───────┴───────┴───────╯                                      ╰───────┴───────┴───────┴───────┴───────╯
//              ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮  ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮
//              │       │ │       │       │       │ │       │  │       │ │       │       │🁢🁢🁢🁢🁢🁢🁢🁢│ │       │
                  _____,    _____,  _____,  _____,    _____,     _____,    _____,  _____,  _____,    _____
//              ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯  ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯
),

// ADJUST
[_ADJ] = LAYOUT(
//╭───────┬───────┬───────┬───────┬───────╮                                      ╭───────┬───────┬───────┬───────┬───────╮
//│ vol + │   F7  │   F8  │   F9  │  F10  │                                      │Scroll⬆️│Scroll⬅️│  Mse⬆️ │Scroll➡️│Bright+
   KC_VOLU, KC_F7,  KC_F8,  KC_F9,  KC_F10,                                       KC_WH_U,KC_WH_L,KC_MS_U,KC_WH_R,KC_BRIU,
//├───────┼───────┼───────┼───────┼───────┤                                      ├───────┼───────┼───────┼───────┼───────┼
//│ vol - │   F4  │   F5  │   F6  │  F11                                         │Scroll⬇️│  Mse⬅️ │  Mse⬇️ │  Mse➡️ │Bright-
   KC_VOLD, KC_F4,  KC_F5,  KC_F6,  KC_F11,                                       KC_WH_D,KC_MS_L,KC_MS_D,KC_MS_R,KC_BRID,
//├───────┼───────┼───────┼───────┼───────┤                                      ├───────┼───────┼───────┼───────┼───────┼
//│  Mute │   F1  │   F2  │   F3  │  F12  │                                      │       │   ⏮  │   ⏯   │   ⏭  │       │
   KC_MUTE, KC_F1,  KC_F2,  KC_F3,  KC_F12,                                        XXXXX, KC_MPRV,KC_MPLY,KC_MFFD, XXXXX,
//╰───────┴───────┴───────┴───────┴───────╯                                      ╰───────┴───────┴───────┴───────┴───────╯
//              ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮  ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮
//        │       │     │       │       │       /        /  \        \MseBtn1│MseBtn2│MseBtn3│     │       │
            XXXXX,        XXXXX,TG(_MAC), XXXXX,  KEEB,        _____, KC_BTN1,KC_BTN2,KC_BTN3,       XXXXX
//              ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯  ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯
),

// GAME
[_GAME] = LAYOUT( // TODO
//┬───────┬───────┬───────┬───────┬───────╮                                      ╭───────┬───────┬───────┬───────┬───────╮
//│       │       │       │       │       │                                      │       │       │       │       │       │
    XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,                                         XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,
//┼───────┼───────┼───────┼───────┼───────┤                                      ├───────┼───────┼───────┼───────┼───────┼
//│       │       │       │       │       │                                      │       │       │       │       │       │
    XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,                                         XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,
//┼───────┼───────┼───────┼───────┼───────┤                                      ├───────┼───────┼───────┼───────┼───────┼
//│       │       │       │       │       │                                      │       │       │       │       │       │
    XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,                                         XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,
//╰───────┴───────┴───────┴───────┴───────╯                                      ╰───────┴───────┴───────┴───────┴───────╯
//              ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮  ╭───────╮ ╭───────┬───────┬───────╮ ╭───────╮
//              │       │ │       │       │       │ │       │  │       │ │       │       │       │ │       │
                  XXXXX,    XXXXX,  XXXXX,  XXXXX,    _____,     _____,    XXXXX,  XXXXX,  XXXXX,    XXXXX
//              ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯  ╰───────╯ ╰───────┴───────┴───────╯ ╰───────╯
)};

enum combos {
  A_S_GRV,
  O_I_QUOT,
  SC_L_QUT, // qwerty
  T_D_ENT,
  F_G_ENT, // qwerty
  H_N_BSLS,
  H_J_BSLS, // qwerty
};

const uint16_t PROGMEM a_s_grv[] = { LSHFT_A, KC_S, COMBO_END};
const uint16_t PROGMEM o_i_quot[] = { RSFT_O, KC_I, COMBO_END};
const uint16_t PROGMEM sc_l_quot[] = { KC_SCLN, KC_L, COMBO_END};
const uint16_t PROGMEM t_d_ent[] = { KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM f_g_ent[] = { KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM h_n_bsls[] = { KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM h_j_bsls[] = { KC_H, KC_J, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [A_S_GRV] = COMBO(a_s_grv, KC_GRV),
  [O_I_QUOT] = COMBO(o_i_quot, KC_QUOT),
  [SC_L_QUT] = COMBO(sc_l_quot, KC_QUOT),
  [T_D_ENT] = COMBO(t_d_ent, KC_ENT),
  [F_G_ENT] = COMBO(f_g_ent, KC_ENT),
  [H_N_BSLS] = COMBO(h_n_bsls, KC_BSLS),
  [H_J_BSLS] = COMBO(h_j_bsls, KC_BSLS),
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
        LayerTap(_LWR, KC_TAB, TAPPING_TERM, false, record);
        return false;

    case LT_RSE:
        // LT(2, S(KC_MINS));
        LayerTap(_RSE, KC_MINS, TAPPING_TERM, false, record);
        return false;

    case LT_GRV:
        // LT(3, KC_GRV);
        LayerTap(_ADJ, KC_GRV, TAPPING_TERM, true, record);
        return false;

    case LT_QTE:
        // LT(3, KC_QUOT);
        LayerTap(6, KC_QUOT, TAPPING_TERM, true, record);
        return false;

    case KEEB:
        if (record->event.pressed) {
            isQwertyActive = !isQwertyActive;
            layer_on(isQwertyActive ? _QWERTY : _COLEMAK);
            layer_off(isQwertyActive ? _COLEMAK : _QWERTY);
        }
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_X:
        case LT_RSE:
        case LT_LWR:
        case LCTL_ENT:
        case LCMD_ENT:
            return TAPPING_TERM - 40;
        // case LCTCM_D:
        // case LCTCM_G:
        //     return TAPPING_TERM + 15;
        case LSHFT_A:
            return TAPPING_TERM + 5;
        case RSFT_O:
        case RSFT_SCL:
            return TAPPING_TERM + 20;
        default:
            return TAPPING_TERM;
    }
}
