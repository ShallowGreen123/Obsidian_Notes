1、使用 stm32CubeMX 生成 FreeRTOS 的代码后，在 Clion 编译不通过，出现错误
>Error: selected FPU does not support instruction -- `vstmdbeq r0!,{s16-s31}'

解决方法，在 cmake 中启用 FPU(浮点运算单元)
~~~
#Uncomment for hardware floating point  
add_compile_definitions(ARM_MATH_CM4;ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING)  
add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)  
add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
~~~

2、clion 获取寄存器 https://blog.csdn.net/qq_39828850/article/details/130627833

3、printf 不能打印浮点数的问题，在 cmake 中添加编译条件
~~~
set(COMMON_FLAGS "-specs=nosys.specs -specs=nano.specs -u _printf_float -u _scanf_float")
~~~