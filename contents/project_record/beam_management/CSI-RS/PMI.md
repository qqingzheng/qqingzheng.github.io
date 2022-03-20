# PMI - Precoding Matrix Indicator

> [!NOTE] 参考文章：
> 
> [5G NR CSI Report中关于codebook/PMI的理解](https://blog.csdn.net/GiveMe5G/article/details/105187987?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164776826516782092914143%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164776826516782092914143&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-4-105187987.142^v2^pc_search_result_cache,143^v4^control&utm_term=NR+PMI&spm=1018.2226.3001.4187)

## PMI的意义

基站利用终端对信道的测量和上报为基站调度提供参考信息。

## Codebook码本

码本其实就是PMI Index到Precoding Matrix的查询表。终端上报自己认为最合适的PMI Index告知gNB，gNB可以使用它的建议，也可以拒绝。

Codebook分为以下两种类型：

**TypeI codebook:** 主要用于SU-MIMO，可以提供比较高阶的空间复用，单用户最多可以支持到8个layer。这种场景相对简单，预编码矩阵主要目的focus在使得接收端可以得到比较高的能量。而潜在的layer之间的干扰，主要由接收机的多天线来解决。TypeI codebook又可以分为single pnnel和multiple panel两种类型。

**TypeII codebook:** 主要用于MU-MIMO场景，由于要在同一时频资源上同时调度多个用户，每个用户限制最多支持到2个layer。这个场景比较复杂，因为gNb选择预编码矩阵不仅要考虑接收端能获得较高的能量，还要考虑同一时频资源上对其它用户的干扰。因此此种PMI反馈的开销相对于TypeI要大得多。（当前暂不考虑）

## TypeI Single-Panel CodeBook

![](https://img-blog.csdnimg.cn/20200329201005493.png)

$N_1$代表水平方向的天线数量，$N_2$代表垂直方向的天线数量。因此这个天线面板上双极化天线数量为$N_1*N_2$。

### DFT Oversample

![](https://img-blog.csdnimg.cn/20200329201037279.png)

上图是上上图的拓展，在水平和垂直方向上增加了参数$O_1$，$O_2$。这时$N_1*O_1$则代表了水平方向可用的beams，$N_2*O_2$则代表了垂直方向可用的beams（物理天线和beams不是一一对应的关系）。CSI—RS的端口数量$P_{CSI-RS} = 2*N1*N2$

### PMI配置

![](https://img-blog.csdnimg.cn/20200331161600836.png)

#### typeI-SinglePanel-ri-Restriction

这是一个8比特的序列，$r_7,r_6,\dots,r_0$，其中$r_0$是LSB。如果$r_i$是0，那么PMI和RI不允许上报到任何与层数$v=i+1$相关的precoder不允许上报。

#### 两个端口的情况

codebookType（这是更高层的参数）会明确配置Type I并且是Type I-SinglePanel。如果nrOfAntennaPorts=2时，那么只能选择layer1和layer2，这样场景就比较简单。此时参数twoTX-CodebookSubsetRestriction有6个bit。如果gNB向终端发送的bits map中的某一位置0，意思为不允许终端使用这个码本。
![](https://img-blog.csdnimg.cn/20200331162022735.png)

#### 大于两个端口的情况

条件：nrOfAntennaPorts=4,8,12,16,24,32。并且UE将codebookType配置为TypeI-SinglePannel。

##### n1-n2参数

n1-n2也是bitmap，bit序列为$a_{A_c-1},\dots,a_1,a_0$，其中$a_0$是LSB。其中如果有bit置0，则代表与这个bit相关联的precoder不允许被上报。其中$A_c = N_1N_1O_1O_2$，但是当层数$v \in \{3,4\}$并且天线端口数量为16, 24, or 32，比特$a_{N_2O_2l+m}$与基于$v_{l,m}(l=0,\dots,N_1O_1-1, m=0,\dots,N_2O_2-2)$的所有的precoder相关联。

#### typeI-SinglePanel-codebookSubsetRestriction-i2

若高层参数reportQuantity配置为cri-RI-i1-CQI。则bitmap参数typeI-SinglePanel-codebookSubsetRestriction-i2会生成16个bit的序列$b_15,b_14,\dots,b_0$，其中$b_i$与$$