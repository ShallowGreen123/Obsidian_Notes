# 0、参考链接
- [灯哥教你写FOC算法教程](http://dengfoc.com/#/dengfoc/%E7%81%AF%E5%93%A5%E6%89%8B%E6%8A%8A%E6%89%8B%E6%95%99%E4%BD%A0%E5%86%99FOC%E7%AE%97%E6%B3%95/%E5%BA%8F%E4%B8%BA%E4%BB%80%E4%B9%88%E8%A6%81%E5%87%BA%E8%BF%99%E7%B3%BB%E5%88%97%E8%AF%BE%E7%A8%8B.md)
- https://zhuanlan.zhihu.com/p/399366217
- https://zhuanlan.zhihu.com/p/172484981

# 1、BLDC 驱动
直流无刷电机 (BLDC) 通常采用 PWM 调制模拟正弦波去控制电机；而永磁同步电机 (PMDM) 采用正弦波的方式控制。

![](FOC1.png)

如上图所示，交替开关 MOS管可以实现电机的转动，而这些交替开关的 MOS管是以极快的速度在周期性进行的，把这些周期性的开启和关断过程中联系起来，并且对其各个相进行观察，就可以得到三个相 A/B/C (U/V/W) 的电流随时间变换的曲线，如下图所示，它们之间存在 120度的相位差。

![](FOC2.gif)

<font  color="red" >红色表示 A相电流的变化</font>；<font  color="green" >绿色表示 B相电流的变化</font> ；<font  color="blue" >蓝色表示 C相电流的变化</font> ；<font  color="cyan" >青色表示三相合成电流的变化</font> ； 三个矢量合成到一起，如下图所示

![](FOC3.gif)

从上面不难看出，要想同时控制三个正弦波去控制电机是非常困难的，所以要对控制方式做一些简化，Clark变换就将控制的正弦波数量简化为两个。

# 2、Clark变换

Clark变换就是将 A、B、C相的电流映射到 α 和 β 轴上面。

![](FOC_Clark_2.png)

如上图所示，我们将 a、b、c 轴通过三角函数变换到 α、β 轴上：

对于 α轴有： 

$$I_{\alpha }=i_{\alpha }-sin\left ( \frac{\pi }{6} \right )i_{b}-cos\left ( \frac{\pi }{3} \right )i_{c}$$
$$I_{\alpha }=i_{\alpha }-\frac{1}{2}i_{b}-\frac{1}{2}i_{c}$$

对于 β轴有：
$$I_{\beta }=cos\left ( \frac{\pi }{6} \right )i_{b}-cos\left ( \frac{\pi }{6} \right )i_{c}$$
$$I_{\beta }=\frac{\sqrt{3}}{2}i_{b}-\frac{\sqrt{3}}{2}i_{c}$$

写出矩阵的形式：
$$\begin{bmatrix}
I_{\alpha }\\ 
I_{\beta }
\end{bmatrix}=
\begin{bmatrix}
1 & -\frac{1}{2} & -\frac{1}{2}\\ 
0 & \frac{\sqrt{3}}{2} & -\frac{\sqrt{3}}{2}
\end{bmatrix}
\begin{bmatrix}
i_{a}\\ 
i_{b}\\ 
i_{c}\\
\end{bmatrix} \tag{1}$$

公式 (1) 是理想状态下用 $I_{\alpha }$ 和 $I_{\beta }$ 表示 $i_{a}$，$i_{b}$，$i_{c}$ 。但是实际上，假设 10A电流从 a相流入，那 b、c相流出的电流之和一定为 10A，遵循基尔霍夫电流定律（电路中任一个节点上，在任意时刻，流入节点的电流之和等于流出节点的电流之和）：
$$i_{a} + i_{b} + i_{c} = 0 $$

假设某时刻 a相的电流为 -1A，则 b、c相的电流分别为 $\frac{1}{2}$A：
$$\left\{\begin{matrix}
i_{a}=-1\\ 
i_{b}=\frac{1}{2}\\ 
i_{c}=\frac{1}{2}
\end{matrix}\right. \tag{2}$$

我们将 (2) 带入 (1) :
$$\begin{bmatrix}
I_{\alpha }\\ 
I_{\beta }
\end{bmatrix}=
\begin{bmatrix}
-\frac{3}{2}\\ 
0 
\end{bmatrix} \tag{3}$$

从 (3) 这里就可以看出 α与 β重合，但由于 b，c相投影的存在，导致从 a相输入 -1A的电流反应在 α轴上不是 -1A，而是 $-\frac{3}{2}$A ;

所以为了让式子等赋值，即使得a相1A时，反应在α轴上的电流也是1A，我们就得乘上系数 $-\frac{2}{3}$，针对上面的投影式乘上 $-\frac{2}{3}$ ​后，式子变换为：

$$\begin{bmatrix}
I_{\alpha }\\ 
I_{\beta }
\end{bmatrix}=\frac{2}{3}
\begin{bmatrix}
1 & -\frac{1}{2} & -\frac{1}{2} \\ 
0 & \frac{\sqrt{3}}{2} & -\frac{\sqrt{3}}{2} 
\end{bmatrix}
\begin{bmatrix}
i_{a} \\ 
i_{b} \\ 
i_{c} 
\end{bmatrix} \tag{4}$$

移项：
$$\begin{align*}
I_{\alpha } &= \frac{2}{3}( i_{a} - \frac{1}{2}i_{b} -\frac{1}{2}i_{c} )\\ 
		   &= \frac{2}{3}[ i_{a} - \frac{1}{2}(i_{b} + i_{c}) ]
\end{align*} \tag{5}$$

根据上面的基尔霍夫电流定律  $i_{a} + i_{b} + i_{c} = 0$ 得到：
$$\frac{1}{2}i_{a} = -\frac{1}{2}(i_{b} + i_{c}) \tag{6}$$

将公式 (6) 带入到 (5) 中，可以得到 $I_{\alpha}$ 为：
$$\begin{align*}
I_{\alpha} &= \frac{2}{3}[ i_{a} + \frac{1}{2}i_{a}] \\ 
		  &= \frac{2}{3} \times \frac{3}{2}i_{a} \\ 
		  &= i_{a}
\end{align*} \tag{7} $$

通过上面的步骤成功推导出了 $I_{\alpha}=i_{a}$，进一步可以求出 $I_{\beta}$，由公式 (4) 得到：
$$\begin{align*}
I_{\beta} &= \frac{2}{3} \times (\frac{\sqrt{3}}{2}i_{b} - \frac{\sqrt{3}}{2}i_{c}) \\
         &= \frac{\sqrt{3}}{3} \times (i_{b} - i_{c}) \\ 
         &= \frac{1}{\sqrt{3}} \times (i_{b} - i_{c})
\end{align*} \tag{8}$$

由基尔霍夫电流定律 $i_{a} + i_{b} + i_{c} = 0$ 得到 $i_{c}=-(i_{a}+i_{b})$ 将其带入到 (8) 式得到：
$$\begin{align*}
I_{\beta} &= \frac{1}{\sqrt{3}} \times (i_{b} - i_{c}) \\
		 &= \frac{1}{\sqrt{3}} \times (i_{b} + i{a} + i_{b}) \\
		 &= \frac{1}{\sqrt{3}} \times (2i_{b} + i_{a})
\end{align*} \tag{9}$$

**综上所述，终于得到了电流变量 $i_{a},i_{b},i_{c}$ 与 $I_{\alpha},I_{\beta}$ 之间的关系了，Clark变换**：
$$\left\{\begin{matrix}
I_{\alpha}=i_{a}\\ 
I_{\beta}=\frac{1}{\sqrt{3}} \times (2i_{b} + i_{a})
\end{matrix}\right. \tag{10}$$

通常使用的较多的是，Clark的逆变换，已知 $i_{a}=I_{\alpha}$ ，现在要求出 $i_{b}$ 和 $i_{c}$，可以求出 $i_{b}$ 得：
$$\begin{align*}
I_{\beta} &= \frac{1}{\sqrt{3}} \times (2i_{b} + i_{a}) \\
I_{\beta} &= \frac{1}{\sqrt{3}} \times (2i_{b} + I_{\alpha}) \\
\sqrt{3} I_{\beta} &= 2i_{b} + I_{\alpha} \\
2i_{b} &= \sqrt{3} I_{\beta} - I_{\alpha} \\
i_{b} &= \frac{\sqrt{3} I_{\beta} - I_{\alpha}}{2}
\end{align*} \tag{11}$$

由基尔霍夫电流定律 $i_{a} + i_{b} + i_{c} = 0$，求得 $i_{c}$：
$$\begin{align*}
i_{c} &= -(i_{a}+i_{b}) \\ 
     &= -I_{\alpha} - i_{b} \\
     &= -I_{\alpha} - \frac{\sqrt{3} I_{\beta} - I_{\alpha}}{2} \\
     &= \frac{-2I_{\alpha} - \sqrt{3} I_{\beta} + I_{\alpha}}{2} \\
     &= \frac{-I_{\alpha} - \sqrt{3} I_{\beta}}{2}
\end{align*} \tag{12}$$

**最后总结 Clark逆变换如下，由式 (12)、(11) 和 $i_{a}=I_{\alpha}$ 得**：
$$\left\{\begin{matrix}
i_{a}=I_{\alpha}\\ 
i_{b}=\frac{\sqrt{3} I_{\beta} - I_{\alpha}}{2}\\ 
i_{c}=\frac{-I_{\alpha} - \sqrt{3} I_{\beta}}{2}
\end{matrix}\right. \tag{13}$$


现在，原先要三个正弦信号 $i_{a},i_{b},i_{c}$  控制电机，经过 Clark变换只需要两个正弦信号  $I_{\alpha},I_{\beta}$ 了(消除了 $i_{c}$)，如下图所示。

![](FOC4.gif)

