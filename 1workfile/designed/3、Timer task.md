源码
[timer_task](scr/timer_task.c)
[timer_task](scr/timer_task.h)

# 简介
实现一个简单非抢占式的时间片调度，用于定时的处理任务，提高 CPU 的利用效率。

# 实现
结构体定义
~~~c
typedef struct _timer_reg_item_t {
    void        *argv;  // 任务回调函数参数
    timer_reg_cb reg_cb; // 任务回调函数
    uint32_t     period; // 每隔 period 毫秒执行 reg_cb
    uint32_t     tick; // 计时器
} timer_reg_item_t;

typedef struct _timer_task_t {
    uint16_t         reg_cnt; // 已注册的任务数量
    uint32_t         jiffies; // 计时器
    timer_reg_item_t reg_list[TIMER_REG_CB_MAX]; // 任务回调函数列表
} timer_task_t;
~~~

如下所示，
当 jiffies > period3 时，执行任务3的回调函数，tick3 = jiffies；
当 jiffies > period1时， 执行任务1的回调函数，tick1 = jiffies；
当 jiffies > period2 时，执行任务2的回调函数，tick2 = jiffies；
每隔 300ms 执行一次任务 3；
每隔 400ms 执行一次任务 1；
每隔 600ms 执行一次任务 2；
![](img/Pasted%20image%2020230512182109.png)

# API
~~~c
void timer_task_init(void); // 初始化，必须调用
void timer_task_regster(timer_reg_cb cb, void *argv, uint32_t period); // 任务注册
void timer_task_loop(void); // 任务处理，必要循环调用
void timer_task_set_tick(void); // 放在定时器中调用
  
/* delay */
void timer_tick_delay_ms(uint32_t ms);
uint32_t timer_tick_get(void);
uint32_t timer_tick_elaps(uint32_t prev_tick);
~~~

# 例子
~~~c
void timer_task_test1(void *agrv)
{
	static int sec = 0;
	printf("sec = %d\n", sec++);
}

void timer_task_test2(void *agrv)
{
	int param = *((int *)argv);
	printf("param = %d\n", param);
}


int main()
{
	int param = 100;
	
	timer_task_init();
	timer_task_regster(timer_task_test1, NULL, 1000); // 1s执行一次，无参数
	timer_task_regster(timer_task_test2, &param, 30); // 30ms执行一次，参数param

	while(1){
		timer_task_loop();
	}
}


void TIMXXX_IRQHandler(void) // 1ms 定时器中断
{
	timer_task_set_tick();
}
~~~