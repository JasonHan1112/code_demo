#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DEBUG 1
int get_next_array(char* p, int *next, int p_size)
{
	int p_len = p_size;
	int i = 0;//suffix
	int j = -1;//prefix
	next[0] = -1;

	while(i < p_size)
	{
	    if(j == -1 || p[i] == p[j])
		{
		    i++;
			j++;
			next[i] = j;
#if DEBUG
			printf("**if** i = %d, j = %d, next[%d] = %d\n\n", i, j, i, j);
#endif
		}
		else
		{
#if DEBUG
			printf("**else** next[%d] = %d\n", j, next[j]);
#endif
		   // j = next[j];/*formal*//*i don't understand*/
		      j = -1;/*my opinion*//*every time miss one char,*/
			                       /* begin with the first one*/
#if DEBUG
			printf("**else** j = %d\n\n", j);
#endif 
		}
	}
#if 0 
	int c;
	for(c=0; c<p_size; c++)
	{
	    printf("next[%d] = %d\n", c, next[c]);
	}
#endif
    return 0;
}

int main(void)
{
	char *p = "ABABABABCAB";
	int next[11] = {0};
	get_next_array(p, next, strlen(p));
    return 0;
}
