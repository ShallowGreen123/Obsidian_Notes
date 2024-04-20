~~~ c
#include "timer_task.h"

void DLO_Main(void)
{
	while(1)
	{
		timer_task_loop(); // 1、程序会跳过这个函数，不会进入该函数
		if(SF_Erase_data_XXX == 0){
		// 省略
		}
	}
}
~~~


timer_task.c
~~~c
#include "timer_task.h"

void timer_task_loop(void)
{
    printf("timer_task_loop_xxx\n");
}
~~~

timer_task.h
~~~c
#ifndef _TIMER_TASK_H
#define _TIMER_TASK_H
void timer_task_loop(void);
#endif
~~~