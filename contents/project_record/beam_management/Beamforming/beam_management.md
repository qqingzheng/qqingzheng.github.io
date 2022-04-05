# Beam Management

> [!NOTE] 参考文章：
> 
> [ShareTechNote] https://www.sharetechnote.com/ 

## 为什么需要Beam Management

如果不使用Beam Management，发送出去的信号会覆盖周围所有的UEs，造成很大的干扰（如图a/b）。而如果使用Beam Management，那么就可以使信号的能量集中在某个UE方向。为了解决如何向分散多UE发送Beam的问题，Beam Management需要复杂的算法，而不同的情形下又需要不同的算法。
![](https://www.sharetechnote.com/html/5G/image/NR_BeamManagement_Overview_02.png)

## UE和基站如何建立联系？

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

### 如何选择Beam

#### 传输阶段

在传输数据时，UE和基站都需要找到最好质量的方向去传输信号。那么他们如何找到最好的方向呢？

当基站在传输时：基站通过参考信号的评估来选择。基站会在UE发出的参考信号（以不同的beam发出）中，选择最好的那个。这个来自UE的参考信号被称为SRS。

当UE在传输时：过程与基站差不多，不过来自基站的参考信号有时是SSB，有时是CSI-RS

#### 接受阶段

接受阶段，UE和基站不是找到一个beam去发射信号，而是相当于改变相位器来接受beam。

当基站接受UE的信号时，基站会参考UE的CSI Report来接受信号。

当UE接受基站的信号时，UE会通过基站发送的指示来接受信号（基站通过测量UE发送的SRS信号来指示UE最好的接受方向）。

### Initial Attach

在接入阶段，基站会发送一系列的SSB信号，UE会在SSB信号中挑选最好的Beam，然后发送PRACH到基站，因此基站收到时就可以通过SSB Index来找出最好的Beam。

![](http://www.sharetechnote.com/html/5G/image/NR_SSB_BeamSweeping_01.png)

### P1,P2,P3到底是什么

P1，P2，P3是下行波束管理的三个不同阶段，都是用来让UE更好的接受下行数据的。

|  过程   | 功能  || 描述 |
|  ----  | ----  || ---- |
| P1  | Beam选择 || 基站扫描beam，UE选择beam并上报 |
| P2  | 基站方面的Beam调节 || 基站通过小范围扫描beam（在原本的最优beam附近小范围扫描），UE选择beam并上报 |
| P3  | UE方面的Beam调节 || 因为基站小短时间内发送的Beam方向是固定的，那么UE就需要调节相位器来跟踪Beam |

[P1，P2，P3过程图示](http://www.slide4math.com/html/NR_BeamManagement_01.html)

**P1过程**
![](http://www.sharetechnote.com/html/5G/image/NR_BeamManagement_P1_01.png)

**P2过程**

![](http://www.sharetechnote.com/html/5G/image/NR_BeamManagement_P2_01.png)

**P3过程**

![](http://www.sharetechnote.com/html/5G/image/NR_BeamManagement_P3_01.png)
