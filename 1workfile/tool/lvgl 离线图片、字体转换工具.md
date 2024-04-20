[在线字体转换](https://lvgl.io/tools/fontconverter)
[在线图片转换](https://lvgl.io/tools/imageconverter)

# LVGL 离线图片转换工具
1、安装node.js [Node.js 安装](Node.js%20安装.md)
命令行中输入 ==*node -v*== 和 ==*npm -v*== ，出现版本号即为安装成功

2、win + r 输入 cmd 打开命令行， 输入 ==*npm install -g canvas*== 安装转换工具必要资源，可能不会一次安装成功，可以多试几次

3、打开 git bash 拉取转换工具仓库，克隆仓库，点击 [仓库地址 ](https://github.com/lvgl/lv_img_conv.git)

4、 Windows 的额外操作，在命令行中输入 ==*npm install -g typescript*==， 进入仓库 lib 目录下，在命令行中运行 ==*npm install -g ts-node*==，==*npm install -g @swc/cli @swc/core==注意仓库的路径不要有中午，字符与字符之间用下划线连接，不要用空格。

安装正确一堆东西，用起来还出错，TMD，还是用线上的算了
![](img/Pasted%20image%2020230912110847.png)



# LVGL 离线字体转换工具
1、安装node.js [Node.js 安装](Node.js%20安装.md)

2、拉取 lv_font_conv 仓库，在 git 中输入下面命令
~~~
$ git clone https://github.com/lvgl/lv_font_conv.git
~~~
![](img/Pasted%20image%2020230911154505.png)

这步操作后会发现当前目录下多出一个 lv_font_conv 文件夹，通过 cmd 的方式打开 lv_font_conv 文件夹。
![](img/Pasted%20image%2020230911155004.png)

3、在 cmd 窗口中输入 "npm install"，安装字体转换工具所需的依赖。
![](img/Pasted%20image%2020230911161016.png)

4、使用下面命令将 lv_font_conv 工具设置为全局的，这样不管在那个文件夹下，都可以使用字体转换工具了。
~~~
npm install -g D:\1mycode\lvgl\lv_font_conv
~~~
![](img/Pasted%20image%2020230911161426.png)

执行完上面的操作后，就可以在路径 **C:\Users\Administrator\AppData\Roaming** 找到 npm 文件夹，这个文件夹里面就是 lv_font_conv 工具了。

![](img/Pasted%20image%2020230911161917.png)

5、测试一下。输入 "cd .." 回到上级目录，在输入 "lv_font_conv -h" ，如果出现下面的信息表示工具可以正常使用。
![](img/Pasted%20image%2020230911162340.png)

6、测试生成字体。在路径 ""**C:\Windows\Fonts**" 下随便选一个字体，我选择的是下面的一款字体，把它复制到任意一个文件下面。
![](img/Pasted%20image%2020230911165115.png)

7、用 cmd 打开字体文件夹
![](img/Pasted%20image%2020230911165204.png)

输入下面命令，就可以发现原来的文件夹下面多一文件夹，那里面就是我们刚刚生成的字体，其中包括四个汉字 “你好世界” 和 ASCII 码为 "0x20-0x70" 的字符。
~~~
lv_font_conv --no-compress --format lvgl --font .\simkai.ttf -o .\conv\simkai_20.c --bpp 4 --size 20 --symbols 你好世界 -r 0x20-0x7F
~~~
![](img/Pasted%20image%2020230911165508.png)

8、下面是对上面命令的解释。
![](img/Pasted%20image%2020230911170530.png)

9、更多的参考可以通过 lv_font_conv -h 获取，也可以关注源仓库 [lv_font_conv](https://github.com/lvgl/lv_font_conv)
