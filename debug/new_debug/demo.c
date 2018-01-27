#include <stdlib.h>
#include <stdio.h>

#include "debug.h"

int main(void)
{
    
    DEBUG_PRINT("%s,%d,%f", "hello", 1, 1.234);
    ERR_PRINT("%s,%d,%f", "not oki", 3, 2);
    return 0;
}