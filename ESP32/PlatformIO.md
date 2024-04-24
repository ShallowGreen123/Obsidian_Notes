## 📗 1、platformio.ini 配置文件

在 PIO 的配置文件中，通常有如下的配置，在 `[env]` 指明一些工程的相关属性；

~~~
[platformio]              
boards_dir = boards             ; 1️⃣
src_dir = examples/demo         ; 2️⃣

[env]
platform = espressif32@6.5.0    ; 3️⃣
board = esp32dev                ; 4️⃣
framework = arduino             ; 5️⃣

...
~~~

### 1️⃣ boards_dir

`boards_dir` 指明与开发板相关信息的路径，这个路径下的文件通常是以 `.json` 为后缀的文件；PIO 默认有一些板子的配置信息，默认情况下 `boards_dir` 指向路径`C:\Users\yourname\.platformio\platforms\espressif32@6.3.0\boards` ，在这里可以看到很多的 `.json` 文件，这些都是 PIO 预设的一些板子配置信息；其中`espressif32@6.3.0` 这个在 `3️⃣` 中的 `platform` 指明；

一般情况下，也可以不用指明，使用 PIO 预设的 `.json` 配置文件，并在 `4️⃣` 中指明预设的文件名即可；

### 2️⃣ src_dir

指明成功源码存放的路径，默认情况下，`src_dir` 指向在当前的工程的 `src` 文件夹；

### 3️⃣ platform ❗❗❗

指明 PIO 默认运行编译 esp32 环境的版本；在 GitHub 上面可以看到很多不同的版本，地址在 [platform-espressif32](https://github.com/platformio/platform-espressif32)；以版本 6.3.0 为例，在 PIO 下载后会将存放在本机路径 `C:\Users\yourname\.platformio\platforms\espressif32@6.3.0` 下；

打开查看这个文件夹，会有如下的一些文件和文件夹

~~~
.github
boards : PIO 预设的一些开发板的信息，默认情况下 boards_dir 会指向这里；
builder ：一些构建环境脚本，它们下载所需要的编译工具链、IDF、Arduion库等等；
examples ：放了一些例子，可以看看它们的 `.ini` 是如何配置的；
monitor ：串口过滤器，在程序异常时，可以打印程序调用的堆栈，Backtrace错误回溯；
platform.json ：为 builder 指明下载那些版本，这个需要多多关注；
platform.py
~~~

查看 `platform.json` 主要查看 `framework-arduinoespressif32` 和 `framework-espidf` 选项，它们分别分表了 PIO 下的  Arduion 框架包和 IDF 框架包，可以在这里看到下载框架的版本，路径通常为 `C:\Users\yourname\.platformio\packages`;

### 4️⃣ board

- boards_dir 没有指定，则只能选择 PIO 预设的 `.json` 配置文件；
- boards_dir 已经指定，则只能选择指定路径下面的 `.json` 配置文件；
### 5️⃣framework

选择工程应用的框架，通常可以选择 arduino 和 espidf 框架；

## 📗2、