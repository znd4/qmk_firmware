/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "keycode.h"
#include QMK_KEYBOARD_H
#include "muse.h"
#include "macros.h"

// clang-format off
enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _NUMERIC,
  _SYMBOL,
  _GUI,
  _NAV,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  NUMERIC,
  SYMBOL,
  GUI,
  NAV,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,   KC_1,   KC_2,     KC_3,    KC_4,    KC_5,   KC_6,      KC_7,   KC_8,    KC_9,     KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,   KC_Y,      KC_U,   KC_I,    KC_O,     KC_P,    KC_BACKSLASH,
  CTL_ESC,  KC_A,   KC_S,     KC_D,    KC_F,    KC_G,   KC_H,      KC_J,   KC_K,    KC_L,     KC_SCLN, KC_QUOT,
  SFT_LPRN, KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,   KC_N,      KC_M,   KC_COMM, KC_DOT,   KC_SLSH, SFT_RPRN,
  GUI_LBRK, LHYPER, ALT_LABK, KC_LGUI, NUMERIC, KC_SPC, KC_ENT, SYMBOL, NAV,     ALT_RABK, RHYPER,  GUI_RBRK
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |NUMERIC |    Space    |SYMBOL | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV,   KC_1,   KC_2,     KC_3,    KC_4,    KC_5,   KC_6,      KC_7,   KC_8,    KC_9,     KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,     KC_F,    KC_P,    KC_G,   KC_J,      KC_L,   KC_U,    KC_Y,     KC_SCLN, KC_BACKSLASH,
  CTL_ESC,  KC_A,   KC_R,     KC_S,    KC_T,    KC_D,   KC_H,      KC_N,   KC_E,    KC_I,     KC_O,    KC_QUOT,
  SFT_LPRN, KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,   KC_K,      KC_M,   KC_COMM, KC_DOT,   KC_SLSH, SFT_RPRN,
  GUI_LBRK, LHYPER, ALT_LABK, KC_LGUI, NUMERIC, KC_SPC, KC_ENT, SYMBOL, NAV,     ALT_RABK, RHYPER,  GUI_RBRK
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |NUMERIC |    Space    |SYMBOL | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid(
  KC_GRV,   KC_1,    KC_2,     KC_3,    KC_4,    KC_5,   KC_6,      KC_7,   KC_8, KC_9,     KC_0,   KC_BSPC,
  KC_TAB,   KC_QUOT, KC_COMM,  KC_DOT,  KC_P,    KC_Y,   KC_F,      KC_G,   KC_C, KC_R,     KC_L,   KC_BACKSLASH,
  CTL_ESC,  KC_A,    KC_O,     KC_E,    KC_U,    KC_I,   KC_D,      KC_H,   KC_T, KC_N,     KC_S,   KC_SLSH,
  SFT_LPRN, KC_SCLN, KC_Q,     KC_J,    KC_K,    KC_X,   KC_B,      KC_M,   KC_W, KC_V,     KC_Z,   SFT_RPRN,
  GUI_LBRK, LHYPER,  ALT_LABK, KC_LGUI, NUMERIC, KC_SPC, KC_ENT, SYMBOL, NAV,  ALT_RABK, RHYPER, GUI_RBRK
),

/* NUMERIC
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMERIC] = LAYOUT_preonic_grid(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, _______, _______, _______
),

/* SYMBOL
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_preonic_grid(
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_DEL, _______, _______, _______, _______, _______
),

/*
 *
 */
[_GUI] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  _______, _______, KC_MPRV, _______, _______, _______, _______, _______,
  _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______,    _______,    _______,     _______, _______, KC_MNXT, _______, _______, _______, _______, _______,
  _______, KC_MPRV,    KC_MPLY,    KC_MNXT,     KC_BRID, KC_SLEP, _______, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, _______
),

/* Adjust (NUMERIC + SYMBOL)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
        case GUI:
            if (record->event.pressed) {
                layer_on(_GUI);
            } else {
                layer_off(_GUI);
            }
            return false;
            break;
        case NUMERIC:
            if (record->event.pressed) {
                layer_on(_NUMERIC);
                update_tri_layer(_NUMERIC, _SYMBOL, _ADJUST);
            } else {
                layer_off(_NUMERIC);
                update_tri_layer(_NUMERIC, _SYMBOL, _ADJUST);
            }
            return false;
            break;
        case SYMBOL:
            if (record->event.pressed) {
                layer_on(_SYMBOL);
                update_tri_layer(_NUMERIC, _SYMBOL, _ADJUST);
            } else {
                layer_off(_SYMBOL);
                update_tri_layer(_NUMERIC, _SYMBOL, _ADJUST);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
                backlight_step();
#endif
#ifdef RGBLIGHT_ENABLE
                rgblight_step();
#endif
#ifdef __AVR__
                writePinLow(E6);
#endif
            } else {
                unregister_code(KC_RSFT);
#ifdef __AVR__
                writePinHigh(E6);
#endif
            }
            return false;
            break;
    }
    return true;
};

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_SYMBOL)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        } else {
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        }
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case SYMBOL:
        case NUMERIC:
            return false;
        default:
            return true;
    }
}
