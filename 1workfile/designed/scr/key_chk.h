#ifndef _KEY_CHK_H
#define _KEY_CHK_H

#ifdef __cplusplus
extern "C"
{
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>

/*********************
 *      DEFINES
 *********************/
#define KEY_CHK_NUM 3

#define KEY_CHK_CLICK_THRESHOLD 20
#define KEY_CHK_LONG_PRESS_THRESHOLD 800
#define KEY_CHK_MULTI_CLICK_THRESHOLD 200
#define KEY_CHK_LONG_PRESS_TRIG_THRESHOLD 300

/**********************
 *      TYPEDEFS
 **********************/
typedef enum {
    RELEASE = 0,
    PRESS,
    LONG_PRESS,
    LONG_PRESS_TRIG,
    MULTI_CLICK,
}key_state_e;

typedef struct key_chk
{
    uint8_t KeyId;
    uint8_t CurrVal;
    uint16_t ClickCnt;

    uint32_t TimePress;
    uint32_t TimeRelease;
    uint32_t TimeLongPress;
    uint32_t TimeMultiTrig;
    key_state_e KeySt;
}key_chk_t;

typedef void (*key_chk_cb)(key_chk_t *key);

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void key_chk_init(void); 
void key_chk_handle(void);
void key_chk_sync(key_chk_cb cb); 
void key_chk_error_handle(key_chk_cb cb); 

void key_chk_click_cb(key_chk_cb cb);
void key_chk_frist_long_press_cb(key_chk_cb cb);
void key_chk_long_press_trig_cb(key_chk_cb cb);
void key_chk_long_press_cb(key_chk_cb cb);
void key_chk_release_cb(key_chk_cb cb);
void key_chk_multi_click_cb(key_chk_cb cb);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*_KEY_CHK_H*/
