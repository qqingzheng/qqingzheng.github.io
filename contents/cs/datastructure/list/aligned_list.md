# 顺序表

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#define IF_IN_SCOPE(A,B,TARGET) A<=TARGET && TARGET<B


typedef struct{
    #define LIST_LENGTH 100
    #define LIST_EXPAND_LENGTH 10
    ElemType* base;
    unsigned int length; // current length of the list    
    unsigned int max_length;
} Mylist;

Status InitList(Mylist* list){
    list->length = 0;
    list->max_length = LIST_LENGTH;
    list->base = (ElemType*) malloc(sizeof(ElemType)*LIST_LENGTH);
    if(!list->base) return ERROR;
    return SUCCESS;
}

Status DestroyList(Mylist* list){
    free(list->base);
    return SUCCESS;
}

Status ClearList(Mylist* list){
    memset(list->base, 0, sizeof(list->length*sizeof(ElemType)));
    return SUCCESS;
}

int ListLength(Mylist* list){
    return list->length;
}

Status ListEmpty(Mylist* list){
    if(list->base == 0 || list-> length == 0){
        return SUCCESS;
    }else{
        return ERROR;
    }
}

ElemType GetElem(Mylist* list, int index){
    // Complexity O(1)
    if(index >= list->length) exit(EXIT_ERROR);
    return *(list->base + index);
}

int LocateElem(Mylist* list, ElemType elem){
    // Complexity O(n)
    int i;
    for(i = 0; i < list->length; ++i){
        if(list->base[i] == elem){
            return i;
        }
    }
    return -1;
}

Status ListInsert(Mylist* list, int index,ElemType elem){
    // Complexity O(n)
    if(!IF_IN_SCOPE(0,list->length,index)) exit(EXIT_ERROR);
    if(list->length == list->max_length){
        list->base = (ElemType*) realloc(list->base,sizeof(ElemType)*LIST_EXPAND_LENGTH);
        if(!list->base) exit(EXIT_ERROR);
        list->max_length += LIST_EXPAND_LENGTH;
    }
    
    // move elements a[i-1] = a[i]
    int i;
    for(i = list->length; i > index; --i){
        list->base[i] = list->base[i-1];
    }
    ++list->length;
    list->base[index] = elem;
    return SUCCESS;
}

Status ListDelete(Mylist* list, int index){
    // Complexity O(n)
    if(!IF_IN_SCOPE(0,list->length,index)) exit(EXIT_ERROR);
    // move elements a[i] = a[i+1]
    int i;
    for(i = index; i < list->length; ++i){
        list->base[i] = list->base[i+1];
    }
    --list->length;
    return SUCCESS;

}


int main(){
    Mylist list;
    InitList(&list);
    ListInsert(&list,0,1);
    ListInsert(&list,0,2);
    ListInsert(&list,0,3);
    ListDelete(&list,0);
    printf("%d",GetElem(&list,0));
    return 0;
}



```