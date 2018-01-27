#ifndef  __DEBUG_H__
#define  __DEBUG_H__


/*macro debug*/
#define  DEBUG_INFO(fmt, args...) \
           printf("[%s]:[%s]"fmt"\n", "debug", __FUNCTION__, ##args)
#define  ERR_INFO(fmt, args...) \
           printf("[%s]:[%s]"fmt"\n", "error", __FUNCTION__, ##args)


/*function*/
void DEBUG_PRINT(const char* fmt, ...);

void ERR_PRINT(const char* fmt, ...);

long long get_runtime(void);


#endif
