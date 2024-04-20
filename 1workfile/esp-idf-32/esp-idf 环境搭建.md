refer to：
[gitee](https://gitee.com/EspressifSystems/esp-gitee-tools/blob/master/docs/README-submodule-update.md)
[espressif](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/linux-macos-setup.html)

1、Install WSL
[[WSL install]]

2、Install Prerequisites
~~~
sudo apt-get update

sudo apt-get install git wget flex bison gperf python3 python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
~~~

3、Get eps-idf
Default installation location is `~/esp`
~~~
mkdir -p ~/esp
cd ~/esp
git clone https://gitee.com/EspressifSystems/esp-gitee-tools.git
git clone https://gitee.com/EspressifSystems/esp-idf.git
~~~

4、Updata submodules
~~~
cd esp-gitee-tools
./submodule-update.sh ~/esp/esp-idf
~~~

5、Set up the tools
~~~
cd ~/esp/esp-idf
export IDF_GITHUB_ASSETS="dl.espressif.com/github_assets"
./install.sh
~~~

6、Set up the environment values
1. Copy and paste the following command to your shell’s profile (`.profile`, `.bashrc`, `.zprofile`, etc.)
~~~
alias get_idf='. $HOME/esp/esp-idf/export.sh'
~~~
2.  Refresh the configuration by restarting the terminal session or by running `source [path to profile]`, for example,  ***source ~/.bashrc.***

把上面 1 的

7、Frist Steps on esp-idf

see [乐鑫官网教程](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/linux-macos-setup.html)

8、Other
- 设置目标芯片
==idf.py set-target esp32-s3==
- 运行工程配置工具 
==idf.py menuconfig==

~~~
The behavior of `idf.py set-target` command is equivalent to:
1.  clearing the build directory (`idf.py fullclean`)
2.  removing the sdkconfig file (`mv sdkconfig sdkconfig.old`)
3.  configuring the project with the new target (`idf.py -DIDF_TARGET=esp32 reconfigure`)
4. 
~~~
- 编译烧录工程
==idf.py build==
- 下载
==idf.py -p /dev/ttyS3 -b 921600 flash==
- 查看输出
==idf.py -p /dev/ttyS3 monitor==

git describe --tags --dirty // 查看esp-idf版本

/mnt/c/lv_micropython/ports/unix$ ./micropython ../../lvgl_SDL/lvgl_test.py

