[micropython](https://github.com/micropython/micropython)
[lv_micropython](https://github.com/lvgl/lv_micropython)

# 1、micropython

Require
- esp-idf [[esp-idf 环境搭建]]
- esp-idf v4.4
- micropython source code

1. git clone micropython source code

GitHub address : https://github.com/micropython/micropython.git .
~~~
git clone https://github.com/micropython/micropython.git
~~~

Cloned versions later than `v1.19` are recommend.
~~~
$ git checkout -b v1.19 v1.19 
~~~

2. Micropython cross-compiler
~~~
$ cd mpy-cross
$ make
~~~

3. External dependencies
~~~
$ cd port/esp32
$ make submodules
$ make

make USER_C_MODULES=../../../examples/usercmodule/micropython.cmake
~~~

4. Edit `Makefile` file，example : esp32s3
~~~
$ cd port/esp32

open `Makefile`

line 6: BOARD ?= GENERIC_S3
line 12: PORT ?= /dev/ttyS10   # your USB
line 13: BAUD ?= 115200
~~~

5. Compile & Install
~~~
$ make
$ make erase
$ make deploy
~~~


---
~~~
测试已经可以使用的 micropython 程序

代码路径： C:\1Project\esp32\micropython
测试板子： esp32-mini-board

使用方法：
1$ cd mpy-cross
2$ make
3$ cd port/esp32
4$ make
5$ make USER_C_MODULES=../../../examples/usercmodule/micropython.cmake     
6$ idf.py -p /dev/ttyS9 -b 921600 flash

5: 添加自定义的方法

打开软件 Thonny
连接板子
~~~

~~~

~~~

