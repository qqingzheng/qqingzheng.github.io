#ifndef _ARRAYSTACK
#define _ARRAYSTACK

#include "stack.h"
#include "list.h"
#include "exception.h"
template<class T>
class arrayStack : public stack<T>,
                   public arrayList<T>
{
    public:
        arrayStack(int initialCapacity = 10) : arrayList<T>(initialCapacity){
        }
        bool empty() const;
        int size() const;
        T& top() const;
        void pop();
        void push(const T&);
        void output() const;
};


template<class T>
bool arrayStack<T>::empty() const{
    return this->size() == 0;
}
template<class T>
int arrayStack<T>::size() const{
    return arrayList<T>::size();
}
template<class T>
T& arrayStack<T>::top() const{
    if(empty()){
        throw stackError("Stack is empty!");
    }
    return arrayList<T>::get(this->size()-1);
}
template<class T>
void arrayStack<T>::pop(){
    if(empty()){
        throw stackError("Stack is empty!");
    }
    arrayList<T>::erase(this->size()-1);
}
template<class T>
void arrayStack<T>::push(const T& element){
    arrayList<T>::insert(this->size(),element);
}
template<class T>
void arrayStack<T>::output() const{
    arrayList<T>::output();
}
#endif