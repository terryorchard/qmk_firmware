#include QMK_KEYBOARD_H

enum layers {
  _DEFAULT,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
        KC_TAB    , KC_Q      , KC_W      , KC_E      , KC_R      , KC_T      ,                                 KC_Y      , KC_U      , KC_I      , KC_O      , KC_P      , KC_MINS   ,
        KC_LCTL   , KC_A     ,LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),KC_G     ,                                 KC_H     ,RSFT_T(KC_J),RCTL_T(KC_K),RALT_T(KC_L),KC_QUOT  , KC_SCLN   ,
        KC_LSFT   , LT(2,KC_Z), KC_X      , KC_C      , KC_V      , KC_B      ,                                 KC_N      , KC_M      , KC_COMM   , KC_DOT    , LT(4,KC_SLSH)   ,LT(2, KC_ESC),
                                                                KC_MPLY    ,LALT_T(KC_DEL),LT(1,KC_BSPC),LT(2,KC_SPC),RGUI_T(KC_ENT)
    ),
    [_LOWER] = LAYOUT(
        KC_F1     , KC_F2     , KC_F3     , KC_F4     , KC_F5     , KC_F6     ,                                 KC_F7     , KC_F8     , KC_F9     , KC_F10    , KC_F11    , KC_F12    ,
        KC_LCTL   , KC_EXLM   , KC_AT     , KC_HASH   , KC_DLR    , KC_PERC   ,                                 KC_CIRC   , KC_AMPR   , KC_ASTR   , KC_LPRN   , KC_RPRN   , TO(4)     ,
        KC_LSFT   , KC_PSCR   , KC_PIPE   , KC_MPLY   , DM_PLY2   , DM_PLY1   ,                                 KC_TILD   , KC_PMNS   , KC_PPLS   , KC_LCBR   , KC_RCBR   , KC_PIPE   ,
                                                                _______   , _______   , _______       ,   MO(3)   , CW_TOGG
    ),
    [_RAISE] = LAYOUT(
        KC_TAB    , KC_1      , KC_2      , KC_3      , KC_4      , KC_5      ,                                 KC_6      , KC_7      , KC_8      , KC_9      , KC_0      , KC_BSPC   ,
        KC_LCTL   , XXXXXXX   , XXXXXXX   , XXXXXXX   , KC_PGUP   , KC_HOME   ,                                 LCA(KC_L) , KC_LEFT   , KC_DOWN   , KC_UP     , KC_RGHT   , TO(4)     ,
        KC_LSFT   , DT_DOWN   , DT_PRNT   , DT_UP     , KC_PGDN   , KC_END    ,                                 KC_GRV    , KC_UNDS   , KC_EQL    , KC_LBRC   , KC_RBRC   , KC_BSLS   ,
                                                                _______   , CW_TOGG   , MO(3)         ,   _______ , _______
    ),
    [_ADJUST] = LAYOUT(
        QK_BOOT   , KC_F13    , KC_F14    , KC_F15    , KC_F16    , KC_INS    ,                                 DM_REC1   , DM_REC2   ,DM_RSTP    , XXXXXXX   , DB_TOGG   , QK_BOOT   ,
        KC_CAPS   , KC_F17    , KC_F18    , KC_F19    , KC_F20    , KC_PAUS   ,                                 KC_VOLU   , KC_MPRV   , KC_MPLY   , KC_MNXT   , XXXXXXX   , XXXXXXX   ,
        KC_SLEP   , KC_F21    , KC_F22    , KC_F23    , KC_F24    , KC_SCRL   ,                                 KC_VOLD   , KC_MUTE   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,
                                                                _______   , _______   , _______       ,   _______ , _______
    ),
    [_NUMPAD] = LAYOUT(
        KC_TAB    , KC_BTN5   , KC_BTN2   , KC_MS_U   , KC_BTN1   , KC_NUM    ,                                 KC_PSLS   , KC_P7     , KC_P8     , KC_P9     , KC_PMNS   , KC_BSPC   ,
        KC_RCTL   , KC_BTN4   , KC_MS_L   , KC_MS_D   , KC_MS_R   , KC_WH_U   ,                                 KC_PAST   , KC_P4     , KC_P5     , KC_P6     , KC_PPLS   , TO(0)     ,
        KC_RSFT   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , KC_WH_D   ,                                 KC_P0     , KC_P1     , KC_P2     , KC_P3     , KC_PENT   , KC_PEQL   ,
                                                                _______   , RALT_T(KC_DEL), KC_BTN1    ,  KC_LALT , KC_PDOT
    )
};

// ----- COMBOS ----- //
const uint16_t PROGMEM combo_LCBR[] = {KC_U, KC_I, COMBO_END};                  // U I = {
const uint16_t PROGMEM combo_RCBR[] = {KC_I, KC_O, COMBO_END};                  // I O = }
const uint16_t PROGMEM combo_LPRN[] = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};  // J K = (
const uint16_t PROGMEM combo_RPRN[] = {RCTL_T(KC_K), RALT_T(KC_L), COMBO_END};  // K L = )
const uint16_t PROGMEM combo_LBRC[] = {KC_M, KC_COMM, COMBO_END};               // M < = [
const uint16_t PROGMEM combo_RBRC[] = {KC_COMM, KC_DOT, COMBO_END};             // < > = ]

const uint16_t PROGMEM combo_MINS[] = {KC_Y, KC_H, COMBO_END};                  // Y H = -
const uint16_t PROGMEM combo_UNDS[] = {KC_H, KC_N, COMBO_END};                  // H N = _
const uint16_t PROGMEM combo_SCLN[] = {RALT_T(KC_L), KC_QUOT, COMBO_END};       // L  "  = ;
const uint16_t PROGMEM combo_COLN[] = {KC_DOT, LT(4,KC_SLSH), COMBO_END}; // >  ?  = :

const uint16_t PROGMEM combo_MPRV[] = {KC_W, KC_E, COMBO_END};                  // W E = «
const uint16_t PROGMEM combo_MNXT[] = {KC_E, KC_R, COMBO_END};                  // E R = »
const uint16_t PROGMEM combo_UNDO[] = {LT(2,KC_Z), KC_X, COMBO_END};            // Z X = undo
const uint16_t PROGMEM combo_COPY[] = {KC_X, KC_C, COMBO_END};                  // X C = copy
const uint16_t PROGMEM combo_PSTE[] = {KC_C, KC_V, COMBO_END};                  // C V = paste

const uint16_t PROGMEM combo_LESC[] = {KC_Q, KC_W, COMBO_END};                  // Q W = esc
const uint16_t PROGMEM combo_RESC[] = {KC_O, KC_P, COMBO_END};                  // O P = esc
const uint16_t PROGMEM combo_CSCR[] = {KC_E, LCTL_T(KC_D), COMBO_END};          // E  D  = print region
const uint16_t PROGMEM combo_PSCR[] = {KC_R, LSFT_T(KC_F), COMBO_END};          // R  F  = print screen
const uint16_t PROGMEM combo_RTAB[] = {KC_T, KC_G, COMBO_END};                  // T  G  = restore tab

const uint16_t PROGMEM combo_KENT[] = {LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};  // D  F  = enter
const uint16_t PROGMEM combo_KTAB[] = {KC_A, LALT_T(KC_S), COMBO_END};          // A  S  = tab
const uint16_t PROGMEM combo_KILL[] = {KC_V, KC_B, COMBO_END};                  // V  B  = quit app
	
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