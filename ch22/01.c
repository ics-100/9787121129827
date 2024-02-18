#include <stdio.h>

/*
 *  i: 0x00000014 --- 0xbfcd6f64
 * pi: 0xbfcd6f64 --- 0xbfcd6f68
 */

int main(void)
{
    printf("初始化变量\n");
    int i = 20;
    int j = 30;
    printf(" i: 0x%08x --- %p\n", i, &i);
    printf(" j: 0x%08x --- %p\n", j, &j);

    printf("初始化指针\n");
    int *pi = NULL;
    int *ri = NULL;
    printf("pi: %p --- %p\n", pi, &pi);
    printf("ri: %p --- %p\n", ri, &ri);

    pi = &i;
    printf("\n(指向变量 i)pi: %p --- %p\n", pi, &pi);

    pi = &j;
    printf("(指向变量 j)pi: %p --- %p\n", pi, &pi);

    printf("\n指针之间相互赋值\n");
    ri = pi;
    printf("ri: %p --- %p\n", ri, &ri);
}
