BLE蓝牙的协议栈 
- [Generic Access Profile (GAP)](#Generic%20Access%20Profile%20(GAP))
- [Generic Attribute Profile (GATT)](#Generic%20Attribute%20Profile%20(GATT))
- [Security Manager (SM)](#Security%20Manager%20(SM))
- [Attribute Protocol (ATT)](#Attribute%20Protocol%20(ATT))
- [Logical Link Control and Adaptation Protocol (L2CAP)](#Logical%20Link%20Control%20and%20Adaptation%20Protocol%20(L2CAP))
- [Host Controller Interface (HCI)](#Host%20Controller%20Interface%20(HCI))
- [Link Layer](#Link%20Layer)
- [Physical Layer](#Physical%20Layer)

三种主流的驱动方式
BR/EDR (classic Bluetooth)
BLE (Bluetooth Low Energy)
Dual-mode (BR/EDR/LE, Bluetooth Smart Ready)

BLE蓝牙的协议栈框图 
![](img/Pasted%20image%2020230825172845.png)

# Physical Layer : 

物理层实际上包含模拟通信电路，能够调制和解调模拟信号并将其转换为数字符号。无线电使用2.4 GHz ISM（Industrial, Scientific, and Medical）频带进行通信，并将该频带划分为40个信道，从2400 MHz 到 2483.5 MHz。

~~~
通道的中心频率：chn = 2402 + k*2 MHz; 其中 k=0-39
~~~

![](img/Pasted%20image%2020230825174923.png)

如图2-2所示，其中37个信道用于连接数据，最后三个信道（37、38和39）用作广告信道，用于建立连接和发送广播数据。BLE 使用了一种 "调频扩频" 技术(动态的调整通道来减小阻塞)，以此来最大程度地避免外界的干扰，其调频公式
~~~
channel = (curr_channel + hop) % 37;
~~~

选择用于对空中比特流进行编码的调制是高斯频移键控(GFSK), 与经典蓝牙和其他几种专业低功率无线协议使用的调制相同。**蓝牙低能耗的调制速率固定为1 Mbit/s，因此这是该技术的物理吞吐量上限**。

# Link Layer :

它也是整个协议栈中唯一的硬实时约束层，因为它负责遵守规范定义的所有时序要求。计算成本高、易于自动化的功能通常由硅供应商在**硬件**中实现，以避免运行堆栈中所有软件层的中央处理单元过载。此功能通常包括

~~~
• Preamble, Access Address, and air protocol framing (数据帧生成)
• CRC generation and verification (CRC生成和验证)
• Data whitening (数据二值化)
• Random number generation (随机数生成)
• AES encryption (AES加密)
~~~

link layer 的**软件**部分管理无线电的链路状态，即设备与其他设备的连接方式。通常会定义一些角色如下，一个BLE设备既可以是 Master 也可以是 Slave 或是两者共存。

~~~
Advertiser: 向外发送广告包的设备  
Scanner: 扫描广告数据包的设备  
Master: 启动连接并在以后进行管理的设备
Slave: 接受连接请求并遵循主机定时的设备
~~~

## Bluetooth Device Address

蓝牙设备的基本标识符类似于以太网媒体访问控制（MAC）地址，是蓝牙设备地址。这个48位（6字节）的数字唯一地标识对等设备中的设备。有两种类型的设备地址(公共地址和随机地址)，其中一种或两种都可以在特定设备上设置。

## Advertising and Scanning

BLE只有一种包格式和两种类型的包（广告包和数据包），极大地简化了协议栈的实现。广告包有两个用途：

~~~
为不需要完全连接建立开销的应用程序广播数据
发现奴隶并与他们建立联系
~~~

每个广告包可以携带多达31字节的广告数据有效载荷，以及基本报头信息（包括蓝牙设备地址）。这样的分组由广告商在没有任何扫描设备存在的先前知识的情况下简单地在空中盲目地广播。它们是以广告间隔定义的固定速率发送的，广告间隔的范围从20ms到10.24s。间隔越短，广播广告包的频率就越高，导致这些包被扫描仪接收的概率越高，但发送的包量越大也意味着功耗越高。

![](img/Pasted%20image%2020230828151357.png)

规范定义了两种基本的扫描类型 Passive scanning 和 Active scanning，者两种扫描方式的工作过程如下图。

![](img/Pasted%20image%2020230828151429.png)

~~~
Passive scanning :  scanner 只是监听 advertising packets，而 advertiser 永远不会意识到 scanner 实际上接收到了一个或多个 packets。

Active scanning : scanner 在接收到 Adertising packets 之后发出 Scan request。Advertiser 接收它并用 Scan response packets 进行响应。这个额外的数据包使广告商能够发送到 scanner 的有效载荷加倍，但重要的是要注意，这根本没有为 scanner 向 Advertiser 发送任何用户数据提供手段
~~~

## Connections

为了建立连接，主机首先开始扫描以查找当前正在接受连接请求的广告商。可以通过蓝牙地址或基于广告数据本身来过滤广告分组。当检测到合适的广告从设备时，主设备向从设备发送连接请求包，并且如果从设备响应，则建立连接。连接请求包包括跳频增量，它确定了主设备和从设备在连接寿命期间将遵循的跳频序列

![](img/Pasted%20image%2020230828154702.png)

~~~
Connection interval : The time between the beginning of two consecutive connection events. This value ranges from 7.5 ms (high throughput) to 4 s (lowest possible throughput but also least power hungry).  

Slave latency : The number of connection events that a slave can choose to skip without risking a disconnection.  

Connection supervision timeout : The maximum time between two received valid data packets before a connection is considered lost.  
~~~

Because many BLE devices might exist in a given area, or even just for security reasons (in which the master or the slave might be interested in only a small set of preknown  devices), the Link Layer implements a white list feature, which specifies device addresses of interest to the advertiser or the scanner. Any advertising (if a scanner) or connection request (if an advertiser) packets received from devices whose Bluetooth Address is not present in the white list will simply be dropped.

# Host Controller Interface (HCI)

这种配置的典型示例包括大多数智能手机、平板电脑和个人电脑，其中主机（和应用程序）在主CPU中运行，而控制器位于通过UART或USB连接的单独硬件芯片中。这与其他技术（如WiFi或以太网）使用的模型类似：TCP/IP堆栈在主处理器上运行，而较低级别的层在单独的IC中执行

# Logical Link Control and Adaptation Protocol (L2CAP)

# Attribute Protocol (ATT)

# Security Manager (SM)

# Generic Attribute Profile (GATT)
[GATT](GATT.md)

# Generic Access Profile (GAP)


# 参考资料： 

[《Getting Started with Bluetooth Low Energy》]()

[Core Specification 5.0](https://www.bluetooth.com/specifications/specs/core-specification-5-0/)

[Core Specification Supplement 11](https://www.bluetooth.com/specifications/specs/core-specification-supplement-11/)

[Assigned Numbers Document](https://www.bluetooth.com/specifications/assigned-numbers/)


![](img/Pasted%20image%2020230822112115.png)

![](img/Pasted%20image%2020230824145042.png)
