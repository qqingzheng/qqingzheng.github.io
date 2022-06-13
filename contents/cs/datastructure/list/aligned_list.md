# 数组

## 代码实现

位于`contents/cs/datastructure/list/implements`文件夹中

## 类型

+ arrayList
+ vectorList（使用STL中的vector来实现的list）
+ multiList （多个表映射到一个表上，详细可以看P109）

## 数组的具体内容

### 数组的优缺点

由于数组索引即元素在内存中与首元素的偏移量（索引可以直接映射到内存地址上），所以查找的时间复杂度为$\Theta(1)$。适用于需要大量查找，且元素数量较为固定或操作通常在数组末端（因为数组的插入与删除n次的时间复杂度为$O(n^2)$）的场景。

### 索引到内存位置的映射

$$locate(i) = i$$

> [!NOTE] 可以将这个映射改变以达到不同的效果，例如$locate(i) = arrayLength - i - 1$则代表反向储存。

### 复杂度分析

#### 插入操作

```cpp
template<class T>
void arrayList<T>::insert(int index,const T& elem){
    checkIndex(index);
    if (listSize == arrayCapacity){
        changeSpace(listSize, listSize*2);
        arrayCapacity *= 2;
    }
    std::copy(array+index, array+listSize,array+index+1);
    listSize += 1;
    array[index] = T(elem);
}
```

> [!NOTE] **定理5-1: 如果我们总是按一个乘法因子来增加数组长度，那么实施一系列线性表的操作所需要的时间与不用改变数组长度时相比，至多增加一个常数因子。**
> 
> 证明：假设列表初始长度为1，且每次插入都在列表尾部插入，插入$n=2^k+1$次，那么其复杂度为$\Theta(1*n)=\Theta(n)$。如果每次插入都增加1的空间，那么每次插入增加空间所需要的复杂度为$\Theta(\sum^{n-1}_{i=1}i)=\Theta(n^2)$。所以n次插入总的需要的时间是$\Theta(n^2)$。
> 
> 但是呈倍数增加数组长度，那么就需要$k$次扩大数组，所以扩大数组需要的复杂度为$\Theta(\sum^{k}_{i=1}2^i)=\Theta(2^(k+1)-1)=\Theta(n)$。根据分析和简单归纳得出，插入n次扩大数组所需要的时间复杂度为$O(n)$。

## 编写过程遇到的问题

> [!WARNING] 
> https://www.freesion.com/article/17501409867/ - 模板类声明与定义位置的问题
> 总结：模板在编译过程中就会更换为特定的类型，但是Array.cpp在编译过程中编译器不清楚模板类型，就会导致模板并没有具体的类型，从而在与test.cpp链接时出现`undefined reference to `arrayList<int>::empty() const'`
> 解决方法：把定义放在头文件

> [!WARING]
> 返回模板类需要加上typename
```cpp
template <class T>
typename arrayList<T>::iterator& arrayList<T>::iterator::operator++()
{
    position += 1;
    return *this;
}
```


## 新知识

1. 使用STL中的copy函数可以进行从前向后的复制，还有copy_backward函数可以实现从后向前的复制。
2. 如何写exception类：
```cpp
#ifndef _illegalParameterValue
#define _illegalParameterValue
#include <string>
class illegalParameterValue{
    public:
        illegalParameterValue(std::string msg) { this->msg = msg; }
        illegalParameterValue(const char * msg) { this->msg = msg; }
    private:
        std::string msg;
};
#endif
```
3. 在erase时要记得析构。
4. 迭代器的编写：有了迭代器才可以使用很多STL库中的函数。
```cpp
// 迭代器
class iterator
{
public:
    // 前面几个是C++必须要加的
    typedef std::bidirectional_iterator_tag iterator_category; 
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef T *pointer;
    typedef T &reference;
    iterator(value_type *thePosition = 0) { position = thePosition; };
    value_type &operator*() const { return *position; }
    value_type *operator->() const { return &*position; } // 一个特殊的取指针方式
    iterator &operator++();                               // 前置自加
    iterator operator++(int);                             // 后置自加
    iterator &operator--();
    iterator operator--(int);
    bool operator!=(const iterator &right) const;
    bool operator==(const iterator &right) const;
protected:
    pointer position;
};
```
5. 其实STL中的vector也是个动态长度的数组，不是链表。
