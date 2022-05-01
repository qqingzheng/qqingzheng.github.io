#ifndef _arrayList
#define _arrayList
#include "ADT.h"
template<class T>
class arrayList : public linearlist{
    public:
        arrayList(int initialCapacity = 10);
        arrayList(const arrayList<T>&);
        ~arrayList() { delete []  }
        int capacity() { return this->arrayCapacity; } // 返回当前容量
    protected:
        T* array;
        int arrayCapacity;
        int listSize;
        void changeSapce(int oldLength, int newLength); // 改变空间
}
#endif