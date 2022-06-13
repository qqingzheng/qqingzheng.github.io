#ifndef _LINKSTACK
#define _LINKSTACK

#include "chain.h"
#include "stack.h"
#include "exception.h"

template<class T>
class linkedStack : public stack<T>,
                    public chain<T>
{
    public:
        linkedStack(int initialCapacity) : chain<T>() {}
        bool empty() const;
        int size() const;
        T& top() const;
        void pop();
        void push(const T&);
        void output() const;
};
template<class T>
bool linkedStack<T>::empty() const{
    return chain<T>::empty();
}
template<class T>
int linkedStack<T>::size() const{
    return chain<T>::size();
}
template<class T>
T& linkedStack<T>::top() const{
    if(empty()){
        throw stackError("Stack is empty!");
    }
    return chain<T>::get(0);
}
template<class T>
void linkedStack<T>::pop(){
    if(empty()){
        throw stackError("Stack is empty!");
    }
    chain<T>::erase(0);
}
template<class T>
void linkedStack<T>::push(const T& element){
    chain<T>::insert(0,element);
}
template<class T>
void linkedStack<T>::output() const{
    chain<T>::output();
}
#endif