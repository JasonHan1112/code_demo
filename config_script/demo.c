#include <stdlib.h>
#include <stdio.h>
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
  int d;
#if 1/*test print define*/
  printf("%s\n", CONFIG_FILE(script.conf));
#endif
  analyze_dir("./");
  analyze_config_file("./script.conf", "hello=%d how=%d are=%d you=%d", &a, &b, &c, &d);/*need fix varlist*/
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
  printf("d = %d\n", d);
  return 0;
}
