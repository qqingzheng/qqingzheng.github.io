# NR物理层
2022/3/15

-------
> [!NOTE]参考文章
> 
> [1] https://blog.csdn.net/m0_45416816/article/details/98631782

物理层处理的起点是MAC层传下来的TB（Transport Block），终点是生成基带OFDM信号，然后将基带OFDM信号变成射频信号，通过天线发射出去。

> [!TIP][**什么是基带?**](http://www.ujiuye.com/wenda/2021/69328.html)
> 
> 基带全程基本频带，简称为基带。基带是Baseband 信息源发出的没有进行频谱搬移和变换的原始电信号所固有的频带(频率带宽)。基带一般是对信号处理，由固定功能的DSP提供强大的处理能力。

![流程](https://img-blog.csdnimg.cn/20190806164210694.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L20wXzQ1NDE2ODE2,size_16,color_FFFFFF,t_70)

可以将以上过程分成两部分解释：

## Transport Block到Code word



