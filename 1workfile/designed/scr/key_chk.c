#include <string.h>
#include "key_chk.h"
#include "utlist.h"

#define KEY_CHK_TIME_STEP 1
#define KEY_CHK_RELEASE   (0)
#define KEY_CHK_PRESS     (!KEY_CHK_RELEASE)

key_chk_t key_chk_list[KEY_CHK_NUM];

key_chk_cb chk_sync_cb = NULL;
key_chk_cb error_handle_cb = NULL;

key_chk_cb click_cb = NULL;
key_chk_cb frist_long_press_cb = NULL;
key_chk_cb long_press_trig_cb = NULL;
key_chk_cb long_press_cb = NULL;
key_chk_cb release_cb = NULL;
key_chk_cb multi_click_cb = NULL;


void key_chk_sync(key_chk_cb cb)
{
    chk_sync_cb = cb;
}

void key_chk_error_handle(key_chk_cb cb)
{
    error_handle_cb = cb;
}

void key_chk_click_cb(key_chk_cb cb)
{
    click_cb = cb;
}

void key_chk_frist_long_press_cb(key_chk_cb cb)
{
    frist_long_press_cb = cb;
}

void key_chk_long_press_trig_cb(key_chk_cb cb)
{
    long_press_trig_cb = cb;
}

void key_chk_long_press_cb(key_chk_cb cb)
{
    long_press_cb = cb;
}

void key_chk_release_cb(key_chk_cb cb)
{
    release_cb = cb;
}

void key_chk_multi_click_cb(key_chk_cb cb)
{
    multi_click_cb = cb;
}

void key_chk_init(void)
{
    key_chk_t *key_tmp;

    memset((void *)key_chk_list, 0, sizeof(key_chk_list));

    for(int i = 0; i < KEY_CHK_NUM; i++){
        key_chk_list[i].KeyId = i;
        key_chk_list[i].KeySt = RELEASE;
    }
}

void key_chk_handle(void)
{
    key_chk_t *key_tmp;
    for(int i = 0; i < KEY_CHK_NUM; i++){

        key_tmp = &key_chk_list[i];
        if(chk_sync_cb){
            chk_sync_cb(key_tmp);
        }

        if(key_tmp->CurrVal == 0){
            if(key_tmp->KeySt == LONG_PRESS_TRIG){
                key_tmp->TimeLongPress = key_tmp->TimePress;
            }
            key_tmp->TimePress = 0;
        }
        if(key_tmp->CurrVal){
            key_tmp->TimePress += KEY_CHK_TIME_STEP;
        }

        if(key_tmp->KeySt == MULTI_CLICK){
            key_tmp->TimeRelease += KEY_CHK_TIME_STEP;
        }else{
            key_tmp->TimeRelease = 0;
        }

        switch (key_tmp->KeySt)
        {
        case RELEASE:
            key_tmp->ClickCnt = 0;
            if(key_tmp->CurrVal){
                key_tmp->KeySt = PRESS;
            }
            break;

        case PRESS:
            if(key_tmp->CurrVal == 0){
                key_tmp->KeySt = RELEASE;
            }else if(key_tmp->TimePress > KEY_CHK_CLICK_THRESHOLD){
                key_tmp->KeySt = LONG_PRESS;
                if(click_cb){
                    click_cb(key_tmp);
                }
            }
            break;

        case LONG_PRESS:
            if(key_tmp->CurrVal == 0){
                key_tmp->KeySt = MULTI_CLICK;
                key_tmp->ClickCnt++;
            }else if(key_tmp->TimePress > KEY_CHK_LONG_PRESS_THRESHOLD){
                key_tmp->KeySt = LONG_PRESS_TRIG;
                key_tmp->TimeMultiTrig = KEY_CHK_LONG_PRESS_TRIG_THRESHOLD;
                if(frist_long_press_cb){
                    frist_long_press_cb(key_tmp);
                }
            }
            break;

        case LONG_PRESS_TRIG:
            if(key_tmp->TimeMultiTrig > 0){
                key_tmp->TimeMultiTrig -= KEY_CHK_TIME_STEP;
            }else{
                key_tmp->TimeMultiTrig = KEY_CHK_LONG_PRESS_TRIG_THRESHOLD;
                if(long_press_trig_cb){
                    long_press_trig_cb(key_tmp);
                }
            }
            if(key_tmp->CurrVal == 0){
                key_tmp->KeySt = RELEASE;
                if(long_press_cb){
                    long_press_cb(key_tmp);
                }
                if(release_cb){
                    release_cb(key_tmp);
                }
            }
            break;

        case MULTI_CLICK:
            if(key_tmp->TimeRelease > KEY_CHK_MULTI_CLICK_THRESHOLD){
                key_tmp->KeySt = RELEASE;
                if(multi_click_cb){
                    multi_click_cb(key_tmp);
                }
                if(release_cb){
                    release_cb(key_tmp);
                }
            }else if(key_tmp->TimePress > KEY_CHK_LONG_PRESS_THRESHOLD){
                key_tmp->KeySt = LONG_PRESS;
            }
            break;
        
        default:
            if(error_handle_cb){
                error_handle_cb(key_tmp);
            }
            break;
        }

    }
}