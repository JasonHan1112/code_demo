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
  int e;
#if 1/*test print define*/
  printf("%s\n", CONFIG_FILE(script.conf));
#endif
#if 1
  analyze_dir("./");/*test script.conf is exit*/
  analyze_config_file("./script.conf", 2, "%d %d %d %f %d", &a, &b, &c, &d, &e);/*formt read line para*/
  printf("%d   ", 0);
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
  printf("d = %f\n", d);
  printf("d = %d\n", e);
  
#endif

  return 0;
}
