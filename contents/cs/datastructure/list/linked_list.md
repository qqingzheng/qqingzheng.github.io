# 链表

## 代码实现

位于`contents/cs/datastructure/list/implements`文件夹中

## 类型

+ 单向链表
+ 单向循环链表
+ 双向链表
+ 双向循环链表

## 链表的具体内容


### 描述

链表的每一个元素称为一个**节点**，每一个节点都包括另一个（可能多个）相关节点的位置信息，这个信息称为**链**或者**指针**。

设链表$L=\{e_1,e_2,e_3,...,e_n\}$，$e_i$称为节点，每一个节点包括了数据域和链域，链域指向相关节点，数据域储存数据。若链域指向下一个节点，那么这样的结构称为单向链表。

循环链表增加一个新的头节点（头节点代替单向链表中的空指针s），首节点没有数据储存的意义（有也不是存必要的数据），然后尾节点指向首节点。

双向链表则是链域存在两个指针，分别指向上一个元素和下一个元素。

### 链表的优缺点

空间占用少，插入与删除时不用大规模移动元素，复杂度低。

查找复杂度高。

### 复杂度分析

**插入操作**：
```cpp
template<class T>
void chain<T>::insert(int index, const T& element){
    if(index < 0 || index > length){
        throw illegalParameterValue("index is not in scope");
    }
    chainNode<T>* ptr = firstNode;
    if(index == 0){
        firstNode = new chainNode<T>(element,ptr);
        ++length; 
        return;
    }
    for(int i = 0; i < index - 1; ++i) ptr = ptr->next;
    chainNode<T>* newNode = new chainNode<T>(element,ptr->next);
    ptr->next = newNode;
    ++length;
} 
```
不考虑index超范围情况，插入的复杂度为$\Theta(index)$

其他分析较为简单。

## 编写过程遇到的问题

> [!NOTE] 对模板类的理解仍然不够深刻，对于模板类，定义方法时一定要用`chain<T>`。

## 应用

### 箱子排序

书本P130

详细实现方法看代码。

```cpp
void binSort(chain<int>* inputChain, int numScope){
    chain<int>* bins = new chain<int>[numScope];
    chainNode<int>** bottoms = new chainNode<int>*[numScope];
    chainNode<int>** tops = new chainNode<int>*[numScope];
    for(int i = 0; i < numScope; ++i){
        bottoms[i] = NULL;
        tops[i] = NULL;
    }
    #define THAT_BIN bins[node->element]
    for(chainNode<int>* node = inputChain->firstNode; node != NULL; node = node->next){
        THAT_BIN.insert(bins->size(),node->element);
        if(THAT_BIN.size() == 1){
            bottoms[node->element] = THAT_BIN.firstNode;
            tops[node->element] = THAT_BIN.firstNode;
        }else{
            tops[node->element] = tops[node->element]->next;
        }
    }
    chainNode<int>* lastAvailableNode = NULL;
    for(int i = 0; i < numScope; ++i){
        if(tops[i] != NULL){
            if(lastAvailableNode == NULL){
                lastAvailableNode = tops[i];
            }else{
                lastAvailableNode->next = bottoms[i];
                lastAvailableNode = tops[i];
            }
        }
    }
    int i = 0;
    while(bottoms[i] == NULL){
        ++i;
    }
    inputChain->~chain();
    inputChain->firstNode = bottoms[i];
}
```