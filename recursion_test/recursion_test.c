#include <stdlib.h>
#include <stdio.h>

#if 1/*this is a test for recursion*/
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
#endif
#if 1/*this is a mid search test*/
void mid_search(char* start, char* end, char data_search)
{
    char *mid = NULL;
	mid = ((long)start + (long)end)/2;
	
	/*end condition*/
	if(*start == data_search || *end == data_search || *mid == data_search)
	{
		printf("find the data_search = %d\n", data_search);
		return;
	}
	else if(start == end || start == mid)/******so important******/
    {
		printf("not found the data_search\n");
      	return;
    }

	/*recursion condition: modify parameters*/
    else
    {

		if(*mid < data_search)
		{
		    start = mid + 1;
		}
		else
		{
		    end = mid - 1;
		}
#if 0/*debug log*/
		printf("trace *start = %d\n,", *start);
		printf("trace *mid = %d\n", *mid);
		printf("trace *end = %d\n\n", *end);
#endif
		mid_search(start, end, data_search);
    }
}
#endif
int main(void)
{
#if 0/*this is a test for recursion*/
    int i = 10;
    int ret = 0;
    printf("recursion starting...\n");
    ret = simple_recursion_print(i);
    printf("recursion ending...\n");
    printf("ret = %d\n", ret);
#endif
#if 1/*this is a test for mid search*/
	int i = 0;
	/*some data maybe can't be found if the order is not right. */ 
	char test_search[18] = {1,2,3,4,5,23,67,56,68,79,80,85,87,89,100,115,117,125};
#if 0
	char test_search[5] = {1,3,2,4,5};
#endif
	/*find every data in array*/
	for(i=0; i<sizeof(test_search); i++)
   	{
		mid_search(test_search, test_search+sizeof(test_search)-1, test_search[i]);
	}
#endif
}



