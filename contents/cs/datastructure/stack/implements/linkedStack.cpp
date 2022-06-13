#include "linkstack.h"
#include <iostream>
#include <ctime>
int main(){
    linkedStack<int> mystack(10);
    clock_t begin,end;
    try{
        mystack.top();
    }catch(stackError s){
        s.outputMessage();
    }
    begin = clock();
    
    for(int i = 0; i < 1000000; ++i){
        mystack.push(10);
        mystack.push(1);
        mystack.push(3);
        mystack.push(4);
        mystack.pop();
    }

    end = clock();
    std::cout << "linkedStack: " << (double)(end-begin)/CLOCKS_PER_SEC << std::endl;
    return 0;  
}  