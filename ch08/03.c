#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define N 100000

int a[N];

void gen_random(int upper_bound)
{
    int i;
    srand(time(NULL));
    for(i=0; i<N; i++)
        a[i] = rand() % upper_bound;
}


int main(void)
{
    int count = 1;
    while (1) {
        printf("\n\n第 %03d 次统计数据\n", count);
        count++;

        int i, histogram[10] = {0};

        gen_random(10);
        for(i = 0; i < N; i++){
                histogram[a[i]]++;
        }

        for(i=0; i<10; i++){
            printf("%d : %d\n", i, histogram[i]);
        }
        sleep(3);
    }
    return 0;
}
