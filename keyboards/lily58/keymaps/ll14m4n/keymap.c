#include QMK_KEYBOARD_H
#include <stdio.h>
#include "wrappers.h"

// extern uint8_t is_master;

enum layer_number {
    _COLEMAK = 0,
    _NAV,
    _SYM,
    _FUN,
    _SYM2,
};

enum custom_keycodes { KC_QWER = SAFE_RANGE, KC_COLE };


// layer
//#define LOW_SPC LT(_NAV, KC_SPACE)
//#define RAI_ENT  LT(_SYM, KC_ENT)
#define MO_NAVI MO(_NAV)
#define MO_SYMB MO(_SYM)
#define MO_FUNC MO(_FUN)
#define MO_SYM2 MO(_SYM2)


// one shot modifiers
#define OS_LSFT  OSM(MOD_LSFT)
#define OS_RSFT  OSM(MOD_RSFT)

#define OS_LCTL  OSM(MOD_LCTL)
#define OS_RCTL  OSM(MOD_RCTL)

#define OS_LALT  OSM(MOD_LALT)
#define OS_RALT  OSM(MOD_RALT)

#define OS_LGUI  OSM(MOD_LGUI)
#define OS_RGUI  OSM(MOD_RGUI)

#define OS_MEH   OSM(MOD_MEH)
#define OS_HYPR  OSM(MOD_HYPR)

// mac os
#define PREV_TB SCMD(KC_LBRC)  // cmd+shift+[
#define NEXT_TB SCMD(KC_RBRC)  // cmd+shift+]
#define BACK    LCMD(KC_LBRC)  // cmd+[
#define FORWARD LCMD(KC_RBRC)  // cmd+]
#define CMD_C   LCMD(KC_C)     // cmd+c
#define CMD_V   LCMD(KC_V)     // cmd+v
#define CMD_X   LCMD(KC_X)     // cmd+v
#define CMD_Z   LCMD(KC_Z)     // cmd+v
#define MEH_F13 MT(MOD_MEH,KC_F13)
#define MEH_F14 MT(MOD_MEH,KC_F14)
#define MEH_F15 MT(MOD_MEH,KC_F15)

// @formatter:off
// clang-format offoffoffoff


#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_wrapper(
      _______, ___________________________________________,                   ___________________________________________, _______,
      _______, _________________COLEMAK_L1________________,                   _________________COLEMAK_R1________________, _______,
      _______, _________________COLEMAK_L2________________,                   _________________COLEMAK_R2________________, _______,
      _______, _________________COLEMAK_L3________________, KC_F13,  KC_QWER, _________________COLEMAK_R3________________, _______,
                                 _______, _______, _______, _______, _______, _______,  _______, _______
    ),

    [_NAV] = LAYOUT(
      KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX,
      XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, OS_RCTL, KC_DEL,
      XXXXXXX, CMD_Z,   CMD_X,   CMD_C,   CMD_V,   XXXXXXX, _______, _______, KC_BSPC, CMD_C,   CMD_V,   XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, _______, _______, KC_ENT,  _______, _______, _______
    ),

    [_SYM] = LAYOUT(
      KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, KC_QUOT, XXXXXXX,
      XXXXXXX, KC_BSLS, KC_PIPE, KC_LCBR, KC_LPRN, KC_LBRC,                   KC_ASTR, KC_RGUI, KC_RALT, KC_RSFT, KC_RCTL, XXXXXXX,
      XXXXXXX, KC_CIRC, KC_AMPR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX, KC_LT,   KC_GT,   XXXXXXX, XXXXXXX,
                                 _______, _______, _______, MO_SYM2, _______, _______, _______, _______
    ),

    [_FUN] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX, XXXXXXX,
      XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX,                   KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX, XXXXXXX,
                                 _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_SYM2] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, KC_RCBR, KC_RPRN, KC_RBRC,                   XXXXXXX, KC_P4,   KC_P5,   KC_P6,   XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_P1,   KC_P2,   KC_P3,   XXXXXXX, XXXXXXX,
                                 _______, _______, _______, _______, KC_PENT, KC_P0,   KC_PDOT, TG(_SYM2)
    ),


};

// @formatter:on
// clang-format on

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;
    return rotation;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYM, _NAV, _FUN);
    return state;
}

static void render_logo(void) {
    static const char PROGMEM logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);

        switch (get_highest_layer(layer_state)) {
            case _NAV:
                oled_write_ln_P(PSTR("N A V"), false);
                break;
            case _SYM:
                oled_write_ln_P(PSTR("S Y M"), false);
                break;
            case _FUN:
                oled_write_ln_P(PSTR("F U N"), false);
                break;
            case _SYM2:
                oled_write_ln_P(PSTR("S Y M 2"), false);
                break;
            default:
                oled_write_ln_P(PSTR("Undefined"), false);
        }

        oled_write_ln("", false);

    } else {
        render_logo();
    }
    return false;
}
#endif  // OLED_ENABLE

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case KC_COLE:
//            if (record->event.pressed && !get_mods()) {
//                default_layer_set(1UL << _COLEMAK);
//                tap_code(KC_F13);
//#ifdef OLED_ENABLE
//                if (is_keyboard_master()) {
//                    oled_write_ln_P(PSTR("COLEMAK"), false);
//                }
//#endif
//            }
//            break;
//
//        case KC_QWER:
//            if (record->event.pressed && !get_mods()) {
//                default_layer_set(1UL << _QWERTY);
//                tap_code(KC_F13);
//#ifdef OLED_ENABLE
//                if (is_keyboard_master()) {
//                    oled_write_ln_P(PSTR("QWERTY"), false);
//                }
//#endif
//            }
//            break;
//
//        default:
//            break;
//    }
//    return true;
//}

// Rotary encoder related code
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {  // Encoder on master side
        if (IS_LAYER_ON(_NAV)) {
            // Cursor control
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
        } else {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    //  else if (index == 0) { // Encoder on slave side
    //    if(IS_LAYER_ON(_NAV)) { // on Lower layer
    //      //
    //      if (clockwise) {
    //          tap_code(KC_RIGHT);
    //      } else {
    //          tap_code(KC_LEFT);
    //      }
    //    }
    //    else {
    //      if (clockwise) {
    //          tap_code(KC_DOWN);
    //      } else {
    //          tap_code(KC_UP);
    //      }
    //    }
    //  }
    return true;
}
#endif
