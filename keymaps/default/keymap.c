// #include <cstdint>
#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"

#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 45 //Switch to fast animation when over words per minute

#ifdef OLED_ENABLE
#include "animations/demon.c"
#endif

#define CTL_ESC LCTL_T(KC_ESC)
#define GUI_A   LGUI_T(KC_A)
#define ALT_S   LALT_T(KC_S)
#define CTL_D   LCTL_T(KC_D)
#define SFT_F   LSFT_T(KC_F)
#define SFT_J   RSFT_T(KC_J)
#define CTL_K   RCTL_T(KC_K)
#define ALT_L   RALT_T(KC_L)
#define GUI_SCN RGUI_T(KC_SCLN)
#define SFT_TAB  LSFT_T(KC_TAB)
#define SPC_NAV LT(_RAISE, KC_SPC)
#define SPC_NUM LT(_LOWER, KC_SPC)
#define ENT_NUM LT(_LOWER, KC_ENT)
#define ENT_NAV LT(_RAISE, KC_ENT)
#define BS_MED LT(_ADJUST, KC_BSPC)
#define TAB_MED LT(_ADJUST, KC_TAB)
#define V_CBR TD(V_LCBR)
#define B_CBR TD(B_RCBR)
#define N_BRC TD(N_LBRC)
#define M_BRC TD(M_RBRC)

enum layer_number {
  _QWERTY = 0,
  _GAME,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
    KC_COLEMAK,
    KC_GAME,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND
};

enum {
    N_LBRC,
    M_RBRC,
    V_LCBR,
    B_RCBR,
};

const custom_shift_key_t custom_shift_keys[] = {
    {TL_LOWR, TL_UPPR},
    {TL_UPPR, TL_LOWR},
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────┬───────┬───────┬───────┬───────┬───────┐                  ┌───────┬───────┬───────┬───────┬───────┬───────┐
//    │ QK_GESC │   1   │   2   │   3   │   4   │   5   │                  │   6   │   7   │   8   │   9   │   0   │   -   │
//    ├─────────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
//    │   tab   │   q   │   w   │   e   │   r   │   t   │                  │   y   │   u   │   i   │   o   │   p   │ bspc  │
//    ├─────────┼───────┼───────┼───────┼───────┼───────┤                  ├───────┼───────┼───────┼───────┼───────┼───────┤
//    │   esc   │   a   │   s   │   d   │   f   │   g   │                  │   h   │   j   │   k   │   l   │   ;   │   '   │
//    ├─────────┼───────┼───────┼───────┼───────┼───────┼──────┐   ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
//    │   tab   │   z   │   x   │   c   │  v/{  │  b/}  │ mute │   │  no   │  n/[  │  m/]  │   ,   │   .   │   /   │ rsft  │
//    └─────────┴───────┼───────┼───────┼───────┼───────┼──────┤   ├───────┼───────┼───────┼───────┼───────┼───────┴───────┘
//                      │ lgui  │ lalt  │  tab  │  spc  │ spc  │   │  ent  │  ent  │ bspc  │ ralt  │ rgui  │
//                      └───────┴───────┴───────┴───────┴──────┘   └───────┴───────┴───────┴───────┴───────┘
[_QWERTY] = LAYOUT(
  QK_GESC , KC_1  , KC_2    , KC_3    , KC_4    , KC_5    ,                         KC_6    , KC_7   , KC_8    , KC_9    , KC_0    , KC_MINUS,
  KC_TAB  , KC_Q  , KC_W    , KC_E    , KC_R    , KC_T    ,                         KC_Y    , KC_U   , KC_I    , KC_O    , KC_P    , KC_BSPC ,
  CTL_ESC , GUI_A , ALT_S   , CTL_D   , SFT_F   , KC_G    ,                         KC_H    , SFT_J  , CTL_K   , ALT_L   , GUI_SCN , KC_QUOT ,
  SFT_TAB , KC_Z  , KC_X    , KC_C    , V_CBR   , B_CBR   , KC_MUTE ,     XXXXXXX , N_BRC   , M_BRC  , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
                    KC_LGUI , KC_LALT , TAB_MED , SPC_NAV , SPC_NUM ,     ENT_NUM , ENT_NAV , BS_MED , KC_RALT , KC_RGUI
),

//    ┌───────┬───────┬───────┬───────┬───────┬───────┐                 ┌───────┬───────┬───────┬───────┬───────┬───────┐
//    │   `   │   1   │   2   │   3   │   4   │   5   │                 │   6   │   7   │   8   │   9   │   0   │   -   │
//    ├───────┼───────┼───────┼───────┼───────┼───────┤                 ├───────┼───────┼───────┼───────┼───────┼───────┤
//    │  tab  │   q   │   w   │   e   │   r   │   t   │                 │   y   │   u   │   i   │   o   │   p   │ bspc  │
//    ├───────┼───────┼───────┼───────┼───────┼───────┤                 ├───────┼───────┼───────┼───────┼───────┼───────┤
//    │  esc  │   a   │   s   │   d   │   f   │   g   │                 │   h   │   j   │   k   │   l   │   ;   │   '   │
//    ├───────┼───────┼───────┼───────┼───────┼───────┼──────┐   ┌──────┼───────┼───────┼───────┼───────┼───────┼───────┤
//    │  tab  │   z   │   x   │   c   │   v   │   b   │ mute │   │  no  │   n   │   m   │   ,   │   .   │   /   │ rsft  │
//    └───────┴───────┼───────┼───────┼───────┼───────┼──────┤   ├──────┼───────┼───────┼───────┼───────┼───────┴───────┘
//                    │ lgui  │ lalt  │  spc  │ lctl  │ lowr │   │ uppr │ rctl  │  ent  │ ralt  │ rgui  │
//                    └───────┴───────┴───────┴───────┴──────┘   └──────┴───────┴───────┴───────┴───────┘
[_GAME] = LAYOUT(
  KC_GRV  , KC_1 , KC_2    , KC_3    , KC_4   , KC_5    ,                         KC_6    , KC_7   , KC_8    , KC_9    , KC_0    , KC_MINUS,
  KC_TAB  , KC_Q , KC_W    , KC_E    , KC_R   , KC_T    ,                         KC_Y    , KC_U   , KC_I    , KC_O    , KC_P    , KC_BSPC ,
  CTL_ESC , KC_A , KC_S    , KC_D    , KC_F   , KC_G    ,                         KC_H    , KC_J   , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
  SFT_TAB , KC_Z , KC_X    , KC_C    , KC_V   , KC_B    , KC_MUTE ,     XXXXXXX , KC_N    , KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
                   KC_LGUI , KC_LALT , KC_SPC , KC_LCTL , TL_LOWR ,     TL_UPPR , KC_RCTL , KC_ENT , KC_RALT , KC_RGUI
),

//    ┌─────┬────┬─────┬─────┬─────┬─────┐               ┌─────┬─────┬───────┬─────┬─────┬─────┐
//    │  `  │ f1 │ f2  │ f3  │ f4  │ f5  │               │ f6  │ f7  │  f8   │ f9  │ f10 │ f11 │
//    ├─────┼────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼───────┼─────┼─────┼─────┤
//    │     │ !  │  @  │  #  │  $  │  %  │               │  ^  │  &  │   *   │  (  │  )  │     │
//    ├─────┼────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼───────┼─────┼─────┼─────┤
//    │     │ 1  │  2  │  3  │  4  │  5  │               │  6  │  7  │   8   │  9  │  0  │  |  │
//    ├─────┼────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼─────┼─────┼───────┼─────┼─────┼─────┤
//    │     │ =  │  -  │  +  │  {  │  }  │     │   │     │  [  │  ]  │   ;   │  :  │  \  │     │
//    └─────┴────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼───────┼─────┼─────┴─────┘
//               │     │     │     │     │     │   │     │     │     │       │     │
//               └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴───────┴─────┘
[_LOWER] = LAYOUT(
  KC_GRV  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                         KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11 ,
  _______ , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,                         KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , _______,
  _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_PIPE,
  _______ , KC_EQL  , KC_MINS , KC_PLUS , KC_LCBR , KC_RCBR , _______ ,     _______ , KC_LBRC , KC_RBRC , KC_SCLN , KC_COLN , KC_BSLS , _______,
                      _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
),

//    ┌─────┬──────┬───────┬──────┬─────────┬─────────┐               ┌──────┬──────┬──────┬──────┬──────┬──────┐
//    │     │      │       │      │         │         │               │      │      │      │      │      │      │
//    ├─────┼──────┼───────┼──────┼─────────┼─────────┤               ├──────┼──────┼──────┼──────┼──────┼──────┤
//    │     │ ins  │ nXTWD │ end  │ CW_TOGG │   no    │               │ C(c) │ pgup │ home │ ent  │ C(v) │ bspc │
//    ├─────┼──────┼───────┼──────┼─────────┼─────────┤               ├──────┼──────┼──────┼──────┼──────┼──────┤
//    │     │ end  │ lctl  │ pgdn │ MS_BTN1 │ MS_BTN2 │               │ left │ down │  up  │ rght │ del  │ bspc │
//    ├─────┼──────┼───────┼──────┼─────────┼─────────┼─────┐   ┌─────┼──────┼──────┼──────┼──────┼──────┼──────┤
//    │     │ C(z) │ C(x)  │ C(c) │  C(v)   │  pRVWD  │     │   │     │  no  │ home │  no  │ end  │  no  │      │
//    └─────┴──────┼───────┼──────┼─────────┼─────────┼─────┤   ├─────┼──────┼──────┼──────┼──────┼──────┴──────┘
//                 │       │      │         │         │     │   │     │      │      │      │      │
//                 └───────┴──────┴─────────┴─────────┴─────┘   └─────┴──────┴──────┴──────┴──────┘
[_RAISE] = LAYOUT(
  _______ , _______ , _______  , _______ , _______ , _______  ,                         _______ , _______ , _______ , _______ , _______ , _______,
  _______ , KC_INS  , KC_NXTWD , KC_END  , CW_TOGG , XXXXXXX  ,                         C(KC_C) , KC_PGUP , KC_HOME , KC_ENT  , C(KC_V) , KC_BSPC,
  _______ , KC_END  , KC_LCTL  , KC_PGDN , MS_BTN1 , MS_BTN2  ,                         KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_DEL  , KC_BSPC,
  _______ , C(KC_Z) , C(KC_X)  , C(KC_C) , C(KC_V) , KC_PRVWD , _______ ,     _______ , XXXXXXX , KC_HOME , XXXXXXX , KC_END  , XXXXXXX , _______,
                      _______  , _______ , _______ , _______  , _______ ,     _______ , _______ , _______ , _______ , _______
),

//    ┌─────────┬──────────┬─────────┬─────────┬─────────┬─────┐               ┌─────┬──────┬──────┬──────┬────┬────┐
//    │   no    │    no    │   no    │   no    │   no    │ no  │               │ no  │  no  │  no  │  no  │ no │ no │
//    ├─────────┼──────────┼─────────┼─────────┼─────────┼─────┤               ├─────┼──────┼──────┼──────┼────┼────┤
//    │ QK_BOOT │   g  AME │ qWERTY  │ cOLEMAK │ CG_TOGG │ no  │               │ no  │  no  │  no  │  no  │ no │ no │
//    ├─────────┼──────────┼─────────┼─────────┼─────────┼─────┤               ├─────┼──────┼──────┼──────┼────┼────┤
//    │   no    │    no    │ CG_TOGG │   no    │   no    │ no  │               │ no  │ vold │ volu │ mute │ no │ no │
//    ├─────────┼──────────┼─────────┼─────────┼─────────┼─────┼─────┐   ┌─────┼─────┼──────┼──────┼──────┼────┼────┤
//    │   no    │    no    │   no    │   no    │   no    │ no  │ no  │   │ no  │ no  │ mprv │ mply │ mnxt │ no │ no │
//    └─────────┴──────────┼─────────┼─────────┼─────────┼─────┼─────┤   ├─────┼─────┼──────┼──────┼──────┼────┴────┘
//                         │         │         │         │     │     │   │     │     │      │      │      │
//                         └─────────┴─────────┴─────────┴─────┴─────┘   └─────┴─────┴──────┴──────┴──────┘
[_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX    , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  QK_BOOT , KC_GAME , KC_QWERTY , KC_COLEMAK , CG_TOGG , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , CG_TOGG   , XXXXXXX    , XXXXXXX , XXXXXXX ,                         XXXXXXX , KC_VOLD , KC_VOLU , KC_MUTE , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX    , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , KC_MPRV , KC_MPLY , KC_MNXT , XXXXXXX , XXXXXXX,
                      _______   , _______    , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // New animation
    oled_render_anim();
    // If you want to change the display of OLED, you need to change here

    // Old config
    // oled_write_ln(read_layer_state(), false);
    // oled_write_ln(read_keylog(), false);
    // oled_write_ln(read_keylogs(), false);

    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    [V_LCBR] = ACTION_TAP_DANCE_TAP_HOLD(KC_V, KC_LCBR),
    [B_RCBR] = ACTION_TAP_DANCE_TAP_HOLD(KC_B, KC_RCBR),
    [N_LBRC] = ACTION_TAP_DANCE_TAP_HOLD(KC_N, KC_LBRC),
    [M_RBRC] = ACTION_TAP_DANCE_TAP_HOLD(KC_M, KC_RBRC),
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }

    if (!process_custom_shift_keys(keycode, record))
    {
        return false;
    }

    tap_dance_action_t *action;

    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        case KC_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case TD(V_LCBR):
        case TD(B_RCBR):
        case TD(N_LBRC):
        case TD(M_RBRC):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(V_LCBR):
        case TD(B_RCBR):
        case TD(N_LBRC):
        case TD(M_RBRC):
            return TAPPING_TERM - 75;
        default:
            return TAPPING_TERM;
    }
}
