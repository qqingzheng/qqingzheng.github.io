# 代码分析

2022/3/16

-------

# 参数说明

```python
numHAnt = 8
numVant = 4

HSpacing = 0.5
VSpacing = 0.7

downtilt = 0
enbleReadBeams = 1

H_angles = np.array(np.arange(-80,81,1),np.float)
V_angles = np.array(np.arange(-60,61,1),np.float)

Beam_path = 'Data/CSIRS_4ports_full.csv'
```

numHAnt与numVant为水平和垂直方向的天线数量，现在水平为8个天线，垂直为4个天线。

HSpacing与VSpacing则为水平天线之间的距离和垂直天线之间的距离，水平距离是0.5，垂直距离是0.7.**（问题：单位是什么）**

downtilt不知道是什么

enableReadBeams则表示是否从外部读入beams

H_angles和V_angles代表一根天线发射水平和垂直角度范围。当前设定为水平角度为[-80,80]，垂直角度为[-60,60]，并且取的角度均为整数。

```python
Beam_path = 'Data/CSIRS_4ports_full.csv'
weight_data = np.loadtxt(Beam_path,delimiter=",")
weight = weight_data[:,np.arange(0,weight_data.shape[1],2)]+1j*weight_data[:,np.arange(1,weight_data.shape[1],2)]
```
Beam_path代表读取的beams文件路径

weight_data为读入beams矩阵，其形状为32x4，矩阵的0，2列为实部，1，3列为虚部。其中0，1列代表了天线阵子的第一个极化，2，3代表第二个极化。

weight则为32x2的矩阵，其类型为复数。