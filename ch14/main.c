// 1234U        - unsigned int
// 0xffff0000   - unsigned int
// 0x7fffffff   - int
// 
// int 取值范围: -2147483648~2147483647

#include <stdio.h>

int main(void)
{
    // 编译器会把它当成一个整数常量 2147483648 和一个负号运算组成的表达式
    // 而整数常量 2147483648 已经超过了 int 型的去值范围
    printf("%d\n", -2147483648);
    return 0;
}
