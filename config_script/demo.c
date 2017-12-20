#include <stdlib.h>
#include <stdio.h>
#include "config.h"

int main(void)
{
  
#if 1/*test print define*/
  printf("%s\n", CONFIG_FILE(script.conf));
#endif
  return 0;
}
