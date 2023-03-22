#include QMK_KEYBOARD_H

enum layers {
    _NUMPD,
    _MACRO,
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
        TO(1),          KC_PSLS,        KC_PAST,        KC_PMNS,
        KC_P7,          KC_P8,          KC_P9,          KC_PPLS,
        KC_P4,          KC_P5,          KC_P6,          KC_WH_U,
        KC_P1,          KC_P2,          KC_P3,          KC_WH_D,
        KC_P0,          KC_PDOT,        LALT_T(KC_PENT),KC_NUM
    ),
    [1] = LAYOUT(       // 1 — MACROS: wzd_bot
        TO(0),          SURPRISE,       SEEM,           OPTO,
        WEATHER,        WORKING,        HINT,           SHRUG,
        UNDEF,          HOBBY,          TOLD,           KC_WH_U,
        DOIT,           WORK,           FUN,            KC_WH_D,
        FUCK,           RESP,           KC_PENT,        QK_BOOT
    )
};

/*
led_config_t g_led_config = { {
        // Key Matrix to LED Index,
        { 0,      NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED, NO_LED }
    }, {
        // LED Index to Physical Position
        { 0,  0 }
    }, {
        // LED Index to Flag
        0
    }
};
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FUCK:
            if (record->event.pressed) {
                SEND_STRING("/wiz fuck ");
            }
            return false;

        case DOIT:
            if (record->event.pressed) {
                SEND_STRING("/wiz say you won" SS_TAP(X_QUOT) "t do it");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case WORK:
            if (record->event.pressed) {
                SEND_STRING("/wiz say shit you" SS_TAP(X_QUOT) "re hard work");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        case FUN:
            if (record->event.pressed) {
                SEND_STRING("/wiz say having fun yet");
                tap_code16(KC_QUES);
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
                SEND_STRING("/wiz weather ");
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
