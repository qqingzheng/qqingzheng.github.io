# Multi-armed Bandits

本章节学习在一种situation（环境因素）下的简化版强化学习。目的是可以更加清楚地了解评价性反馈与指导性反馈的区别。

> [!NOTE] evaluative feedback：uses traning information that evaluates the actions taken rather than instructs by giving correct actions. **Purely evaluative feedback indicates how good the actions taken was, but not whether it was the best or the worst action possible.**

## A k-armed Bandit Problem

在这个问题下，你会反复的面对$k$个选择的问题（k different actions）。每次你选择了一个动作，那么你会收到量化的奖励（numerical reward）。这个量化的奖励从stationary probablity distribution（固定的概率分布）中选取。你的目标是在一定的选择数量（比如每选择1000次）内**最大化总的奖励**。

这就是典型的**k-armed bandit problem**。

## value

在这个问题中的每一轮，你对与k个动作都记录下了之前选择这个动作获得奖励的平均，我们可以将这个平均的奖励称为value。现在我们对这个问题进行数学的建模，记动作为$a$。在t次选择的动作记为$A_t$，其对应的奖励为$R_t$。记对于某个动作$a$的价值为$q_*(a)$。那么：

$$q_*(a) = \mathbb{E}(R_t|A_t=a)$$

其含义过去选择了a动作的奖励的期望。记$Q_t(a)$为t次选择后，我们得到的某个动作的估计价值，我们想要$Q_t(a)$接近$q_*(a)$。

## Exploration and Exploitation

在每次step中，**至少**有一个动作具有最大的$Q_t(a)$，我们称之为**greedy actions**。如果我们选择了greedy action，我们则称我们的选择是在exploiting（用我们已知的经验选择动作），否则则为exploring（探索未知）。探索未知可以让我们发现“有长期价值”的动作。探索与循规蹈矩常常会出现冲突。

> [!NOTE] 在这本书里，没有详细的介绍如何平衡exploring和exploiting，只会介绍简单的方法。


> [!ATTENTION] 并不是说exploring和exploiting的研究没用，这其实是强化学习领域一个挑战。

## Action-value methods
 
> [!NOTE] Action-value method包含两部分，一个部分是评估动作价值的方法和使用评估结果选择动作的方法。