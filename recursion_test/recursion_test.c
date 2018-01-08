#include <stdlib.h>
#include <stdio.h>

int simple_recursion_print(int i)
{
    int tmp = 0;
    if(i == 1)
    {
        printf("i = %d\n", i);
        return i;
    }
    printf("next recursion i = %d\n", i);
    tmp = simple_recursion_print(i-1) + 2;
    printf("tmp = %d\n", tmp);
    return tmp;
}


int main(void)
{
    int i = 10;
    int ret = 0;
    printf("recursion starting...\n");
    ret = simple_recursion_print(i);
    printf("recursion ending...\n");
    printf("ret = %d\n", ret);
}



