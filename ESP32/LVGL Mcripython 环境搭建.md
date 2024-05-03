
# 1. Unix (Linux) port install

该环境在 WSL 中搭建，使用的是 lv_micropython 发布的 release/v8 分支；

参考链接 [Github](https://github.com/lvgl/lv_micropython/tree/release/v8?tab=readme-ov-file)

~~~
sudo apt-get install build-essential libreadline-dev libffi-dev git pkg-config libsdl2-2.0-0 libsdl2-dev python3.8 parallel
 
git clone -b relese/v8 https://github.com/lvgl/lv_micropython.git

cd lv_micropython

git submodule update --init --recursive lib/lv_bindings

make -C mpy-cross

make -C ports/unix submodules

make -C ports/unix

./ports/unix/micropython
~~~

# 2. Win10+WSL+VcXsrv Ubuntu图形化界面

安装 VcXscv 

### 参考链接

- https://blog.csdn.net/u010164190/article/details/106771013
- https://www.jianshu.com/p/dd1d67fee3aa
- [VcXsrv下载](https://sourceforge.net/projects/vcxsrv/)

### 1. 更新 apt-get 命令

~~~csharp
sudo apt-get update
sudo apt-get upgrade
~~~

### 2. 安装 VcXscv

安装地址 [VcXsrv下载](https://sourceforge.net/projects/vcxsrv/)

按照指示安装完成后，桌面会生成 `XLaunch` 的快捷方式；

### 3. WSL 安装 xfce desktop

安装过程中会出现要你选择登录界面的选项，选择gdm安装即可  这个步骤最容易安装失败，后面的步骤做不下去了一般是你安装到最后报错Error了，这时候百度解决一下，笔者遇到的一般 安装修复 就解决了。

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


# 3. 测试工程

测试工程地址 [Gitee](https://github.com/lvgl/lv_micropython/tree/release/v8?tab=readme-ov-file)

在完成上面的步骤后，可以使用测试 lvgl + micropython 的模拟器的环境是否可以使用；

首先启动软件 `XLaunch` ，默认一直点击 next 就可以；

后面使用 `./ports/unix/micropython` 来运行测试工程里面的 `lvgl_SDL/lvgl_test.py` 文件。假设当前在 lv_micropython 目录下，那可以使用下面的命令来运行测试模拟器例程：

~~~python
./ports/unix/micropython lvgl_SDL/lvgl_test.py
~~~

