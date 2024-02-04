/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "features/sentence_case.h"
#include <stdio.h>

#define _DVORAK 0
#define _FUNKEYS 1
#define _SYMBOLS 2
#define _RANDOM 3
#define _NUMPAD 4
#define _ARROWSTWO 5


enum {
    TD_SCO_CO,
    TD_LEFT,
    TD_RIGHT,
    TD_UP,
    TD_DOWN
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_SCO_CO] = ACTION_TAP_DANCE_DOUBLE(KC_SEMICOLON, KC_COLN),
    [TD_LEFT] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_LEFT), LALT(KC_LEFT)),
    [TD_RIGHT] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_RIGHT), LALT(KC_RIGHT)),
    [TD_UP] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_UP), LALT(KC_UP)),
    [TD_DOWN] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_DOWN), LALT(KC_DOWN)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,  KC_QUOTE, KC_COMMA, KC_DOT, KC_P,    KC_Y,        KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLASH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, LCTL_T(KC_A),   LT(_SYMBOLS, KC_O),    KC_E,    LALT_T(KC_U), KC_I,            KC_D,    RALT_T(KC_H),    KC_T,    KC_N,   RCTL_T(KC_S),    KC_MINUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QK_LEAD, TD(TD_SCO_CO), KC_Q,   KC_J,   KC_K,    KC_X,                        KC_B,    KC_M,    KC_W,     KC_V,    KC_Z,   RSFT_T(KC_SLASH),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO(_ARROWSTWO),   LT(_FUNKEYS, KC_ENT),  LT(_NUMPAD,KC_SPACE), OSM(MOD_LSFT),  LT(_RANDOM, KC_BSPC),   KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [_FUNKEYS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, KC_MPRV, LCTL_T(KC_MNXT), KC_VOLU, KC_PGUP, KC_UNDS,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_RIGHT, KC_BACKSLASH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS,                      KC_PLUS, KC_END,  KC_END, RGB_SAD, RGB_VAD, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       QK_RBT,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_LABK, KC_CIRC,  KC_LPRN, KC_RPRN, KC_PLUS, KC_BACKSLASH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_DEL,  _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                            KC_RABK, KC_EQUAL, KC_LCBR, KC_RCBR, KC_ASTR,  KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
BL_STEP, _______, _______, _______, KC_DOWN, KC_LCBR,                               KC_TILD, KC_GRAVE, KC_LBRC, KC_RBRC,   KC_PIPE, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_RANDOM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_DEL,  KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F11, KC_MSTP, KC_MPLY, LCTL(KC_C), KC_PGDN, KC_MINS,        KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_7,    KC_8,    KC_9,    KC_P,    KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_A,    KC_LCTL,    LCTL(KC_B),    KC_LALT,    KC_G,                               KC_H,    KC_4,    KC_5,    KC_6,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B  ,                       KC_N, KC_1,    KC_2,   KC_3,    KC_0,    KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
    [_ARROWSTWO] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, KC_MPRV, LCTL_T(KC_MNXT), KC_VOLU, KC_PGUP, KC_UNDS,                     TD(TD_LEFT), TD(TD_DOWN), TD(TD_UP), TD(TD_RIGHT), KC_RIGHT, KC_BACKSLASH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS,                      KC_PLUS, KC_END,  KC_END, RGB_SAD, RGB_VAD, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   LGUI(KC_BSPC), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
};

    layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_disable();
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   if (!process_sentence_case(keycode, record)) { return false; }
    switch (keycode) {
    case KC_CAPS:
        if (record->event.pressed) {
            // do nothing special
        } else {
            rgblight_disable();
        }
        return true;
    default:
        return true;
    }
}

bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {  //if caps lock is on
        rgblight_enable();
        rgblight_sethsv_noeeprom(HSV_WHITE);
    }
    return true;
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_H)) {
        SEND_STRING("x");
    } else if (leader_sequence_one_key(KC_T)) {
        SEND_STRING("x");
    } else if (leader_sequence_one_key(KC_N)) {
        SEND_STRING("x");
    } else if (leader_sequence_one_key(KC_S)) {
        SEND_STRING("x");
    }
}


enum combos {
  AB_CAPS,
  HT_ESCAPE,
  EU_TAB,
  AO_LAYER,
  COPY,
  PASTE
};

const uint16_t PROGMEM caps_lock_combo[] = {LCTL_T(KC_A), KC_B, COMBO_END};
const uint16_t PROGMEM escape_combo[] = {RALT_T(KC_H), KC_T, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_E, LALT_T(KC_U), COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_K, KC_X, COMBO_END};
const uint16_t PROGMEM layer_combo[] = {KC_O, KC_E, LALT_T(KC_U), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [HT_ESCAPE] = COMBO(escape_combo, KC_ESC),
  [AB_CAPS] = COMBO(caps_lock_combo, KC_CAPS),
  [EU_TAB] = COMBO(tab_combo, KC_TAB),
  [COPY] = COMBO(copy_combo, LALT(KC_C)),
  [AO_LAYER] = COMBO(layer_combo, MO(_SYMBOLS)),
  [PASTE] = COMBO(paste_combo, LALT(KC_V))
};

