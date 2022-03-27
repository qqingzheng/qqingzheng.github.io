# 什么是复数

> [!TIP] 参考文章：http://www.slide4math.com/

> [!ATTENTION] 本文主要在工程方面理解复数和应用复数。

## 复数的形式

![](http://www.sharetechnote.com/image/EngMath_ComplexNumber_02.PNG)

其中a代表的是实部，b代表的虚部。

## 复数有什么意义

复数可以是任何两个数字的组合。所以可以将两个不同量集合在一个复数中以综合两种量的特征在一个数字上。

## 复数的表示方法

### 原始表示

![](http://www.sharetechnote.com/image/EngMath_ComplexNumber_02.PNG)

### Polar form

![](http://www.sharetechnote.com/image/EngMath_ComplexNumber_PolarForm.PNG)

复数坐标到坐标原点的距离称为“Absolute distance of complex number”（复数的绝对距离）


### 三角表示

![](http://www.sharetechnote.com/image/EngMath_ComplexNumber_TrigForm.png)

## 复数的数学运算

### 加法运算

![](http://www.sharetechnote.com/image/EngMath_ComplexNumber_Addition_01.PNG)

### 减法运算

![](http://www.sharetechnote.com/image/EngMath_ComplexNumber_Substraction_01.PNG)

### 乘法运算

![](http://www.sharetechnote.com/image/EngMath_ComplexNumber_Multiplication_01.PNG)

乘法运算得到的新复数，其Arg两个乘数的Arg的和，模是两个乘数的模r的乘积：

$$
Arg_{c3} = Arg_{c2}+ Argx_{c1}\\
Absnum_{c3} = Absnum_{c2}\times Absnum_{c1} 
$$

如果c1的Absnum是1，那么相当于c3仅仅是c2的一个**旋转**，旋转的角度是c1的角度，这在工程上有很大的用处：

![](http://www.sharetechnote.com/image/EngMath_ComplexNumber_Multiplication_02.PNG)

### De Moivre's Theorem

$$
Let\ z = cos\theta + sin(\theta)i\\
z^n = r^n(cosn(n\theta) + sin(n\theta)i)
$$
其中r为z的模。

如何理解这个公式呢？由乘法运算，两个复数相乘得到的新复数的角度和模是它们的角度相加，模相乘。

### Euler Equation

$$
e^{i\theta} = cos(\theta) + sin(\theta)i
$$

欧拉公式将我们上面的三角表示法转化为指数的形式。并且，$e^{i\theta}$表示起点在坐标上，与实轴的夹角为$\theta$，终点指向单位圆的向量。

![](http://www.sharetechnote.com/image/EngMath_ComplexNumber_EulerEq_02.PNG)

#### 分割和伸长

可以通过$Ae^{\frac{n}{k}2\pi}$将单位圆分割为k份，并且将半径扩大A倍。

![](http://www.sharetechnote.com/image/EngMath_ComplexNumber_EulerEq_04.PNG)
![](http://www.sharetechnote.com/image/EngMath_ComplexNumber_EulerEq_05.PNG)
