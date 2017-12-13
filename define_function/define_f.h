

#define INIT(fun) fun ## _init
#define CALL_INIT(fun) fun ## _init()
#define STRING(str) #str

typedef int (*INIT_FUN)(void);
#define MAX_INIT_CALL 10
