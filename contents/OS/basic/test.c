typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
union{
    uint32_t a;
    uint16_t b;
    uint8_t c;
} Test;

int main(){
    Test.a = 0x12345678;
    printf("%x, %x, %x, %x", Test.a, Test.b, Test.c, Test.a & 0xffff);
    return 0;
}