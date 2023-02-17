#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _MACRO,
    _ARROW,
    _RGB
};

enum custom_keycodes {
    LAYER_SWITCH = SAFE_RANGE,
    OPTO,
    FUCK,
    DOIT,
    WORK,
    FUN,
    UNDEF,
    HOBBY,
    TOLD,
    WORKING,
    HINT,
    RESP,
    SEEM,
    SURPRISE,
    SHRUG,
    SAY_LIB,
    FUN_LIB,
    WEATHER,
    HELP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(       // 0 — BASE: numpad
        LAYER_SWITCH,   KC_PSLS,        KC_PAST,        KC_PMNS,
        KC_P7,          KC_P8,          KC_P9,          KC_PPLS,
        KC_P4,          KC_P5,          KC_P6,          KC_WH_U,
        KC_P1,          KC_P2,          KC_P3,          KC_WH_D,
        KC_P0,          KC_PDOT,        LALT_T(KC_PENT),KC_CALC
    ),
    [1] = LAYOUT(       // 1 — MACROS: wzd_bot
        LAYER_SWITCH,   SURPRISE,       SEEM,           OPTO,
        WEATHER,        WORKING,        HINT,           SHRUG,
        UNDEF,          HOBBY,          TOLD,           KC_WH_U,
        DOIT,           WORK,           FUN,            KC_WH_D,
        FUCK,           RESP,           KC_PENT,        QK_BOOT
    ),
    [2] = LAYOUT(       // 2 — ARROW: arrow keys
        LAYER_SWITCH,   XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        KC_UP,          XXXXXXX,        XXXXXXX,
        KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_WH_U,
        KC_P2,          XXXXXXX,        XXXXXXX,        KC_WH_D,
        XXXXXXX,        XXXXXXX,        KC_PENT,        _______
    ),
    [3] = LAYOUT(       // 3 — RGB: light control
        LAYER_SWITCH,   KC_MPRV,        KC_MPLY,        KC_MNXT,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        RGB_SAI,        RGB_VAI,        KC_WH_U,
        KC_P3,          RGB_SAD,        RGB_VAD,        KC_WH_D,
        RGB_M_P,        RGB_TOG,        KC_PENT,        _______
    ),
};

uint16_t layer = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LAYER_SWITCH:
            if (record->event.pressed) {
                if (layer > 0) {
                    layer_off(layer);
                }
                layer = (layer + 1) % 4;
                if (layer > 0) {
                    layer_on(layer);
                }
            }
            return false;

        case FUCK:
            if (record->event.pressed) {
                SEND_STRING("/wiz fuck ");
            }
            return false;

        case DOIT:
            if (record->event.pressed) {
                SEND_STRING("/wiz say you won’t do it");
            }
            return false;

        case WORK:
            if (record->event.pressed) {
                SEND_STRING("/wiz say shit you’re hard work");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case FUN:
            if (record->event.pressed) {
                SEND_STRING("/wiz say having fun yet");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case UNDEF:
            if (record->event.pressed) {
                SEND_STRING("/wiz say undefined");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case HOBBY:
            if (record->event.pressed) {
                SEND_STRING("/wiz say I like this hobby");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case TOLD:
            if (record->event.pressed) {
                SEND_STRING("/wiz told dad");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case WORKING:
            if (record->event.pressed) {
                SEND_STRING("/wiz gif working.gif");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case HINT:
            if (record->event.pressed) {
                SEND_STRING("/wiz gif hint.gif");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case RESP:
            if (record->event.pressed) {
                SEND_STRING("/wiz gif responses.gif");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case SEEM:
            if (record->event.pressed) {
                SEND_STRING("/wiz gif seemright.gif");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case SURPRISE:
            if (record->event.pressed) {
                SEND_STRING("/wiz gif surprise.gifv");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case SHRUG:
            if (record->event.pressed) {
                SEND_STRING("/wiz gif shrug.gif");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case HELP:
            if (record->event.pressed) {
                SEND_STRING("/wiz help");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case WEATHER:
            if (record->event.pressed) {
                SEND_STRING("/wiz weather");
            }
            return false;

        case SAY_LIB:
            if (record->event.pressed) {
                SEND_STRING("/wiz say library");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case FUN_LIB:
            if (record->event.pressed) {
                SEND_STRING("/wiz fun library");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case OPTO:
            if (record->event.pressed) {
                SEND_STRING("opto");
                SEND_STRING(SS_TAP(X_TAB));
                SEND_STRING("opto22");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        default:
            return true;
    }
}