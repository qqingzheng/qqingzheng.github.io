#ifndef _CHAIN
#define _CHAIN

#include "linearList_ADT.h"
#include "exception.h" 
#include <iostream>
using namespace std;


template<class T>
class chainNode{
    public:
        chainNode(const T& element,chainNode<T>* next = NULL){ this->element=element; this->next=next; }
        T element;
        chainNode<T>* next;
        bool operator!=(chainNode<T>& node){ return node.element != element; }
};
template<class T>
ostream& operator<<(ostream& out, chainNode<T>& node){
    cout << node.element;
    return out;
}
template<class T>
class chain : public linearlist<T>{
    public:
        chain();
        ~chain();
        bool empty() const;
        int size() const; 
        T& get(int) const; 
        int indexOf(const T&) const;
        void erase(int); 
        void insert(int, const T&); 
        void output() const;
        chainNode<T> *firstNode;
    private:
        int length;
};

template<class T>
chain<T>::chain(){
    firstNode = NULL;
    length = 0;
}
template<class T>
bool chain<T>::empty() const{
    return length == 0;
}
template<class T>
int chain<T>::size() const{
    return length;
}
template<class T>
T& chain<T>::get(int index) const{
    if(index < 0 || index >= length){
        throw illegalParameterValue("index is not in scope");
    }
    chainNode<T>* ptr = firstNode;
    for(; ptr->next != NULL; ptr = ptr->next);
    return (*ptr).element;
}
template<class T>
int chain<T>::indexOf(const T& element) const{
    int i = 0;
    for(chainNode<T>* ptr = firstNode; ptr != NULL ; ptr = ptr->next){
        if(ptr->element == element){
            return i;
        }
        ++ i;
    }
    return -1;
}
template<class T>
void chain<T>::erase(int index){
    if(index < 0 || index >= length){
        throw illegalParameterValue("index is not in scope");
    }
    chainNode<T>* ptr = firstNode;
    if(index == 0){
        ptr = firstNode->next;    
        delete firstNode;
        firstNode = ptr;
        --length;
        return;
    }
    for(int i = 0; i < index - 1; ++i) ptr = ptr->next;
    chainNode<T>* lastNode = ptr;
    ptr = ptr->next;
    lastNode->next = ptr->next;
    --length;
    delete ptr;
}
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
template<class T>
chain<T>::~chain(){
    while(firstNode != NULL){
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}
template<class T>
void chain<T>::output() const{
    cout << "{";
    for(chainNode<T>* ptr = firstNode; ptr != NULL; ptr = ptr->next){
        cout << *ptr;
        if(ptr->next != NULL){
            cout << ",";
        }
    }
    cout << "}";
}


#endif
