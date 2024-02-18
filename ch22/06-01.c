#include <stdio.h>

int main(void)
{
    int i=5;
    int *pi = &i;
    int **ppi = &pi;
    printf("   i=%08x@%p\n", i, &i);
    printf("  pi=%p@%p\n", pi, &pi);
    printf(" ppi=%p@%p\n", ppi, &ppi);
    printf("%d -- %d", pi, ppi);
}
