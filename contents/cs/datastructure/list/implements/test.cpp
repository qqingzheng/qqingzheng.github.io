#include "Array.h"
#include <algorithm>
#include <cstdlib>
int main(){
    arrayList<int> list(10);
    list.insert(0,10);
    list.insert(0,1);
    list.insert(0,10);
    list.insert(0,10);
    list.insert(0,1);
    list.insert(0,5);
    // list.erase(1);
    for(arrayList<int>::iterator it = list.begin(); it != list.end(); ++it){
        std::cout << " " << *it;
    }

    std::reverse(list.begin(), list.end());
    std::cout << list;
    // std::cout << list
    return 0;
}