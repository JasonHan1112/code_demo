#include <stdlib.h>
#include <stdio.h>
#include "define_f.h"


int INIT(first)(void)
{
  
  printf("function = %s\n",__FUNCTION__);
  return 0;
}

int INIT(second)(void)
{
  printf("function = %s\n",__FUNCTION__);
  return 0;
}

int INIT(third)(void)
{
  printf("function = %s\n",__FUNCTION__);
  return 0;
}
int forever(void)
{
  printf("this is the last, before while(1)\n");
  while(1);
}

INIT_FUN init_fun_array[MAX_INIT_CALL] = 
{
  INIT(third),
  INIT(second), 
  INIT(first),
};/*initialize function pointer*/

int main(void)
{
  printf("this is begin...\n");
  INIT(third)();
  INIT(second)();
  INIT(first)();
  printf("#define string = %s\n", STRING(hello));
  
  /*for init call*/
  int i = 0;
  for(; i<3; i++)
  {
    init_fun_array[i]();
  }

  return 0;
}
