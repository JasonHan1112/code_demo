#ifndef __DEBUG_H__
#define __DEBUG_H__
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>	
#include <errno.h>
	
#define DEBUG

#ifdef DEBUG
#define DEBUG_INFO(fmt,args...) \
printf("[DEBUG]:fun: %s, line: %d; "fmt"\n",__FUNCTION__,__LINE__,##args)

#else
#define LOG_FILE "log_file"
#define LOG_INFO_BUF 512
#define DEBUG_INFO(fmt,args...) \
do\
{\
    int fd_log = -1;\
    char log_info_buf[LOG_INFO_BUF];\
    memset(log_info_buf,0,sizeof(log_info_buf));\
    fd_log = open(LOG_FILE,O_CREAT | O_APPEND | O_RDWR,777);\
    if(fd_log == -1)\
    {\
        printf("open log_file error!!!\nerror code: %s\n",strerror(errno));\
        break;\
    }\
    sprintf(log_info_buf,"[DEBUG]:fun: %s, line: %d; "fmt"\n",__FUNCTION__,__LINE__,##args);\
    write(fd_log,log_info_buf,strlen(log_info_buf));\
    close(fd_log);\
}while(0);

#endif


######################################################
#ifdef DEBUG #define DEBUG_ERR(format,args...) \
do{ \
    printk("[%s:%d] ",__FUNCTION__,__LINE__); \
    printk(format,##args); \
}while(0)
#else
#define DEBUG_PRINT(format,args...)
#endif

######################################################

#endif


