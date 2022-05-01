#ifndef _arrayList
#define _arrayList
#include "ADT.h"
#include "exception.h"
#include <iostream>
#include <algorithm>
template<class T>
class arrayList : public linearlist<T>{
    public:
        arrayList(int initialCapacity = 10);
        arrayList(const arrayList<T>&);
        ~arrayList() { delete [] array; }
        int capacity() const{ return this->arrayCapacity; } // 返回当前容量
        bool empty() const;
        int size() const;
        T& get(int) const;
        int indexOf(const T&) const;
        void erase(int); 
        void insert(int, const T&);
        void output() const; 
    protected:
        T* array;
        int arrayCapacity;
        int listSize;
        void changeSpace(int, int); // 改变空间
    private:
        void checkIndex(int) const;

};
template<class T>
void arrayList<T>::checkIndex(int index) const{
    if(index < 0 && index >= listSize){
        throw illegalParameterValue("index must in the list scope");
    }
}
template<class T>
arrayList<T>::arrayList(int initialCapacity){
    if(initialCapacity < 0){
        throw illegalParameterValue("initialCapacity must be > 0");
    }
    array = new T[arrayCapacity];
    arrayCapacity = initialCapacity;
    listSize = 0;
}
template<class T>
arrayList<T>::arrayList(const arrayList& list){
    arrayCapacity = list.arrayCapacity;
    listSize = list.listSize;
    array = new T[arrayCapacity];
    std::copy(list.array, list.array + listSize, array);
}
template<class T>
bool arrayList<T>::empty() const{
    return listSize == 0;
}
template<class T>
int arrayList<T>::size() const{
    return listSize;   
}
template<class T>
T& arrayList<T>::get(int index) const{
    checkIndex(index);
    return array[index];
}
template<class T>
int arrayList<T>::indexOf(const T& elem) const{
    int index = (int)(std::find(array,array+listSize,elem) - array);
    if(index == listSize)
        return -1;
    else return index;
}
template<class T>
void arrayList<T>::erase(int index){
    checkIndex(index);
    std::copy(array+index+1,array+listSize,array+index);
    array[listSize-1].~T(); // 这一步要记得，元素需要析构，
    listSize -= 1;
}
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
template<class T>
void arrayList<T>::output() const{
    std::cout << "{";
    for(int i = 0 ; i < listSize; ++i){
        std::cout << array[i];
        if (i != listSize - 1){
            std::cout << ",";
        }
    }
    std::cout << "}" << std::endl;
}
template<class T>
void arrayList<T>::changeSpace(int oldLength, int newLength){
    if ( oldLength <= 0 || newLength <= 0){
        throw illegalParameterValue("illegalParameterValue");
    }
    T* newarray = new T[newLength];
    std::copy(array, array+oldLength, newarray);
    array = newarray;
}
template<class T>
std::ostream& operator<<(std::ostream& out, const arrayList<T>& list){
    list.output();
    return out;
}
#endif