# Overview of Beamforming

> [!NOTE] 参考文章：
> 
> [ShareTechNote] https://www.sharetechnote.com/ 

![](https://www.sharetechnote.com/image/BeamForming_MappingFunction_Concept_01.png)

数据经过$F_{1,2,3,4}$得到不同的beam（不同的beam意味着不同的方向，不同的形状，不同的能量）

Beamfroming利用波的干涉机制。当多个波共相位时，会发生叠加。而当多个波正交时，会抵消。如果将天线排成一列，然后进行波束赋形操作，就会在空间上得到以下能量分布图：

![](https://www.sharetechnote.com/image/BeamForming_HowToForm_01.png)

但是在实际中，天线通常是分布在一个二维平面上的（天线面板），所以会有以下能量分布：

![](https://www.sharetechnote.com/image/BeamForming_HowToForm_03.png)

如果天线在二维平面上的分布不是等边的，那么就会有下面的能量分布：

![](https://www.sharetechnote.com/image/BeamForming_HowToForm_04.png)

# 一列天线的情况

![](https://www.sharetechnote.com/image/BeamForming_ArrayAntenna_Concept_06.png)

假设两个天线之间距离是$d$。假设天线发送数据到很远处的一个接受者，那么他们之间的连线可以看作是平行的。假设发射信号的方向与竖直方向的夹角为$\theta$。那么他们发出的波的距离差为$\tau = dsin\theta$，这个距离也表示了两个波之间的延迟。

> [!TIP] 已知两个天线之间的距离d和频率f，计算两个波之间的相位：
> $\Delta p=e^{j(2\pi f\frac{dsin\theta}{c})}=e^{j(2\pi \frac{dsin\theta}{\lambda})}$。如果$d=\frac{\lambda}{2\pi}，$那么就可以得到$\Delta p=e^{jdsin\theta}=e^{j\tau}$

因此我们将每个天线发射的信号调整相位，使信号在接受端发生叠加：

$$
\newcommand\norm[1]{\left|#1\right|}
\textbf{s
}(t) =
\norm{
\begin{bmatrix}
1\\
e^{j1\tau} \\
e^{j2\tau} \\
\vdots \\
e^{j(N-1)\tau}
\end{bmatrix}s(t)}
$$

![](https://www.freetechslide.com/images/antennaRadiation/antennaRadiation_ArraySize_dsin_01.png)

在接受端，发送端就可以从不平行看似平行。

![](https://www.sharetechnote.com/image/BeamForming_BeamPatter_Plot_04.png)