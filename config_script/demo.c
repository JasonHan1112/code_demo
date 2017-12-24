#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "config.h"
struct test
{
  int a;
  int b;
  int c;
  int d;
};
int main(void)
{
  int a;
  int b;
  int c;
  float d;
#if 1/*test print define*/
  printf("%s\n", CONFIG_FILE(script.conf));
#endif
#if 1
  analyze_dir("./");
  analyze_config_file("./script.conf", 4, "%d %d %d %f", &a, &b, &c, &d);/*need fix varlist*/
  printf("%d   ", 0);
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
  printf("d = %f\n", d);
  
#endif

  return 0;
}
