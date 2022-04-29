#include <iostream>
using namespace std;

void print_sequence(int num, int len){
    if(!len){
        cout << endl;
        return;
    }
    int bit_num = (num & 0x00000001);
    num >>= 1;
    print_sequence(num,len-1);
    cout << bit_num;
}

int set_bit(int num, int index, bool open){
    if(open){
        num = num | (0x00000001 << index);
    }else{
        num = num & (0xffffffff ^ (0x00000001 << index));
    }
    return num;
}

void generate_subset(int nowlen,int len,int num = 0){
    if(nowlen == len - 1){
        print_sequence(set_bit(num,len-nowlen-1,true),len);
        print_sequence(set_bit(num,len-nowlen-1,false),len);
        return;
    }
    generate_subset(nowlen+1,len,set_bit(num,len-nowlen-1,true));
    generate_subset(nowlen+1,len,set_bit(num,len-nowlen-1,false));
}


int main(){
    generate_subset(0,4);
    return 0;
}