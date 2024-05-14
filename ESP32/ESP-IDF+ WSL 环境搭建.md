## 📗 1. ESP-IDF+ WSL Install
refer to：
[gitee](https://gitee.com/EspressifSystems/esp-gitee-tools/blob/master/docs/README-submodule-update.md)
[espressif](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/linux-macos-setup.html)

1、Install WSL
[[WSL install]]

2、Install Prerequisites
~~~
sudo apt-get update

sudo apt-get install git wget flex bison gperf python3 python3-pip python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
~~~

3、Get eps-idf
Default installation location is `~/esp`
~~~
mkdir -p ~/esp
cd ~/esp
git clone https://gitee.com/EspressifSystems/esp-gitee-tools.git
git clone -b v4.4 https://gitee.com/EspressifSystems/esp-idf.git
git checkout v4.4
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
`idf.py set-target esp32-s3` 
- 运行工程配置工具 
`idf.py menuconfig`

~~~
The behavior of `idf.py set-target` command is equivalent to:
1.  clearing the build directory (`idf.py fullclean`)
2.  removing the sdkconfig file (`mv sdkconfig sdkconfig.old`)
3.  configuring the project with the new target (`idf.py -DIDF_TARGET=esp32 reconfigure`)
4. 
~~~
- 编译烧录工程
`idf.py build`
- 下载
`idf.py -p /dev/ttyS3 -b 921600 flash`
- 查看输出
`idf.py -p /dev/ttyS3 monitor`

git describe --tags --dirty // 查看esp-idf版本

## 2. 📗 ESP-IDF Different Version

在 esp-idf 的开发过程中可能会遇到需要使用不同版本的 idf 的问题，如何对 idf 的多版本进行管理；

### 2.1 IDF 环境文件结构

在 Linux 的子系统中，可以在自己的 home 目录下面找到 `.espressif` 这个文件夹，这个文件夹下面通常放 idf 环境相关的文件，`.espreeif` 文件夹下面会有这么几个文件，如下：

~~~
dist ：存放 idf 编译相关的工具包；
python_env ：存放 idf 对应的 python 环境；
tools ： 关于编译的一些工具；
espidf.constraints.v5.2.txt ：关于 idf 版本的一些信息；
idf-env.json ：
~~~

![[Pasted image 20240420213023.png]]


### 2.2 多IDF 多版本

实现 idf 多版本共存，添加一个版本的 idf，主要做了这么几件事：
- 先在 github 上面 clone 新的 idf
- 更新 `.espressif/dist` 文件夹下的工具包
- 更新 `.espressif/python_env` 下对应的 python 环境
- 配置 `.espressif/idf-env.json`，然后在配置一下 Linux 的环境