- **sudo apt-get updata** :
1.  The sudo apt-get update command is used to download package information from all configured sources.
2.  The sources often defined in the /etc/apt/sources. ...
3.  So when you run update command, it downloads the package information from the Internet.

- **sudo apt-get upgrade** : You need to use apt-get dist-upgrade for upgrading the kernel version with apt-get command. This is because upgrading the kernel version means installing a completely new package. **apt-get upgrade command cannot install a new package**. It can only upgrade existing packages

- **sudo apt-get install (package_name) **: 
~~~
- find <起始目录> <选项> <匹配条件>
- <选项> 
	-name "文件名"
	-type <f普通文件> <d目录>
~~~

```
tar -cvf log.tar log2012.log            # 仅打包，不压缩
tar -zcvf log.tar.gz log2012.log        # 打包后，以 gzip 压缩
tar -jcvf log.tar.bz2 log2012.log       # 打包后，以 bzip2 压缩

tar -ztvf log.tar.gz                    # 查阅上述 tar 包内有哪些文件
tar -zxvf log.tar.gz                    # 将 tar 包解压缩
tar -zxvf log30.tar.gz log2013.log      # 只将 tar 内的部分文件解压出来
```
