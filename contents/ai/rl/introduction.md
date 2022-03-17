# 前言

> [!NOTE] 本书参考书籍 《Reinforcement Learning》 by Richard S. Sutton and Andrew G. Barto

> [!WARNING] 笔记为原文的理解性翻译并加入了部分自己的观点。

本书重点在于讨论如何高效的选择action，也就是如何建立state到action的映射。因此本书大部分讲述如何评估价值函数（value function）。但是不是所有的强化学习算法都需要评估价值函数，例如遗传算法（适用于agent无法完全感知环境的state的环境）。