# Beam Management

> [!NOTE] 参考文章：
> 
> [ShareTechNote] https://www.sharetechnote.com/ 

## 为什么需要Beam Management

如果不使用Beam Management，发送出去的信号会覆盖周围所有的UEs，造成很大的干扰（如图a/b）。而如果使用Beam Management，那么就可以使信号的能量集中在某个UE方向。为了解决如何向分散多UE发送Beam的问题，Beam Management需要复杂的算法，而不同的情形下又需要不同的算法。
![](https://www.sharetechnote.com/html/5G/image/NR_BeamManagement_Overview_02.png)

## UE和基站如何建立联系？

### 总览

换句话说，基站与UE之间如何找到相互之间的位置（方向）。为了与UE建立联系，基站会发送**Synchronization Signal**，并且这个信号需要传输给基站附近所有的UE。问题来了，由于基站使用波束赋形来发送信号，那么基站的信号就无法覆盖很广的范围。
![](https://www.sharetechnote.com/html/5G/image/NR_BeamManagement_Overview_03.png)

在当前，最流行的方法是：让基站对着空间不同方向发送信号进行扫描来与UE建立联系
![](https://www.sharetechnote.com/html/5G/image/NR_BeamManagement_Overview_05.png)

基站与UE产生波束联系的方式有很多，sharetechnote中给出了以下四种情况（其实不止）：

![](https://www.sharetechnote.com/html/5G/image/NR_BeamManagement_Overview_06.png)

## 建立联系后该咋办？

建立联系后，最重要的就是如何维持连接。现在大致只需要知道：UE接收到特殊的参考信号后，执行一些测量计算，然后向基站发送反馈。

## 细说

Beam Management大致在以下两个过程起作用：一个是RACH（随机接入）过程，另一个是介入后的过程。

![](https://www.sharetechnote.com/html/5G/image/NR_BeamManagement_InNutshell_01.png)