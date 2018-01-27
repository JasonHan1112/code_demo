#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>


#include "debug.h"

#define MAX_PRINT 512
#define MAX_FMT 256
#define FMT_STRING(fmt) "[%s]:"fmt




/*return ms*/
long long get_runtime(void)
{
    int ret = 0;
    struct timespec debug_time;/*debug_time*/
    long long time_ms = 0;/*time*/
    ret = clock_gettime(CLOCK_MONOTONIC, &debug_time);
    if(ret == -1)
    {
      return -1;
    }
    time_ms = debug_time.tv_sec*1000 + debug_time.tv_nsec/1000000;
  
    return time_ms;/*return ms*/
 
}


/*debug*/
void DEBUG_PRINT(const char* fmt, ...)
{
    va_list arg_ptr;
    int ret = 0;
    char print[MAX_PRINT];/*the char that print*/
    char fmt_print[MAX_FMT] = {0};
    long long time_ms = 0;/*time*/

    va_start(arg_ptr, fmt);/*arg_ptr point to the first param*/
  
    /*get local time*/
    time_ms = get_runtime();
    if(ret == -1)
    {
      goto GET_TIME_ERROR;
    }
    /*format print fmt*/
    snprintf(fmt_print, MAX_FMT, "[%lld][%s]:%s\n", time_ms, "debug", fmt);/*[time][debug]*/
  
    ret = vsnprintf(print, MAX_PRINT, fmt_print, arg_ptr);
    if(ret < 0)
    {
       goto ERROR;
    }
    va_end(arg_ptr);
    printf("%s", print);
    return;

ERROR:
    ERR_INFO("debug print vsnprintf error!!!");
    va_end(arg_ptr);
    return;
GET_TIME_ERROR:
    ERR_INFO("debug print get time error!!!");
    va_end(arg_ptr);
    return;
}
void ERR_PRINT(const char* fmt, ...)
{
    va_list arg_ptr;
    int ret = 0;
    char print[MAX_PRINT];/*the char that print*/
    char fmt_print[MAX_FMT] = {0};
    long long time_ms = 0;
    va_start(arg_ptr, fmt);/*arg_ptr point to the first param*/
  
    /*get local time*//*to be continued*/
    time_ms = get_runtime();
    if(time_ms == -1)
    {
      goto GET_TIME_ERROR;
    }

    /*format print fmt*/
    snprintf(fmt_print, MAX_FMT, "[%lld][%s]:%s\n", time_ms, "error", fmt);/*[time][error]*/
  
    ret = vsnprintf(print, MAX_PRINT, fmt_print, arg_ptr);
    if(ret < 0)
    {
       goto ERROR;
    }
    va_end(arg_ptr);
    printf("%s", print);
    return;

ERROR:
    ERR_INFO("err print vsnprintf error!!!");
    va_end(arg_ptr);
    return;
GET_TIME_ERROR:
    ERR_INFO("err print get time error!!!"); 
    va_end(arg_ptr);
    return;
}
