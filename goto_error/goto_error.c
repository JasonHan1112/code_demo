#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  int a = 0;
  int b = 1;
  char *c = "hello";
  printf("probe before goto ...\n");
  goto error;
  printf("probe after goto ...\n");
error:
  printf("this is error\n");
  return -1;
another_error:
  printf("this is another_error ...\n");

  return 0;


}
