# Union与Struct学习

# Anonymous Union & Anonymous Struct代码分析

## Anonymous Union

```c
struct Test{
    union{
        int a;
        int b;
    };
};
```

Test结构里面的union没有命名，因此成为匿名union（Anonymous Union）。它可以直接使用`Test.a`这样调用。

## Anonymous Struct

```c
struct Test{
    struct{
        int a;
        int b;
    }
};
```

同上理。

# union的内存结构

假如我们有:

```c
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
union{
    uint32_t a;
    uint16_t b;
    uint8_t c;
} Test;
```

我们执行下面代码：

```c
int main(){
    Test.a = 0x12345678;
    printf("%x, %x, %x, %x", Test.a, Test.b, Test.c);
    return 0;
}
// output: 12345678, 5678, 78
```
