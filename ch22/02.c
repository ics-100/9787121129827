#include <stdio.h>

int *swap(int *px, int *py)
{
    printf("function swap\n");
    printf("px %p --- %p\n", px, &px);
    printf("py %p --- %p\n", py, &py);
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
    return px;
}

int main(void)
{
    int i = 10, j = 20;
    printf("function main\n");
    printf("i 0x%08x --- %p\n", i, &i);
    printf("j 0x%08x --- %p\n", j, &j);

    int *p = swap(&i, &j);
    printf("now i=%d j=%d *p=%d\n", i, j, *p);
    return 0;
}
