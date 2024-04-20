
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

https://blog.csdn.net/u010164190/article/details/106771013
https://www.jianshu.com/p/dd1d67fee3aa

[VcXsrv下载](https://sourceforge.net/projects/vcxsrv/)