#include QMK_KEYBOARD_H
/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(             // 0
    KC_TAB,       KC_Q,				  KC_W,				  KC_E,				  KC_R,				  KC_T,				          KC_Y,				  KC_U,				  KC_I,				  KC_O,				  KC_P,               KC_MINS,
    KC_LCTL,      LGUI_T(KC_A), LALT_T(KC_S),	LCTL_T(KC_D),	LSFT_T(KC_F), KC_G,				          KC_H,				  RSFT_T(KC_J), RCTL_T(KC_K),	RALT_T(KC_L),	RGUI_T(KC_QUOT),    KC_SCLN,
    KC_LSFT,      LT(2,KC_Z),	  KC_X,				  KC_C,				  KC_V,				  KC_B,				          KC_N,				  KC_M,				  KC_COMM,			KC_DOT,			  LT(4,KC_SLSH),KC_ESC,
                                              KC_NO,       LALT_T(KC_DEL),LT(1,KC_BSPC),        LT(2,KC_SPC),RGUI_T(KC_ENT),KC_NO
  ),
  [1] = LAYOUT(           // 1
    KC_F1,        KC_F2,			  KC_F3,        KC_F4,			  KC_F5,         KC_F6,			          KC_F7,			  KC_F8,			  KC_F9,			  KC_F10,       KC_F11,       KC_F12,
    KC_LCTL,      KC_EXLM,		  KC_AT,			  KC_HASH,			KC_DLR,			   KC_PERC,			        KC_CIRC,			KC_AMPR,			KC_ASTR,			KC_LPRN,			KC_RPRN,      TO(4),
    KC_LSFT,      KC_PSCR,			TO(2),        KC_MPLY,			DM_PLY2,       DM_PLY1,	            KC_TILD,			KC_UNDS,			KC_PLUS,			KC_LBRC,			KC_RBRC,      KC_PIPE,
                                              KC_NO,        KC_TRNS,       KC_TRNS,             MO(3),        CW_TOGG,      KC_NO
  ),
  [2] = LAYOUT(           // 2
    KC_TAB,       KC_1,				  KC_2,				  KC_3,				  KC_4,				  KC_5,				          KC_6,         KC_7,				  KC_8,				  KC_9,				  KC_0,         KC_BSPC,
    KC_LCTL,      KC_MPRV,			KC_MUTE,			KC_MNXT,			KC_PGUP,			KC_HOME,			        LCA(KC_L),    KC_LEFT,			KC_DOWN,			KC_UP,			  KC_RGHT,      TO(4),
    KC_LSFT,      DT_DOWN,			DT_PRNT,			DT_UP,        KC_PGDN,			KC_END,			          KC_GRV,       KC_MINS,			KC_EQL,			  KC_LCBR,			KC_RCBR,      KC_BSLS,
                                              KC_NO,        CW_TOGG,      MO(3),                KC_TRNS,      TO(0),        KC_NO
  ),
  [3] = LAYOUT(           // 3
    QK_BOOT,			KC_F13,       KC_F14,       KC_F15,			  KC_F16,       KC_INS,			          DM_REC1,      DM_REC2,      DM_RSTP,	    KC_NO,        KC_NO,			  QK_BOOT,
    KC_CAPS,			KC_F17,			  KC_F18,			  KC_F19,			  KC_F20,       KC_PAUS,			        RGB_M_P,      RGB_MOD,      RGB_SPI,	    RGB_HUI,			RGB_SAI,      RGB_VAI,
    KC_SLEP,			KC_F21,			  KC_F22,			  KC_F23,			  KC_F24,       KC_SCRL,			        RGB_TOG,      RGB_RMOD,     RGB_SPD,      RGB_HUD,      RGB_SAD,      RGB_VAD,
                                              KC_NO,        KC_TRNS,      KC_TRNS,              KC_TRNS,      KC_TRNS,      KC_NO
  ),
  [4] = LAYOUT(           // 5
    TO(0),			  KC_TAB,			  KC_BTN2,			KC_MS_U,      KC_BTN1,      KC_NUM,			          KC_PSLS,			KC_P7,			  KC_P8,			  KC_P9,			  KC_PMNS,      KC_BSPC,
    KC_NO,			  KC_RCTL,			KC_MS_L,			KC_MS_D,			KC_MS_R,			KC_WH_U,			        KC_PAST,      KC_P4,			  KC_P5,			  KC_P6,			  KC_PPLS,      TO(0),
    KC_NO,			  KC_RSFT,			KC_WH_L,			KC_BTN3,			KC_WH_R,      KC_WH_D,			        KC_P0,        KC_P1,			  KC_P2,			  KC_P3,			  KC_PENT,      KC_PEQL,
                                              KC_NO,       RALT_T(KC_DEL),KC_BTN1,              KC_RALT,      KC_PDOT,      KC_NO
  )
};
*/
 
/*
// ----- MACROS ----- //
enum custom_keycodes {
    NEXTSEN = SAFE_RANGE,
    SRCHSEL
};
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case NEXTSEN:  // Next sentence macro.
      if (record->event.pressed) {
        SEND_STRING(". ");
        add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
      }
      return false;
    case SRCHSEL:  // Searches the current selection in a new tab.
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("ct") SS_DELAY(100) SS_LCTL("v") SS_TAP(X_ENTER));
      }
      return false;
  }
  return true;
}
*/

// ----- COMBOS ----- //
const uint16_t PROGMEM combo_LCBR[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_RCBR[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_LPRN[] = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM combo_RPRN[] = {RCTL_T(KC_K), RALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM combo_LBRC[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_RBRC[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_MPRV[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_MNXT[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_MINS[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_UNDS[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM combo_SCLN[] = {RALT_T(KC_L), RGUI_T(KC_QUOT), COMBO_END};
const uint16_t PROGMEM combo_COLN[] = {KC_DOT, LT(_NUMPAD,KC_SLSH), COMBO_END};
const uint16_t PROGMEM combo_UNDO[] = {LT(2,KC_Z), KC_X, COMBO_END};
const uint16_t PROGMEM combo_COPY[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_PSTE[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_LCBR, KC_LCBR),
    COMBO(combo_RCBR, KC_RCBR),
    COMBO(combo_LPRN, KC_LPRN),
    COMBO(combo_RPRN, KC_RPRN),
    COMBO(combo_LBRC, KC_LBRC),
    COMBO(combo_RBRC, KC_RBRC),
    COMBO(combo_MPRV, KC_MPRV),
    COMBO(combo_MNXT, KC_MNXT),
    COMBO(combo_MINS, KC_MINS),
    COMBO(combo_UNDS, KC_UNDS),
    COMBO(combo_SCLN, KC_SCLN),
    COMBO(combo_COLN, KC_COLN),
    COMBO(combo_UNDO, LCTL(KC_Z)),
    COMBO(combo_COPY, LCTL(KC_C)),
    COMBO(combo_PSTE, LCTL(KC_V))
};