# NR物理层
2022/3/15

-------

## 基本流程

> [!NOTE]参考文章
> 
> [1] https://blog.csdn.net/m0_45416816/article/details/98631782

物理层处理的起点是MAC层传下来的TB（Transport Block），终点是生成基带OFDM信号，然后将基带OFDM信号变成射频信号，通过天线发射出去。

> [!TIP][**什么是基带?**](http://www.ujiuye.com/wenda/2021/69328.html)
> 
> 基带全程基本频带，简称为基带。基带是Baseband 信息源发出的没有进行频谱搬移和变换的原始电信号所固有的频带(频率带宽)。基带一般是对信号处理，由固定功能的DSP提供强大的处理能力。

![流程](https://img-blog.csdnimg.cn/20190806164210694.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L20wXzQ1NDE2ODE2,size_16,color_FFFFFF,t_70)

## TB到CW

1. TB是由MAC层发往物理层的01数据，第一步要先进行**CRC循环冗余检验**（保证信息有一定的检错和纠错能力）。
2. TB可能长度过长，那么就要经过**码块分割**，分割为下一步处理的大小，分割之后还要加入CRC循环冗余检验。
3. 分割后的码块要经过**信道编码（汉明码、卷积码、Turbo码、Polar码等），使得接收端可以检测和纠正传输中发生的错误，实现可靠传输**。
4. 编码后的码块有时候太多，分给它的资源又比较少，那么就要进行**速率匹配**，实现信息和资源的匹配。信息多了就扔掉一些，信息少了就重复一些。
5. 速率匹配后的码块又串在一起（原来分割的现在重新接合成一串）**形成码字**（CW）。

## MIMO和OFDM物理层实现

1. CW形成后，要先进行**扰码**：扰码就是将信息bit和扰码序列相乘得到新的加扰后的序列。**扰码序列会根据小区ID、子帧编号和UEID的不同而不同**，在5G中，由于不再是LTE那样以子帧为单位进行调度，而是以符号为单位，所以5G中扰码序列一般不再与时域的信息有关。**进行加扰的目的就是上行避免不同的UE之间的干扰，下行避免不同的小区之间的干扰。**
> [!TIP] [通信扰码的原理与实现](https://blog.csdn.net/qq_33668920/article/details/79661454)
2. 加扰后信息要进行调制：**从此从0和1的bit变为复数值**。5G中多数采用QAM调制，就是用不同的幅度和相位表示不同的01 bit，**在数学表达上，调制后的符号可以表示为复数值，图中的I路和Q路分别是复数值的实部和虚部**。
> [!TIP] [调制的原理](https://blog.csdn.net/m0_45416816/article/details/96572794)
3. 调制后得到的复数值信号要进行**层映射**。
4. 层映射后的复数值信息进行**预编码**。
5. 

![](https://img-blog.csdnimg.cn/20190806164228194.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L20wXzQ1NDE2ODE2,size_16,color_FFFFFF,t_70)

