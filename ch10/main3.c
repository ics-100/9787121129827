#include <stdio.h>

int main(void)
{
    int i;
    char str[6] = "hello";
    char reverse_str[6] = "";

    printf("%s\n", str);
    for(i = 0; i < 5; i++)
        // 数组索引从0开始： 字符串第一个字符是\0,认为结束了
        reverse_str[5-i] = str[i];

    printf("%s\n", reverse_str);
    return 0;
}
