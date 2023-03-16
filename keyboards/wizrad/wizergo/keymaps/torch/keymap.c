#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _FUNSYM,
  _NUMNAV,
  _ADJUST,
  _EXTRAS,
  _NUMPAD,
  _GAMING
};

enum custom_keycodes {
    NEXTSEN = SAFE_RANGE,
    SRCHSEL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │                     │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤                     ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │                     │ H │ J │ K │ L │ ' │
      * ├───┼───┼───┼───┼───┤                     ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │                     │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘                     └───┴───┴───┴───┴───┘
      *           ┌───┐                                 ┌───┐
      *           │Tab├───┐                         ┌───┤Esc│
      *           └───┤Del├───┐ ┌───┐     ┌───┐ ┌───┤Ent├───┘
      *               └───┤Bsp│ │NXT│     │PLY│ │Spc├───┘
      *                   └───┘ └───┘     └───┘ └───┘
      */
  [_BASE] = LAYOUT(             // 0
    KC_Q,				  KC_W,				  KC_E,				  KC_R,				  KC_T,				      KC_Y,				  KC_U,				  KC_I,				  KC_O,				  KC_P,
    KC_A,				  LALT_T(KC_S),	LCTL_T(KC_D),	LSFT_T(KC_F), KC_G,				      KC_H,				  RSFT_T(KC_J), RCTL_T(KC_K),	RALT_T(KC_L),	KC_QUOT,
    LT(2,KC_Z),	  KC_X,				  KC_C,				  KC_V,				  KC_B,				      KC_N,				  KC_M,				  KC_COMM,			KC_DOT,			  LT(_NUMPAD,KC_SLSH),
                  LGUI_T(KC_TAB),LT(4,KC_DEL),LT(1,KC_BSPC),TO(_NUMPAD),      KC_MPLY,			LT(2,KC_SPC),	LT(4,KC_ENT),	RGUI_T(KC_ESC)
  ),
  [_FUNSYM] = LAYOUT(           // 1
    KC_F2,			  KC_F3,        KC_F4,			  KC_F5,        KC_F6,			      KC_F7,			  KC_F8,			  KC_F9,			  KC_F10,			  KC_F11,
    KC_EXLM,		  KC_AT,			  KC_HASH,			KC_DLR,			  KC_PERC,			    KC_CIRC,			KC_AMPR,			KC_ASTR,			KC_LPRN,			KC_RPRN,
    KC_F1,			  KC_F12,       KC_PIPE,			DM_PLY2,      DM_PLY1,	        KC_TILD,			KC_UNDS,			KC_PLUS,			KC_LBRC,			KC_RBRC,
                  TO(_BASE),    TO(5),			  KC_TRNS,			KC_TRNS,          KC_TRNS,      MO(3),			  CW_TOGG,			KC_TRNS
  ),
  [_NUMNAV] = LAYOUT(           // 2
    KC_1,				  KC_2,				  KC_3,				  KC_4,				  KC_5,				      KC_6,				  KC_7,				  KC_8,				  KC_9,				  KC_0,
    KC_LCTL,			KC_LCBR,			KC_RCBR,			KC_PGUP,			KC_HOME,			    KC_BSLS,			KC_LEFT,			KC_DOWN,			KC_UP,			  KC_RGHT,
    KC_LSFT,			KC_LBRC,			KC_RBRC,			KC_PGDN,			KC_END,			      KC_GRV,			  KC_MINS,			KC_EQL,			  KC_COLN,			KC_SCLN,
                  KC_TRNS,			CW_TOGG,			MO(3),			  KC_TRNS,          KC_TRNS,      KC_TRNS,			TO(5),			  TO(_BASE)
  ),
  [_ADJUST] = LAYOUT(           // 3
    QK_BOOT,			KC_F13,       KC_F14,       KC_F15,			  KC_INS,			      DM_REC1,	    DM_REC2,      DM_RSTP,	    KC_NO,			  QK_BOOT,
    KC_CAPS,			KC_F16,			  KC_F17,			  KC_F18,			  KC_PAUS,			    DT_DOWN,	    DT_UP,		    DT_PRNT,	    KC_LCBR,			KC_RCBR,
    KC_SLEP,			KC_F19,			  KC_F20,			  KC_F21,			  KC_SCRL,			    TO(6),			  KC_NO,			  KC_NO,			  KC_NO,			  KC_NO,
                  KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS,          KC_TRNS,      KC_TRNS,			KC_TRNS,			KC_TRNS
  ),
  [_EXTRAS] = LAYOUT(           // 4
    LCTL(KC_PSCR),KC_NO,			  KC_UP,			  KC_NO,	      QK_BOOT,          QK_BOOT,      KC_NO,        KC_NO,			  KC_NO,			  KC_NO,
    KC_LCTL,			KC_LEFT,			KC_DOWN,			KC_RGHT,			SRCHSEL,			    KC_NO,			  KC_NO,			  KC_NO,			  KC_NO,			  KC_NO,
    KC_LSFT,			KC_NO,			  RCS(KC_C),		RCS(KC_V),		LCA(KC_L),		    LCA(KC_L),		KC_NO,			  KC_NO,			  NEXTSEN,			KC_NO,
                  KC_TRNS,			KC_TRNS,			KC_TRNS,			KC_TRNS,          KC_TRNS,      KC_TRNS,		  KC_TRNS,			KC_TRNS
  ),
  [_NUMPAD] = LAYOUT(           // 5
    TO(_BASE),    KC_NO,			  KC_MS_U,			KC_NO,			  KC_NUM,			      KC_PSLS,			KC_P7,			  KC_P8,			  KC_P9,			  KC_PMNS,
    KC_NO,			  KC_MS_L,			KC_MS_D,			KC_MS_R,			KC_WH_U,			    KC_PAST,			KC_P4,			  KC_P5,			  KC_P6,			  KC_PPLS,
    KC_NO,			  KC_WH_L,			KC_BTN3,			KC_WH_R,			KC_WH_D,			    KC_P0,			  KC_P1,			  KC_P2,			  KC_P3,			  KC_PENT,
                  KC_BTN2,			KC_BTN1,			KC_BSPC,			TO(_BASE),        TO(_BASE),    KC_LALT,			KC_PDOT,			KC_COLN
  ),
  [_GAMING] = LAYOUT(           // 6
    KC_TAB,			  KC_Q,				  KC_W,				  KC_E,				  KC_R,				      KC_T,				  KC_Y,				  KC_U,				  KC_I,				  KC_O,
    KC_LCTL,			KC_A,				  KC_S,				  KC_D,				  KC_F,				      KC_G,				  KC_H,				  KC_J,				  KC_K,				  KC_CAPS,
    KC_LSFT,			KC_Z,				  KC_X,				  KC_C,				  KC_V,				      KC_B,				  KC_N,				  KC_M,         KC_COMM,			KC_DOT,
                  KC_ESC,			  LT(2,KC_1),   KC_SPC,			  TO(_BASE),        TO(_BASE),    KC_BSPC,			KC_ENT,			  KC_LALT
  )
};

// ----- MACROS ----- //
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
//  const uint8_t oneshot_mods = get_oneshot_mods();
//  const uint8_t mods = get_mods();
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
/*
  case BRACES:  // Types [], {}, or <> and puts cursor between braces.
    if (record->event.pressed) {
      clear_oneshot_mods();  // Temporarily disable mods.
      unregister_mods(MOD_MASK_CSAG);
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        SEND_STRING({});
      } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
        SEND_STRING(<>);
      } else {
        SEND_STRING([]);
      }
      tap_code(KC_LEFT);  // Move cursor between braces.
      register_mods(mods);  // Restore mods.
    }
    return false;
*/

  }
  return true;
}

// ----- COMBOS ----- //
const uint16_t PROGMEM combo_LCBR[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_RCBR[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_LPRN[] = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM combo_RPRN[] = {RCTL_T(KC_K), RALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM combo_LBRC[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_RBRC[] = {KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM combo_MINS[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_UNDS[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM combo_SCLN[] = {RALT_T(KC_L), KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_COLN[] = {KC_DOT, LT(_NUMPAD,KC_SLSH), COMBO_END};

const uint16_t PROGMEM combo_MPRV[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_MNXT[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_UNDO[] = {LT(2,KC_Z), KC_X, COMBO_END};
const uint16_t PROGMEM combo_COPY[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_PSTE[] = {KC_C, KC_V, COMBO_END};

const uint16_t PROGMEM combo_LESC[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_RESC[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_CSCR[] = {KC_E, LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM combo_PSCR[] = {KC_R, LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo_RTAB[] = {KC_T, KC_G, COMBO_END};
	
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_LCBR, KC_LCBR),
    COMBO(combo_RCBR, KC_RCBR),
    COMBO(combo_LPRN, KC_LPRN),
    COMBO(combo_RPRN, KC_RPRN),
    COMBO(combo_LBRC, KC_LBRC),
    COMBO(combo_RBRC, KC_RBRC),

    COMBO(combo_MINS, KC_MINS),
    COMBO(combo_UNDS, KC_UNDS),
    COMBO(combo_SCLN, KC_SCLN),
    COMBO(combo_COLN, KC_COLN),

    COMBO(combo_MPRV, KC_MPRV),
    COMBO(combo_MNXT, KC_MNXT),
    COMBO(combo_UNDO, LCTL(KC_Z)),
    COMBO(combo_COPY, LCTL(KC_C)),
    COMBO(combo_PSTE, LCTL(KC_V)),

    COMBO(combo_LESC, KC_ESC),
    COMBO(combo_RESC, KC_ESC),
    COMBO(combo_CSCR, LCTL(KC_PSCR)),
    COMBO(combo_PSCR, KC_PSCR),
    COMBO(combo_RTAB, RCS(KC_T))
};