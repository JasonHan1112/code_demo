#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    int ret = 0;
    int i = 0;
    printf("hello! this is a child progress!!!\nthe para is below:\n");
    
    for(i=0; i<argc; i++)
    {
        printf("the arg %d = %s\n", i, argv[i]);
    }
    printf("set alarm\n");
    alarm(3);/*mixing calls to alarm(2) and sleep() is a bad idea.*/
    //sleep(5);
    printf("the child progress is exiting...\n");
    
    return 0;
}

