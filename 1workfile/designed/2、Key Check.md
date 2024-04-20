源码 
[key_chk.c](scr/key_chk.c)
[key_chk.h](scr/key_chk.h)

# 简介
对通用按键模块进行封装，实现按键的消抖、点击、长按、连点功能，支持多个按键检测，并独立检测每一个按键，采用回调函数的形式对不同按键的事件进行处理。


# 实现
按键状态变化如下图，绿色部分为按键状态，其中几个关键的时间变量的定义为：
~~~
T1：按下到松开的时间  
T2：判定为长按的时间  
T3：判定为长按触发的时间  
T4：松开按键的时间  
T5：判定为机械抖动的时间阈值
~~~

![Pasted image 20230509114350](img/Pasted%20image%2020230509114350.png)

从时间轴的角度可以描述成如下所示，注意时间T代表的含义，其中箭头表示按键触发了一个事件。所以在使用这个 key_chk 按键检测模块时，可以根据具体的需求，注册相应的回调函数。

![Pasted image 20230509115226](img/Pasted%20image%2020230509115226.png)


# API
~~~C
#define KEY_CHK_NUM 3 // 如果你有 N 个按键，将此设为 N

#define KEY_CHK_CLICK_THRESHOLD 20

#define KEY_CHK_LONG_PRESS_THRESHOLD 800

#define KEY_CHK_MULTI_CLICK_THRESHOLD 200

#define KEY_CHK_LONG_PRESS_TRIG_THRESHOLD 300


void key_chk_init(void); // 初始化函数，必须调用

void key_chk_handle(void); // 按键处理函数，需要循环调用，必须调用

void key_chk_sync(key_chk_cb cb); // 按键映射函数，必须注册

void key_chk_error_handle(key_chk_cb cb);

void key_chk_click_cb(key_chk_cb cb);

void key_chk_frist_long_press_cb(key_chk_cb cb);

void key_chk_long_press_trig_cb(key_chk_cb cb);

void key_chk_long_press_cb(key_chk_cb cb);

void key_chk_release_cb(key_chk_cb cb);

void key_chk_multi_click_cb(key_chk_cb cb);
~~~

# 例子

下面是检测单个按键 ‘A’ 的点击事件
~~~c
void my_key_read(key_chk_t *key)
{
	if(key->KeyId == 0){ // 把按键 A 的 id 映射为 0
		key->CurrVal = your_read_GPIO_pin(); // 调用读按键 A 函数
	}
}

void my_key_click(key_chk_t *key)
{
	if(key->KeyId == 0){
		printf("Key0 pressed\n");
	}
}

int main()
{
	key_chk_init();
	key_chk_sync(my_key_read); // 注册按键映射关系回调函数
	key_chk_click_cb(my_key_click); // 注册点击事件回调函数

	while(1) {
		key_chk_handle(); 
	}
}
~~~

下面是检测按键 ‘A’ 和 ‘B’ 的点击和释放事件
~~~c
void my_key_read(key_chk_t *key)
{
	if(key->KeyId == 0){ // 把按键 A 的 id 映射为 0
		key->CurrVal = your_read_GPIO_pinA(); // 调用读按键 A 函数
	}
	if(key->KeyId == 1){ // 把按键 B 的 id 映射为 1
		key->CurrVal = your_read_GPIO_pinB(); // 调用读按键 B 函数
	}
}

void my_key_click(key_chk_t *key)
{
	if(key->KeyId == 0){
		printf("Key0 pressed\n");
	}
	if(key->KeyId == 1){
		printf("Key1 pressed\n");
	}
}

void my_key_released(key_chk_t *key)
{
	if(key->KeyId == 0){
		printf("Key0 released\n");
	}
	if(key->KeyId == 1){
		printf("Key1 released\n");
	}
}

int main()
{
	key_chk_init();
	key_chk_sync(my_key_read); // 注册按键映射关系回调函数
	key_chk_click_cb(my_key_click); // 注册点击事件回调函数
	key_chk_release_cb(my_key_released); // 注册释放事件回调函数
	
	while(1) {
		key_chk_handle(); 
	}
}
~~~

以此类推，想要检测更多的按键，并触发不同的事件，则可以在 key_chk_sync 回调函数中映射更多的按键，和注册不同的事件回调函数。
~~~c
void my_key_read(key_chk_t *key)
{
	if(key->KeyId == 0){ // 把按键 A 的 id 映射为 0
		key->CurrVal = your_read_GPIO_pinA(); // 调用读按键 A 函数
	}
	if(key->KeyId == 1){ // 把按键 B 的 id 映射为 1
		key->CurrVal = your_read_GPIO_pinB(); // 调用读按键 B 函数
	}
	
	......
	
	if(key->KeyId == N){ // 把按键 X 的 id 映射为 N
		key->CurrVal = your_read_GPIO_pinN(); // 调用读按键 N 函数
	}
}

void my_key_click(key_chk_t *key)
{
	if(key->KeyId == 0){
		printf("Key0 pressed\n");
	}
	if(key->KeyId == 1){
		printf("Key1 pressed\n");
	}
	
	......
	
	if(key->KeyId == N){
		printf("KeyN pressed\n");
	}
}

void my_key_released(key_chk_t *key)
{
	if(key->KeyId == 0){
		printf("Key0 released\n");
	}
	if(key->KeyId == 1){
		printf("Key1 released\n");
	}

	......
	
	if(key->KeyId == N){
		printf("KeyN released\n");
	}
}

int main()
{
	key_chk_init();
	key_chk_sync(my_key_read); // 注册按键映射关系回调函数
	key_chk_click_cb(my_key_click); // 注册点击事件回调函数
	key_chk_release_cb(my_key_released); // 注册释放事件回调函数
	
	while(1) {
		key_chk_handle(); 
	}
}
~~~