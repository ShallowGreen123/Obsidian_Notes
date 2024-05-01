
Unix (Linux) port install
~~~
sudo apt-get install build-essential libreadline-dev libffi-dev git pkg-config libsdl2-2.0-0 libsdl2-dev python3.8 parallel
 
git clone https://github.com/lvgl/lv_micropython.git

cd lv_micropython

git submodule update --init --recursive lib/lv_bindings

make -C mpy-cross

make -C ports/unix submodules

make -C ports/unix

./ports/unix/micropython
~~~

# Win10+WSL+VcXsrv Ubuntu图形化界面

安装 VcXscv 

 ### 1. 更新 apt-get 命令
~~~csharp
sudo apt-get update
sudo apt-get upgrade
~~~

 ### 2. 安装 VcXscv

安装地址 [VcXsrv下载](https://sourceforge.net/projects/vcxsrv/)

 ### 3. WSL 安装 xfce desktop

安装过程中会出现要你选择登录界面的选项，选择gdm安装即可  
这个步骤最容易安装失败，后面的步骤做不下去了一般是你安装到最后报错Error了，这时候百度解决一下，笔者遇到的一般 安装修复 就解决了。
~~~csharp
sudo apt-get install xfce4-terminal
sudo apt-get install xfce4
~~~

### 4. 添加配置到 .bashrc

将下面的内容添加到 ~/.bashrc 文件后面
~~~bash
export DISPLAY=:0.0
export LIBGL_ALWAYS_INDIRECT=1
~~~

### 5. 启动 xfce

打开第 2 步安装的 XLaunch，选择 `Multiple Windows`，然后一直电机 `next`；最后在 WSL 中输入 `startxfce4` 即可打开图像化界面；

### 参考链接
https://blog.csdn.net/u010164190/article/details/106771013
https://www.jianshu.com/p/dd1d67fee3aa

[VcXsrv下载](https://sourceforge.net/projects/vcxsrv/)