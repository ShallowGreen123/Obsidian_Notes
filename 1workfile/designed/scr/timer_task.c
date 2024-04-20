

#define TIMER_TASK_C
#include <string.h>
#include "timer_task.h"

timer_task_t timer_task_handle;

// fun
void timer_task_set_tick(void)
{
    timer_task_handle.jiffies++;
}

uint32_t timer_tick_get(void)
{
    return timer_task_handle.jiffies;
}

uint32_t timer_tick_elaps(uint32_t prev_tick)
{
    uint32_t act_time = timer_tick_get();

    if (act_time >= prev_tick) {
        prev_tick = act_time - prev_tick;
    } else {
        prev_tick = UINT32_MAX - prev_tick + 1;
        prev_tick += act_time;
    }
    return prev_tick;
}

void timer_tick_delay_ms(uint32_t ms)
{
    uint32_t act_time = timer_tick_get();

    while (timer_tick_elaps(act_time) < ms)
        ;
}

void timer_task_init(void)
{
    timer_task_t *p = &timer_task_handle;
    p->jiffies      = 0;
    p->reg_cnt      = 0;
    memset((void *)p->reg_list, 0, sizeof(p->reg_list));
}

void timer_task_regster(timer_reg_cb cb, void *argv, uint32_t period)
{
    timer_task_t *p = &timer_task_handle;

    if (p->reg_cnt < TIMER_REG_CB_MAX) {
        p->reg_list[p->reg_cnt].reg_cb   = cb;
        p->reg_list[p->reg_cnt].argv     = argv;
        p->reg_list[p->reg_cnt].tick     = 0;
        p->reg_list[p->reg_cnt++].period = period;
    } else {
        // printf("TIMER_REG_CB_MAX \n");
    }
}

void timer_task_loop(void)
{
    int           i;
    timer_task_t *p = &timer_task_handle;

    for (i = 0; i < p->reg_cnt; i++) {
        if (timer_tick_elaps(p->reg_list[i].tick) > p->reg_list[i].period) {
            p->reg_list[i].reg_cb(p->reg_list[i].argv);
            p->reg_list[i].tick = p->jiffies;
        }
    }
}
