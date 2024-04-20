1、Start a new project : create project
~~~
idf.py create-project <project-name>
~~~

2、Create a new component : create -component
~~~
idf.py create-component <component-name>
~~~

3、Select the target chip : set-target
~~~
idf.py set-target <target>
~~~


~~~
esp_get_minimum_free_heap_size(); // 获取堆栈大小
~~~

1、获取 ESP32 flash 大小；下载并运行 [Flash Download Tools](https://www.espressif.com/en/support/download/other-tools)工具；选择 COM 和 BAUD 点击 START 在 detected info 中的 QUAD 就是 flash 大小；
![](img/Pasted%20image%2020230713152524.png)