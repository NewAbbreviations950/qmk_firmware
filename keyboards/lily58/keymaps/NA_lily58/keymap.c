#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LEFT,
  _RIGHT,
  _ADJUST,
};

enum custom_keycodes {
    NO_NOK = SAFE_RANGE, // Norwegian currency symbol
    KC_JIGG, // F15 keypress every 30 seconds when inactive
    DE_LEFT, // Windows switch desktop left
    DE_RIGHT, // Windows switch desktop right
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   !  |   @  |   #  |   $  |   %  |                    |   &  |   *  |   \  | REC1 | REC2 | RSTP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Lshift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ø  |  Æ   |
 * |------+------+------+------+------+------|   /   |    |       |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RSFTDL|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LEFT  | /Space  /       \Enter \  |BackSP|RIGHT | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_EXLM,ALGR(KC_2),S(KC_3),ALGR(KC_4),S(KC_5),                  S(KC_6), S(KC_BSLS),KC_EQL,  DM_REC1, DM_REC2, DM_RSTP,
  KC_TAB,   KC_Q,   KC_W,      KC_E,   KC_R,      KC_T,                     KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_LBRC,
  KC_LSFT,  KC_A,   KC_S,      KC_D,   KC_F,      KC_G,                     KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,      KC_C,   KC_V,      KC_B, S(KC_7),  _______,  KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_DEL),
                        KC_LALT, KC_LGUI, TT(_LEFT),  KC_SPC,  KC_ENT, KC_BSPC, TT(_RIGHT), KC_RALT
),
/* LEFT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |Vol_dn|Vol_up| Mute |                    |   /  |   *  |   -  | PLY1 | PLY2 | NUML |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | NUM  |      |      |  Up  |  ML  | Copy |                    |  MR  |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |      | Left | Down | Right| Paste|-------.    ,-------|      |   4  |   5  |   6  |   =  |      |
 * |------+------+------+------+------+------|   |   |    |       |------+------+------+------+------+------|
 * |Jiggle|      |      |      |      |      |-------|    |-------|      |   1  |   2  |   3  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LEFT  | /Space  /       \Enter \  |   0  |RIGHT |   ,  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LEFT] = LAYOUT(
  _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,                         KC_PSLS, KC_PAST, KC_PMNS, DM_PLY1, DM_PLY2, KC_NUM,
  KC_NUM,  _______, _______, KC_UP,   KC_BTN1, LCTL(KC_C),                      KC_BTN2, KC_7,    KC_8,    KC_9,    KC_PPLS, _______,
  KC_CAPS, _______, KC_LEFT, KC_DOWN, KC_RGHT, LCTL(KC_V),                      _______, KC_4,    KC_5,    KC_6,    S(KC_0), _______,
  KC_JIGG, _______, _______, _______, _______, _______, KC_GRV,        _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
                             _______, _______, _______, _______,       _______, KC_P0,   _______, KC_COMM
),
/* RIGHT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  [   |   ]  |      |                    |   <  |   >  |D_LEFT|D_RIGT|      | Home |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  (   |   )  |      |-------.    ,-------|   ?  |   '  |   "  |      |      | End  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |  {   |   }  |      |-------|    |-------|   ~  |  ,-  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LEFT  | /Space  /       \Enter \  |BackSP|RIGHT | RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RIGHT] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,                         KC_F7,        KC_F8,     KC_F9,   KC_F10,   KC_F11,  KC_F12,
  _______, _______, _______,ALGR(KC_8),ALGR(KC_9),_______,                   KC_NUBS,      S(KC_NUBS),DE_LEFT, DE_RIGHT, _______, KC_HOME,
  _______, _______, _______,RSFT(KC_8),RSFT(KC_9),_______,                   LSFT(KC_MINS),KC_NUHS,   S(KC_2), _______,  _______, KC_END,
  _______, _______, _______,ALGR(KC_7),ALGR(KC_0),_______, _______, _______, ALGR(KC_RBRC),NO_NOK,    _______, _______,  _______, _______,
                                _______, _______, _______, _______, _______, _______,      _______,   _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LEFT  | /Space  /       \Enter \  |RIGHT |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};


#ifdef OLED_ENABLE

/* 64 * 64 logo */
static void render_logo(void) {
    static const char PROGMEM NALily58_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x80, 0xc0, 0xe0, 0x70, 0x38, 0xdc, 0x3e, 0x3e, 0xdc, 0x38, 0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x38, 0xdc, 0x3e, 0x3e, 0xdc, 0x38, 0x70, 0xe0, 0xc0, 0x80, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x38, 0x1c, 0x0e, 0x07, 
0x03, 0x01, 0xc0, 0x38, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0xb8, 0xc0, 0xe1, 0x73, 0x3f, 0x1e, 
0x1e, 0x3f, 0x73, 0xe1, 0xc0, 0xb8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xc0, 0x01, 0x03,  
0x07, 0x0e, 0x1c, 0x38, 0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x3f, 0xf9, 0xe1, 0x82, 0x02, 0x02, 


0x02, 0x1f, 0xe2, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x07, 0xef, 0x3f, 0xfb, 0xe3, 0x82, 
0x82, 0xe3, 0xfb, 0x3f, 0xef, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xe2, 0x1f, 0x02, 
0x02, 0x02, 0x82, 0xe1, 0xf9, 0x3f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x3e, 0xf8, 
0xe0, 0x00, 0x01, 0x3e, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3e, 0x01, 0x00, 0xe0, 0xfb, 0x3f, 
0x3f, 0xfb, 0xe0, 0x00, 0x01, 0x3e, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3e, 0x01, 0x00, 0xe0, 
0xf8, 0x3e, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
0x07, 0x1f, 0x7c, 0xf0, 0xc7, 0x78, 0x80, 0x80, 0x78, 0xc7, 0xf0, 0x7c, 0x1f, 0x07, 0x01, 0x00, 
0x00, 0x01, 0x07, 0x1f, 0x7c, 0xf0, 0xc7, 0x78, 0x80, 0x80, 0x78, 0xc7, 0xf0, 0x7c, 0x1f, 0x07, 
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x20, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 
0x20, 0x00, 0x00, 0x01, 0x07, 0x1f, 0x7f, 0x7f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1f, 0x7f, 0x7f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x80, 0x40, 0x40, 0x20, 0xe0, 0x20, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x10, 0x20, 0x20, 0x10, 0x0e, 0x01, 0x00, 0x07, 0x1c, 0x38, 0x07, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x30, 0x20, 0x20, 0x18, 0x04, 0x03, 0x02, 0x02, 0x3f, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  oled_write_raw_P(NALily58_logo, sizeof(NALily58_logo));
}



/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       80

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           256   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 64x22px */
                                                   {
                                                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0x1c, 0x1c, 0x02, 0x02, 0x05, 0x05, 0x02, 0x02, 0x24, 0x24, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0xa9, 0xa9, 0x1e, 0x1e, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0x10, 0x10, 0x08, 0x08, 0x68, 0x68, 0x10, 0x10, 0x08, 0x08, 0x04, 0x04, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x06, 0x06, 0x82, 0x82, 0x7c, 0x7c, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x04, 0x04, 0x0c, 0x0c, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x28, 0x28, 0x3e, 0x3e, 0x1c, 0x1c, 0x20, 0x20, 0x20, 0x20, 0x3e, 0x3e, 0x0f, 0x0f, 0x11, 0x11, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 64x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0x1c, 0x1c, 0x02, 0x02, 0x05, 0x05, 0x02, 0x02, 0x24, 0x24, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0xa9, 0xa9, 0x1e, 0x1e, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0x90, 0x90, 0x08, 0x08, 0x18, 0x18, 0x60, 0x60, 0x10, 0x10, 0x08, 0x08, 0x04, 0x04, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x0e, 0x0e, 0x82, 0x82, 0x7c, 0x7c, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x04, 0x04, 0x0c, 0x0c, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x28, 0x28, 0x3e, 0x3e, 0x1c, 0x1c, 0x20, 0x20, 0x20, 0x20, 0x3e, 0x3e, 0x0f, 0x0f, 0x11, 0x11, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 64x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xa0, 0xa0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x70, 0x70, 0x08, 0x08, 0x14, 0x14, 0x08, 0x08, 0x90, 0x90, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0xa4, 0xa4, 0x78, 0x78, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x08, 0x08, 0xfc, 0xfc, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x18, 0x18, 0xea, 0xea, 0x10, 0x10, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x1c, 0x1c, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x3c, 0x0f, 0x0f, 0x11, 0x11, 0x1f, 0x1f, 0x03, 0x03, 0x06, 0x06, 0x18, 0x18, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x3c, 0x0c, 0x0c, 0x12, 0x12, 0x1e, 0x1e, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 64x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0x10, 0x10, 0x28, 0x28, 0x10, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x48, 0x48, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x20, 0x20, 0xf8, 0xf8, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x10, 0x10, 0x30, 0x30, 0xd5, 0x5d, 0x20, 0x20, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x20, 0x20, 0x30, 0x30, 0x0c, 0x0c, 0x02, 0x02, 0x05, 0x05, 0x09, 0x09, 0x12, 0x12, 0x1e, 0x1e, 0x02, 0x02, 0x1c, 0x1c, 0x14, 0x14, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x2c, 0x2c, 0x32, 0x32, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 64x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0xc8, 0xc8, 0xb0, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x3c, 0x3c, 0x14, 0x14, 0x04, 0x04, 0x08, 0x08, 0x90, 0x90, 0x18, 0x18, 0x04, 0x04, 0x08, 0x08, 0xb0, 0xb0, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0xc4, 0xc4, 0xa4, 0xa4, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc8, 0xc8, 0x58, 0x58, 0x28, 0x28, 0x2a, 0x2a, 0x10, 0x10, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x0e, 0x09, 0x09, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x26, 0x26, 0x2b, 0x2b, 0x32, 0x32, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 64x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0x10, 0x10, 0x10, 0x10, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x78, 0x78, 0x28, 0x28, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x30, 0x30, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x11, 0x11, 0xf9, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x10, 0x10, 0xb0, 0xb0, 0x50, 0x50, 0x55, 0x55, 0x20, 0x20, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x0c, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x28, 0x28, 0x37, 0x37, 0x02, 0x02, 0x1e, 0x1e, 0x20, 0x20, 0x20, 0x20, 0x18, 0x18, 0x0c, 0x0c, 0x14, 0x14, 0x1e, 0x1e, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 64x22px */
                                                    {
                                                        0x00, 0x00, 0xc0, 0xc0, 0x20, 0x20, 0x10, 0x10, 0xd0, 0xd0, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x3c, 0x14, 0x14, 0x04, 0x04, 0x08, 0x08, 0x90, 0x90, 0x18, 0x18, 0x04, 0x04, 0x08, 0x08, 0xb0, 0xb0, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x11, 0x11, 0xf9, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc8, 0xc8, 0x48, 0x48, 0x28, 0x28, 0x2a, 0x2a, 0x10, 0x10, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x0c, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x28, 0x28, 0x37, 0x37, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x26, 0x26, 0x2b, 0x2b, 0x32, 0x32, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 64x22px */
                                                    {
                                                        0x00, 0x00, 0xe0, 0xe0, 0x10, 0x10, 0x10, 0x10, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x2c, 0x2c, 0x14, 0x14, 0x04, 0x04, 0x08, 0x08, 0x90, 0x90, 0x18, 0x18, 0x04, 0x04, 0x08, 0x08, 0xb0, 0xb0, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x11, 0x11, 0xf9, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0x48, 0x48, 0x28, 0x28, 0x2a, 0x2a, 0x10, 0x10, 0x0f, 0x0f, 0x20, 0x20, 0x4a, 0x4a, 0x09, 0x09, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x0c, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x28, 0x28, 0x37, 0x37, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x26, 0x26, 0x2b, 0x2b, 0x32, 0x32, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 64x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0x21, 0x21, 0xf0, 0xf0, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x01, 0x01, 0x80, 0x80, 0x80, 0x80, 0xab, 0xab, 0x04, 0x04, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x1c, 0x1c, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x3c, 0x0f, 0x0f, 0x11, 0x11, 0x1f, 0x1f, 0x02, 0x02, 0x06, 0x06, 0x18, 0x18, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x08, 0x38, 0x10, 0x10, 0x18, 0x18, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 64x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xa0, 0xa0, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0xc0, 0xc0, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x3e, 0x41, 0x41, 0xf0, 0xf0, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x55, 0x55, 0x82, 0x82, 0x7c, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x20, 0x20, 0x30, 0x30, 0x0c, 0x0c, 0x02, 0x02, 0x05, 0x05, 0x09, 0x09, 0x12, 0x12, 0x1e, 0x1e, 0x04, 0x04, 0x18, 0x18, 0x10, 0x10, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x28, 0x28, 0x34, 0x34, 0x06, 0x06, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[current_frame], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[current_frame], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[current_frame], ANIM_SIZE);
        }
    }

/*#    if OLED_TIMEOUT > 0
*    // the animation prevents the normal timeout from occuring
*    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
*        oled_off();
*        return;
*    } else {
*        oled_on();
*    }
*#    endif
*/
    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }
}

/* KEYBOARD PET END */

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

#ifdef OLED_ENABLE
__attribute__((weak))
bool process_record_oled(uint16_t keycode, keyrecord_t *record) { return true; }
#endif


/*declare boolean for jiggler*/
bool is_jiggling = false;

/*timers*/
uint32_t idle_timeout = 30000; // (after 30s)
uint32_t mouse_interval = 10000; // (every 10s)

static uint32_t idle_callback(uint32_t trigger_time, void* cb_arg) {
    // now idle
    if (is_jiggling){
        SEND_STRING(SS_TAP(X_F15));
        return mouse_interval;
    }
      return false;
 
}


/*Dynamic macro hooks to display on oled */

int8_t cached_direction;
int8_t stop_direction;
bool is_recording_1 = false;
bool is_recording_2 = false;

void dynamic_macro_record_start_user(int8_t direction) {
    cached_direction = direction;
    if (cached_direction == 1){
        is_recording_1 = true;
    } else if (cached_direction == -1){
        is_recording_2 == true;
    }
}

void dynamic_macro_record_end_user(int8_t direction) {
    stop_direction = direction;
    if (stop_direction == 1){
        is_recording_1 = false;
    } else if (stop_direction == -1){
        is_recording_2 = false;
    }
}


static void print_logo_narrow(void) {
    render_logo();

    /* wpm counter */
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(0, 11);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 10);
    oled_write(" WPM", false);

}

static void print_status_narrow(void) {
    /* Print current mode */

   oled_set_cursor(0, 0);

    /* Print current layer */
    oled_write_P(PSTR("Layer:\n "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LEFT:
            oled_write_P(PSTR("LEFT\n"), false);
            break;
        case _RIGHT:
            oled_write_P(PSTR("RIGHT\n"), false);
            break;
       default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    /* caps lock */
    oled_set_cursor(0, 3);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);


    /*Dynamic macros */

    oled_set_cursor(0, 5);
    if (cached_direction == 0) {
        oled_write_P(PSTR("    "), false);
    } else if (is_recording_1){
        oled_write_P(PSTR("REC1"), false);
    } else if (!is_recording_1 && cached_direction != 0){
        oled_write_P(PSTR("PLY1"), false);
    }

    oled_set_cursor(5, 5);
    if (cached_direction == 0) {
        oled_write_P(PSTR("    "), false);
    } else if (is_recording_2){
        oled_write_P(PSTR("REC2"), false);
    } else if (!is_recording_2 && cached_direction != 0){
        oled_write_P(PSTR("PLY2"), false);
    }

/*    oled_set_cursor(5, 5);
 *   switch (is_recording_2) {
 *       case 1:
 *           oled_write_P(PSTR("REC2"), false);
 *           break;
 *       case 0:
 *           oled_write_P(PSTR("PLY2"), false);
 *           break;
 *       default:
 *           oled_write_P(PSTR("    "), false);
 *           break;
 *      
 *  }
*/
    /*jiggler*/

    oled_set_cursor(0, 7);
    switch (is_jiggling) {
        case true:
            oled_write_P(PSTR("Jiggle"), false);
            break;
        default:
            oled_write_P(PSTR("      "), false);
   }


    /* KEYBOARD PET RENDER START */

    render_luna(0, 10);

    /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_0; }

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}

#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

// on every key event start or extend `idle_callback()` deferred execution after IDLE_TIMEOUT_MS
  static deferred_token idle_token = INVALID_DEFERRED_TOKEN;

      if (!extend_deferred_exec(idle_token, idle_timeout)) {
        idle_token = defer_exec(idle_timeout, idle_callback, NULL);
    }

  
  switch (keycode) {
      case NO_NOK:
            if (record->event.pressed) {
                SEND_STRING("," SS_TAP(X_SLSH));
            }

            break;
     
      case KC_JIGG:
            if (record->event.pressed) {
                    is_jiggling = !is_jiggling; /* flip boolean to true */
            }

            break;

    case DE_LEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_LEFT))));
            }

            break;

    case DE_RIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
            }

            break;   
    }
    
    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record)
            #ifdef OLED_ENABLE
            && process_record_oled(keycode, record)
            #endif
            ;

}
