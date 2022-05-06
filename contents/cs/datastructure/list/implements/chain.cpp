#include "chain.h"
void binSort(chain<int>* inputChain, int numScope);

int main(){
    chain<int> chain;
    chain.insert(0,89);
    chain.insert(0,1);
    chain.insert(0,88);
    chain.insert(0,73);
    chain.insert(0,2);
    chain.insert(0,33);
    chain.insert(0,44);
    chain.insert(0,12);
    chain.insert(0,4);
    chain.insert(0,7);
    binSort(&chain,101);
    chain.output();
    return 0;

}

void binSort(chain<int>* inputChain, int numScope){
    chain<int>* bins = new chain<int>[numScope];
    chainNode<int>** bottoms = new chainNode<int>*[numScope];
    chainNode<int>** tops = new chainNode<int>*[numScope];
    for(int i = 0; i < numScope; ++i){
        bottoms[i] = NULL;
        tops[i] = NULL;
    }
    #define THAT_BIN bins[node->element]
    for(chainNode<int>* node = inputChain->firstNode; node != NULL; node = node->next){
        THAT_BIN.insert(bins->size(),node->element);
        if(THAT_BIN.size() == 1){
            bottoms[node->element] = THAT_BIN.firstNode;
            tops[node->element] = THAT_BIN.firstNode;
        }else{
            tops[node->element] = tops[node->element]->next;
        }
    }
    chainNode<int>* lastAvailableNode = NULL;
    for(int i = 0; i < numScope; ++i){
        if(tops[i] != NULL){
            if(lastAvailableNode == NULL){
                lastAvailableNode = tops[i];
            }else{
                lastAvailableNode->next = bottoms[i];
                lastAvailableNode = tops[i];
            }
        }
    }
    int i = 0;
    while(bottoms[i] == NULL){
        ++i;
    }
    inputChain->~chain();
    inputChain->firstNode = bottoms[i];
}