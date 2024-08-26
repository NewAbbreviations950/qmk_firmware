// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
    _num = 0,
    _calc = 1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───-───┐
     * │NUM│   │  SEND │
     * ├───┼───┼───-───┤
     * │CLR│ / │ * │BSP│
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │ - │
     * ├───┼───┼───┤---│
     * │ 4 │ 5 │ 6 │ + │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │ 0     │ . │   │
     * └───────┴───┴───┘
     */
    [_num] = LAYOUT(
        KC_1,   KC_1,           KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_1,   KC_1,
        KC_1,           KC_1,   KC_1
    ),

    /*
     * ┌───┐───┬───┬───┐
     * │Rst│Tab│MO1│Bsp│
     * └───┘───┼───┼───┤
     * │Num│ / │ * │ - │
     * ┌───┬───┬───┐───┤
     * │Hom│ ↑ │PgU│   │
     * ├───┼───┼───┤ + │
     * │ ← │   │ → │   │
     * ├───┼───┼───┤───┤
     * │End│ ↓ │PgD│   │
     * ├───┴───┼───┤Ent│
     * │Insert │Del│   │
     * └───────┴───┘───┘
     */
    [_calc] = LAYOUT(
        QK_BOOT, _______,          _______,
        _______, _______, _______, _______,
        KC_HOME, KC_UP,   KC_PGUP, _______,
        KC_LEFT, XXXXXXX, KC_RGHT, _______,
        KC_END,  KC_DOWN, KC_PGDN,
        KC_INS,           KC_DEL,  _______
    )
};
