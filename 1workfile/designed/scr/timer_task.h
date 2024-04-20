#ifndef _TIMER_TASK_H
#define _TIMER_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef TIMER_TASK_C
#define EXT_TIMER_TASK
#else
#define EXT_TIMER_TASK extern
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>

/*********************
 *      DEFINES
 *********************/
#define TIMER_REG_CB_MAX 10

/**********************
 *      TYPEDEFS
 **********************/
typedef void (*timer_reg_cb)(void *argv);

typedef struct _timer_reg_item_t {
    void        *argv;
    timer_reg_cb reg_cb;
    uint32_t     period;
    uint32_t     tick;
} timer_reg_item_t;

typedef struct _timer_task_t {
    uint16_t         reg_cnt;
    uint32_t         jiffies;
    timer_reg_item_t reg_list[TIMER_REG_CB_MAX];
} timer_task_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
EXT_TIMER_TASK void timer_task_init(void);
EXT_TIMER_TASK void timer_task_regster(timer_reg_cb cb, void *argv, uint32_t period);
EXT_TIMER_TASK void timer_task_loop(void);
EXT_TIMER_TASK void timer_task_set_tick(void);

/* delay */
EXT_TIMER_TASK void timer_tick_delay_ms(uint32_t ms);
EXT_TIMER_TASK uint32_t timer_tick_elaps(uint32_t prev_tick);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*_TIMER_TASK_H*/
