# 基础概念介绍

## policy
**policy决定学习中的agent在某个状态下动作的选择。**大概来说，policy就是环境状态到动作的映射。在一些情况中，policy是一个简单的函数或者查询表（look-up table），而在其他情况下，policy可能涉及大量的运算，例如搜索过程。**policy是强化学习模型的核心，它可以决定agent的行为。**

## reward signal

**reward signal决定了强化学习的目标。**每一次step，环境都会反馈给agent一个数值，这个数值为reward。**而agent的目标就是去最大化reward。**reward signal也就反映了agent采取的行为是好的还是坏的。reward signal也是改变（alter）policy的首要要素。

## value function

reward signal是用来衡量一个动作的执行是好还是坏，而value function则是用于衡量这个动作的执行对于后续环境的变化是否有好处。粗略来说，**value function就是从某个state开始，未来agent可以取得的reward总和。**

## reward与value

reward是首要的，而value是次要的。没有了reward就没有了value，而评估value的唯一目的就是取得更大的reward。然而，value是我们在做出决定时最关心的。我们action的选择是基于value判断。我们想要找到一个最好的action能带来最大的value（也就是未来可以得到更多的reward）。不幸运地是，value（价值）的量化往往比reward更难。reward是直接环境反馈的，但value是从agent过往所有的observations中估计的。
**实际上，强化学习最重要的部分就是如何高效率的评估value。**

## model of environment

model of environment也就是环境模型，**它是用于模仿环境的**，或者说它可以人们通过model来推断环境会发生什么变化。例如，给model一个action和state，model可以预测下一个state和下一个reward。model是用于agent规划未来行为的，也就是说agent在决定动作之前会思考未来的环境形势。

## state

policy和value function的输入。并且state也是整个模型的输入和输出（输入为当前的state，输出为下一个state）。**我们可以认为state是告诉agent当前环境怎么样的元素。**
