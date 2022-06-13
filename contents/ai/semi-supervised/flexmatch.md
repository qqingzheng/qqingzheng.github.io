# [论文阅读] FlexMatch

> [!NOTE] 下载：[https://arxiv.org/pdf/2110.08263.pdf](https://arxiv.org/pdf/2110.08263.pdf)，[本地](papers/2110.08263.pdf)

> [!WARNING] 什么是Consistensy Regularization
> + [https://zhuanlan.zhihu.com/p/46893709](https://zhuanlan.zhihu.com/p/46893709)


# 摘要

提出了CPL（Curriculum Pseudo Labeling），这是一种可以根据学习过程中的状态去分类未标签数据，其实也就是**采用灵活调整阈值的方式**去分类。
CPL在每一个时间步（time step）调整阈值，给分类可信度最大的数据打上伪标签。

> [!ATTENTION] 什么是学习过程中的状态（learning status）？

# 过去工作

过去的一些SSL算法对**所有的分类都使用预先定义好的常量阈值**去训练。这样的算法**没有考虑到不同类别的训练难度和学习过程中不同的状态**。尽管这样的策略会保证分类可信度高的无标签数据对模型有帮助，但是忽略了训练早期大部分无标签数据其实无法达到这样的高阈值。

# 创新点/贡献

+ 提出了CPL，一个动态改变阈值的方法。
+ 这个算法运算效率与FixMatch相当，并且可以很容易结合进其他的SSL算法。
+ CPL大大增加了一些SSL算法的准确度和收敛速度。

# 数学模型

## 过去的模型

![](papers/2110.08263-1.png)


在SSL中，最基础的一致性损失是$\mathscr{l}-2 loss$：

$$
\sum_{b=1}^{\mu B}\left\|p_{m}\left(y \mid \omega\left(u_{b}\right)\right)-p_{m}\left(y \mid \omega\left(u_{b}\right)\right)\right\|_{2}^{2}
$$

> [!WARNING] 我很讨厌网上有的人介绍公式但是不介绍变量含义！

其中$B$是有标注数据集的大小，$\mu$是无标签数据比有标签数据的值，$\omega$是一个随机的数据增强函数（因为是随机的，所以两个$\omega$是不同的），$u_b$是一条无标签数据，$p_m$代表模型的输出。

引入了伪标签技术后，一致性损失就被转化到了熵最小化的形式（对于分类任务更好用）。改进后的一致性损失就写为：

$$
\frac{1}{\mu B} \sum_{b=1}^{\mu B} \mathbb{1}\left(\max \left(p_{m}\left(y \mid \omega\left(u_{b}\right)\right)\right)>\tau\right) H\left(\hat{p}_{m}\left(y \mid \omega\left(u_{b}\right)\right), p_{m}\left(y \mid \omega\left(u_{b}\right)\right)\right)
$$

其中$H$代表交叉熵（cross-entropy），$\tau$是预先定义的阈值（基础阈值），$\hat{p}_{m}\left(y \mid \omega\left(u_{b}\right)\right)$是伪标签。

在FixMatch中，它使用如上的一致性正则化（Consistency Regularization）和强数据增强去实现好的效果。对于无标签数据，FixMatch首先使用弱数据增强去生成伪标签。这些伪标签数据然后被作为强数据增强的数据。FixMatch中的无监督损失如下：

$$
\frac{1}{\mu B} \sum_{b=1}^{\mu B} \mathbb{1}\left(\max \left(p_{m}\left(y \mid \omega\left(u_{b}\right)\right)\right)>\tau\right) H\left(\hat{p}_{m}\left(y \mid \omega\left(u_{b}\right)\right), p_{m}\left(y \mid \Omega\left(u_{b}\right)\right)\right)
$$

其中$\Omega$是强数据增强函数。

## FlexMatch

当前的SSL算法只为高可信度的数据打伪标签，而CPL会在每一个时间步为不同的类别打伪标签。CPL会在每一个时间步根据模型对于每个类的学习状态去调整这个类的阈值。

实现这个的理想方式是为每个分类评估可信度，然后使用这个评估值去与预定的阈值相乘得到每个类的阈值。

$$
\mathcal{T}_{t}(c)=a_{t}(c) \cdot \tau
$$

其中$\mathcal{T}_{t}(c)$指的是分类$c$在时间步$t$的阈值。$a_{t}(c)$指的分类的评估值。在这种理想模式下存在两个问题：**1、我们需要额外分割出有标签的数据来计算$a_t(c)$，但是有标签资源本来就稀缺。** **2、我们需要在每一个时间步更新$a_t(c)$，这会降低训练速度。** 

而提出的CPL则解决了上面的问题，它没有引入新的计算复杂度，也不需要额外的标签数据集。CPL的基本假设是：**当阈值很高时，对于一个类别的学习效果可以从分对了类且结果高于阈值的数据量来反映。** 说人话就是，如果一个类别中只有少量样本的分类结果高于阈值，那么这个类就认为是很难学习的（学习效率很差）。因此有以下公式：
$$
\sigma_{t}(c)=\sum_{n=1}^{N} \mathbb{1}\left(\max \left(p_{m, t}\left(y \mid u_{n}\right)\right)>\tau\right) \cdot \mathbb{1}\left(\arg \max \left(p_{m, t}\left(y \mid u_{n}\right)=c\right)\right.
$$
其中$\sigma_{t}(c)$反映了分类$c$在时间步$t$的学习效率 **（其实这是所有未标签数据中分类为$c$，且高于阈值$\tau$的数据总数）** 。$p_{m, t}\left(y \mid u_{n}\right)$代表模型在时间$t$对未标签数据$u_n$的预测。$N$是未标签数据的总数。将$\sigma_{t}(c)$规范到0到1之间，则可以与$\tau$（预定的阈值）进行相乘了：
$$
\beta_{t}(c)=\frac{\sigma_{t}(c)}{\max _{c} \sigma_{t}}
$$

$$
\mathcal{T}_{t}(c)=\beta_{t}(c) \cdot \tau
$$

这个新的阈值就被用来设计FlexMatch中的半监督损失函数：

$$
\mathcal{L}_{u, t}=\frac{1}{\mu B} \sum_{b=1}^{\mu B} \mathbb{1}\left(\max \left(q_{b}\right)>\mathcal{T}_{t}\left(\arg \max \left(q_{b}\right)\right)\right) H\left(\hat{q}_{b}, p_{m}\left(y \mid \Omega\left(u_{b}\right)\right)\right)
$$

其中$q_{b}=p_{m}\left(y \mid \omega\left(u_{b}\right)\right)$。然后我们将半监督损失函数与监督损失函数结合起来：

$${\mathcal L}_{t}=\mathcal{L}_{s}+\lambda\mathcal{L}_{u,t}$$

$\mathcal{L}_{s}$是指监督学习损失

## 阈值Warm—up

在训练早期，评估某个类别的学习状态得到的评估值往往不可靠，而模型却会根据初始化的参数盲目地将很多无标签数据分入特定的类别中。因此为了解决这个办法，需要进行阈值的warm-up：
$$\beta_{t}(c)={\frac{\sigma_{t}(c)}{\operatorname*{max}\left\{\max_c\sigma_{t},N-\sum_{c}\sigma_{t}\right\}}},$$

其中$N-\sum_{c}\sigma_{t}$表示还未被分类的无标签数据。这个可以保证$\beta_t(c)$从0逐渐增长到1。在实际应用中，我们可以设置一个新的类别表示未分类的数据，这样可以很容易的实现阈值warm-up。

## 非线性映射

上面阈值的获取都是通过将预定阈值乘一个学习率评估值得到的（线性映射）。然而，这在实际训练中并不适用，因为这样会导致$\beta_t(c)$在早期就大幅度增加而影响实验效果。因此需要一个函数，使得当$\beta_t(c)$较小时不敏感。

$$
{\mathcal T}_{t}(c)=\mathcal{M}(\beta_{t}(c))\cdot\mathcal{T}
$$

其中映射函数$\mathcal{M}$应该具有一下性质：

+ 单调递增
+ 变量较小时函数增长慢，变量较大时函数增长快。
+ 最大值不超过$1/\tau$

论文中给出了$\mathcal{M}(x)=\frac{x}{2-x}$
# 实验