开发环境：
STM32F429IGT6
STM32CubeMX + Keil
正点原子阿波罗开发板
sdram W9825G6KH

---

W9825G6KH 特性
1. 共用 13 位地址线。其中行地址 13 条， 列地址 9 条；包含 4 个 Bank，位宽位 16 位；容量位：2^13 * 2^9 * 4 * 16 bit  = 8192 * 512 * 4 * 16 bit = 32M byte；
2. 最大工作时钟频率为 200M
3. 8K 的 Refresh Cycles / 64ms
4. 列地址选通延迟 CAS Latency :  2 ~ 3 个时钟周期
5. 


一、STM32CubeMX 配置
![](img/Pasted%20image%2020230619115444.png)
~~~
	Clock and chip enable: 时钟和使能
	Internal bank number: 内部 Bank 数
	Address: 地址线数
	Data: 数据线位宽
	Byte enable: 数据掩码，这个必须使能；数据线的数据都会 & 上 0xFFFF；如果没有使能，则 SDRAM 里面的数据都是 0
~~~

![](img/Pasted%20image%2020230619114107.png)

~~~

SDRAM_Timing.LoadToActiveDelay=2;                                   //加载模式寄存器到激活时间的延迟为2个时钟周期

    SDRAM_Timing.ExitSelfRefreshDelay=8;                                //退出自刷新延迟为8个时钟周期

    SDRAM_Timing.SelfRefreshTime=6;                                     //自刷新时间为6个时钟周期                                

    SDRAM_Timing.RowCycleDelay=6;                                       //行循环延迟为6个时钟周期

    SDRAM_Timing.WriteRecoveryTime=2;                                   //恢复延迟为2个时钟周期

    SDRAM_Timing.RPDelay=2;                                             //行预充电延迟为2个时钟周期

    SDRAM_Timing.RCDDelay=2;                                            //行到列延迟为2个时钟周期

~~~

二、