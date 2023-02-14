#include QMK_KEYBOARD_H

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
      *               └───┤Bsp│ │CAL│     │PLY│ │Spc├───┘
      *                   └───┘ └───┘     └───┘ └───┘
      */
    [0] = LAYOUT(
        KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,               KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,               KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,
        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,               KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,
                    KC_TAB,     KC_DEL,     KC_BSPC,    KC_CALC,            KC_MPLY,    KC_SPC,     KC_ENT,     KC_ESC
    )
};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    // 0 is left-half encoder,
    // 1 is right-half encoder
    if (index == 0) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    } else if (index == 1) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}