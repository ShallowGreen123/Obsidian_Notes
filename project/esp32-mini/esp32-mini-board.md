---
~
---
esp-idf v4.4
micropython v1.19

编译固件
~~~
工程路径：D:\Project\esp32_mpy\esp32_mini_board


使用方法：
1$ cd mpy-cross
2$ make
3$ cd port/esp32
4$ make
5$ make USER_C_MODULES=../../../examples/usercmodule/micropython.cmake     
6$ idf.py -p /dev/ttyS9 -b 921600 flash

$ get_idf      //
$ make         // 
$ make deploy  //

~~~

# 关于 mainfest.py

mainfest.py 指定包含哪些 python 模块和冻结那些模块。在为设备构建固件的时候，编译过程中包含以下组件：
- micropython 核心虚拟机
- 端口特定的系统代码和驱动程序，用于与固件针对的微控制器/设备进行交互
- 标准的内置模块，如 sys
- 扩展的内置模块，如 json 、machine
- 用 C/C++ 编写的额外模块
- 用 python 编写的额外模块

## freeze(path, script=None, opt=0)

path 的特殊路径：
- `$(MPY_DIR)` – path to the micropython repo.
- `$(MPY_LIB_DIR)` – path to the micropython-lib submodule. Prefer to use `require()`.
- `$(PORT_DIR)` – path to the current port (e.g. `ports/stm32`)
- `$(BOARD_DIR)` – path to the current board (e.g. `ports/stm32/boards/PYBV11`)

script： 如果 script 等于 None，则路径中的所有文件都会被冻结

opt：是将 .py 编译为 .mpy 是传递给 mpy-cross 的优化级别

## include(mainfest, **kwargs)

包含另一个 mainfest




# 其他
flash_download_tool 工具固件下载
![](Pasted%20image%2020240219214833.png)