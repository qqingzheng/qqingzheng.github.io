
#ifndef _linearlist
#define _linearlist
template<class T>
class linearlist{
    public:
        virtual ~linearlist() {};  //析构函数
        virtual bool empty() const = 0; // 判断线性表是否为空
        virtual int size() const = 0; // 获取线性表当前大小
        virtual T& get(int) const = 0; // 获取元素 
        virtual int indexOf(const T&) const = 0; // 获取某个元素的索引
        virtual void erase(int) = 0; // 删除某个元素
        virtual void insert(int, const T&) = 0; //在某个位置插入某个元素
        virtual void output() const = 0; // 输出整个表
};
#endif