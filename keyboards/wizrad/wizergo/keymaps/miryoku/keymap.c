#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
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
      *           └───┤Bsp├───┐ ┌───┐     ┌───┐ ┌───┤Spc├───┘
      *               └───┤Del│ │NUM│     │PLY│ │Ent├───┘
      *                   └───┘ └───┘     └───┘ └───┘
      */
  [_BASE] = LAYOUT(             // 0
    KC_Q,				  KC_W,				  KC_F,				  KC_P,				  KC_B,				      KC_J,				  KC_L,				  KC_U,				  KC_Y,				  KC_QUOT,
    KC_A,				  LALT_T(KC_R),	LCTL_T(KC_S),	LSFT_T(KC_T), KC_G,				      KC_M,				  RSFT_T(KC_N), RCTL_T(KC_E),	RALT_T(KC_I),	KC_O,
    LT(2,KC_Z),	  KC_X,				  KC_C,				  KC_D,				  KC_V,				      KC_K,				  KC_H,				  KC_COMM,			KC_DOT,			  LT(_NUMPAD,KC_SLSH),
                  KC_TAB,       LT(1,KC_BSPC),LT(3,KC_DEL), TO(_BASE),        KC_MPLY,      RGUI_T(KC_ENT),LT(2,KC_SPC),KC_ESC
  ),
  [_LOWER] = LAYOUT(           // 1
    KC_F2,			  KC_F3,        KC_F4,			  KC_F5,        KC_F6,			      KC_F7,			  KC_F8,			  KC_F9,			  KC_F10,			  KC_F11,
    KC_EXLM,		  KC_AT,			  KC_HASH,			KC_DLR,			  KC_PERC,			    KC_CIRC,			KC_AMPR,			KC_ASTR,			KC_LPRN,			KC_RPRN,
    KC_F1,			  KC_F12,       KC_PIPE,			DM_PLY2,      DM_PLY1,	        KC_TILD,			KC_UNDS,			KC_PLUS,			KC_LBRC,			KC_RBRC,
                  TO(_BASE),    KC_TRNS,			KC_TRNS,			KC_TRNS,          KC_TRNS,      CW_TOGG,			MO(_ADJUST),  KC_TRNS
  ),
  [_RAISE] = LAYOUT(           // 2
    KC_1,				  KC_2,				  KC_3,				  KC_4,				  KC_5,				      KC_6,				  KC_7,				  KC_8,				  KC_9,				  KC_0,
    KC_LCTL,			KC_LCBR,			KC_RCBR,			KC_PGUP,			KC_HOME,			    KC_BSLS,			KC_LEFT,			KC_DOWN,			KC_UP,			  KC_RGHT,
    KC_LSFT,			KC_LBRC,			KC_RBRC,			KC_PGDN,			KC_END,			      KC_GRV,			  KC_MINS,			KC_EQL,			  KC_COLN,			KC_SCLN,
                  KC_TRNS,			MO(_ADJUST),  CW_TOGG,			KC_TRNS,          KC_TRNS,      KC_TRNS,			KC_TRNS,			TO(_BASE)
  ),
  [_ADJUST] = LAYOUT(           // 3
    QK_BOOT,			LCTL(KC_W),   KC_UP,        KC_ENT,       KC_INS,			      DM_REC1,	    DM_REC2,      DM_RSTP,	    KC_NO,			  QK_BOOT,
    KC_CAPS,			KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_PAUS,			    DT_DOWN,	    DT_UP,		    DT_PRNT,	    KC_LCBR,			KC_RCBR,
    KC_SLEP,			KC_F13,			  KC_F14,			  KC_F15,			  LCA(KC_L),		    LCA(KC_L),		KC_NO,			  SRCHSEL,      NEXTSEN,      KC_TRNS,
                  KC_TRNS,			KC_TRNS,			TO(_GAMING),  KC_TRNS,          KC_TRNS,      TO(_GAMING),  KC_TRNS,			KC_TRNS
  ),
  [_NUMPAD] = LAYOUT(           // 4
    TO(_BASE),    KC_NO,			  KC_MS_U,			KC_SCRL,      KC_NUM,			      KC_PSLS,			KC_P7,			  KC_P8,			  KC_P9,			  KC_PMNS,
    KC_NO,			  KC_MS_L,			KC_MS_D,			KC_MS_R,			KC_WH_U,			    KC_PAST,			KC_P4,			  KC_P5,			  KC_P6,			  KC_PPLS,
    KC_NO,			  KC_WH_L,			KC_BTN3,			KC_WH_R,			KC_WH_D,			    KC_P0,			  KC_P1,			  KC_P2,			  KC_P3,			  KC_PENT,
                  KC_BTN2,			KC_BSPC,			KC_BTN1,			TO(_BASE),        TO(_BASE),    KC_PDOT,			KC_LALT,			KC_COLN
  ),
  [_GAMING] = LAYOUT(           // 5
    KC_TAB,			  KC_Q,				  KC_W,				  KC_E,				  KC_R,				      KC_T,				  KC_Y,				  KC_U,				  KC_I,				  KC_O,
    KC_LCTL,			KC_A,				  KC_S,				  KC_D,				  KC_F,				      KC_G,				  KC_H,				  KC_J,				  KC_K,				  KC_CAPS,
    KC_LSFT,			KC_Z,				  KC_X,				  KC_C,				  KC_V,				      KC_B,				  KC_N,				  KC_M,         KC_COMM,			KC_DOT,
                  KC_ESC,			  KC_SPC,			  LT(2,KC_1),   TO(_BASE),        KC_MPLY,      KC_ENT,			  KC_BSPC,			KC_LALT
  )
};

// ----- MACROS ----- //
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

// ----- COMBOS ----- //
const uint16_t PROGMEM combo_LCBR[] = {KC_L, KC_U, COMBO_END};                  // L U = {
const uint16_t PROGMEM combo_RCBR[] = {KC_U, KC_Y, COMBO_END};                  // U Y = }
const uint16_t PROGMEM combo_LPRN[] = {RSFT_T(KC_N), RCTL_T(KC_E), COMBO_END};  // N E = (
const uint16_t PROGMEM combo_RPRN[] = {RCTL_T(KC_E), RALT_T(KC_I), COMBO_END};  // E I = )
const uint16_t PROGMEM combo_LBRC[] = {KC_H, KC_COMM, COMBO_END};               // H < = [
const uint16_t PROGMEM combo_RBRC[] = {KC_COMM, KC_DOT, COMBO_END};             // < > = ]

const uint16_t PROGMEM combo_MINS[] = {KC_J, KC_M, COMBO_END};                  // J M = -
const uint16_t PROGMEM combo_UNDS[] = {KC_M, KC_K, COMBO_END};                  // M K = _
const uint16_t PROGMEM combo_SCLN[] = {RALT_T(KC_I), KC_O, COMBO_END};          // I O = ;
const uint16_t PROGMEM combo_COLN[] = {KC_DOT, LT(_NUMPAD,KC_SLSH), COMBO_END}; // > ? = :

const uint16_t PROGMEM combo_MPRV[] = {KC_W, KC_F, COMBO_END};                  // W F = «
const uint16_t PROGMEM combo_MNXT[] = {KC_F, KC_P, COMBO_END};                  // F P = »
const uint16_t PROGMEM combo_UNDO[] = {LT(2,KC_Z), KC_X, COMBO_END};            // Z X = undo
const uint16_t PROGMEM combo_COPY[] = {KC_X, KC_C, COMBO_END};                  // X C = copy
const uint16_t PROGMEM combo_PSTE[] = {KC_C, KC_D, COMBO_END};                  // C D = paste

const uint16_t PROGMEM combo_LESC[] = {KC_Q, KC_W, COMBO_END};                  // Q W = esc
const uint16_t PROGMEM combo_RESC[] = {KC_Y, KC_QUOT, COMBO_END};               // Y " = esc
const uint16_t PROGMEM combo_CSCR[] = {KC_F, LCTL_T(KC_S), COMBO_END};          // F S = print region
const uint16_t PROGMEM combo_PSCR[] = {KC_P, LSFT_T(KC_T), COMBO_END};          // P T = print screen
const uint16_t PROGMEM combo_RTAB[] = {KC_B, KC_G, COMBO_END};                  // B G = restore tab

const uint16_t PROGMEM combo_KENT[] = {LCTL_T(KC_S), LSFT_T(KC_T), COMBO_END};  // S T = enter
const uint16_t PROGMEM combo_KTAB[] = {KC_A, LALT_T(KC_R), COMBO_END};          // A R = tab
const uint16_t PROGMEM combo_KILL[] = {KC_D, KC_V, COMBO_END};                  // D V = quit app
	
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_LCBR, KC_LCBR),
    COMBO(combo_RCBR, KC_RCBR),
    COMBO(combo_LPRN, KC_LPRN),
    COMBO(combo_RPRN, KC_RPRN),
    COMBO(combo_LBRC, KC_LBRC),
    COMBO(combo_RBRC, KC_RBRC),
// + 6 =  6
    COMBO(combo_MINS, KC_MINS),
    COMBO(combo_UNDS, KC_UNDS),
    COMBO(combo_SCLN, KC_SCLN),
    COMBO(combo_COLN, KC_COLN),
// + 4 = 10
    COMBO(combo_MPRV, KC_MPRV),
    COMBO(combo_MNXT, KC_MNXT),
    COMBO(combo_UNDO, LCTL(KC_Z)),
    COMBO(combo_COPY, LCTL(KC_C)),
    COMBO(combo_PSTE, LCTL(KC_V)),
// + 5 = 15
    COMBO(combo_LESC, KC_ESC),
    COMBO(combo_RESC, KC_ESC),
    COMBO(combo_CSCR, LCTL(KC_PSCR)),
    COMBO(combo_PSCR, KC_PSCR),
    COMBO(combo_RTAB, RCS(KC_T)),
// + 5 = 20
    COMBO(combo_KENT, KC_ENT),
    COMBO(combo_KTAB, KC_TAB),
    COMBO(combo_KILL, LALT(KC_F4))
};