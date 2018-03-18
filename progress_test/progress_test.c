#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void test_chld_pnt_parm(void)
{
    pid_t cpid;
    int p1 = 123;
    int p2 = 456;
    int p3 = 789;
    printf("before fork:\n p1 = %d, p2 = %d, p3 = %d\n", 
		    p1, p2, p3);
    cpid = fork();
    if(cpid < 0)
    {
        printf("fork error!!!\n");
	return ;
    }
    else if(cpid == 0)/*change p1 p2 p3 in child progress*/
    {
        printf("this is child progress pid = %ld\n", 
			(long)getpid());
	p1 += 100;
	p2 += 100;
	p3 += 100;
    }
    else
    {
	printf("this is parent progress pid = %ld\n",
	                (long)getpid());

        sleep(2);
    }
    printf("after fork pid = %ld, p1 = %d, p2 = %d, p3 = %d\n", 
		    (long)getpid(), p1, p2, p3);
    return ;

}

int test_execv(char* test_arg)
{
   pid_t cpid;
   int ret = 0;
   cpid = fork();
   if(cpid < 0)
   {
        printf("fork error!!!\n");
        return -1;
   }
   else if(cpid == 0)/*child progress*/
   {
       char* argv[2] = {test_arg, NULL};
       sleep(2);
       printf("parent pid = %d\n", getppid());
       ret = execv("./child_progress", argv);
       if(ret < 0)
       {
	   printf("execv error !!!\n");
           return -1;
       }
   }
   else/*parent progress*/
   {
      //sleep(10);
       printf("parent itself id = %d\n", getpid());
       printf("parent progress exit\n");
       exit(0);
   }
   return 0;
}





int main(void)
{
    int ret = 0;
#if 0
    test_chld_pnt_parm();
#endif
    test_execv("string_test");
    return 0;
}
