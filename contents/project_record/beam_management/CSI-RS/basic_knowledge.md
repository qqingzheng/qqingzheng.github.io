# NR CSI-RS 基础概念

> [!NOTE] 参考文章：[5G NR - CSI-RS学习笔记2 - Basic Structure Overview](https://blog.csdn.net/travel_life/article/details/118968882?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1.pc_relevant_antiscanv2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1.pc_relevant_antiscanv2&utm_relevant_index=2)

## 时频结构设计

### 时域上

CSI-RS可以在一个时隙内的14个符号的任何一个开始。这种快速的反馈让CSI信息更为精确（如快速移动，信道快速变化）。

### 频域上

NR中，CSI-RS可以映射到任意RE位置

### 码分复用CDM - Code Division Multiplexing Group

NR使用CDM对CSI-RS的所有端口进行分组，每个CDM Group占用的时频资源相同，通常包含至少两个连续的RE(Resource Eelement)，使用正交码(OCC - Orthogonal Cover Code)来区分各个端口。
> 一个多端口的CSI-RS可以包含多个CDM Group，每个CDM Group包含多个端口，即：CSI-RS Port数 = CDM Group数 * 每个Group包含的端口数，比如32 Port。

## CSI-RS密度

CSI-RS密度指的是REs/Port/RB，也就是一个port在一个RB中占用的RE数。

