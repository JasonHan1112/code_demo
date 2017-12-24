#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


#include "config.h"

#define PRINT_TAG "SCRIPT.CONF" /*print tag for look up log*/

#define DEBUG_INFO(fmt, args...) \
        printf("[%s][%s][%s]:"fmt"\n", PRINT_TAG, "debug", __FUNCTION__, ##args)
#define ERR_INFO(fmt, args...) \
        printf("[%s][%s][%s]:"fmt"\n", PRINT_TAG, "error", __FUNCTION__, ##args)

#define FIRST_FLAG ""

#define LINE_CHAR 10
#define COL_CHAR 128



static char read_buf[LINE_CHAR*COL_CHAR];/*read buf*/
static char* read_line[LINE_CHAR];/*each line pointer*/

int analyze_dir(const char* config_dir)
{
  int ret = 0;
  struct stat file_st;
  char file_path[128];
  memset(file_path, 0, sizeof(file_path));
  if(strlen(config_dir) > 100)/*dir length*/
  {
    goto CONFIG_DIR_ERR;
  }
  snprintf(file_path, sizeof(file_path), "%sscript.conf", config_dir);
  /*find name in dir*/
  ret = stat(file_path, &file_st);
  if(ret != 0)
  {
    goto STAT_ERR;
  }
  DEBUG_INFO("script.conf exist");
  return 0;

CONFIG_DIR_ERR:
  ERR_INFO("config dir error!!!");
  return -1;

STAT_ERR:
  ERR_INFO("stat error!!!");
  return -1;
}

/*need fix*/
int analyze_config_file(const char* config_file, char* fmt, int* a, int* b, int* c, int* d)
{
  int ret = 0;
  ret = open(config_file, O_RDONLY);
  if(ret < 0)
  {
    goto OPEN_CONF_ERR;
  }
  ret = find_lines(ret);
  if(ret != 0)
  {
    goto ERR_FIND_LINES;
  }

  ret = find_content(read_line, fmt, a, b, c, d);/*need fix*/

  {
    goto ERR_FIND_CONTENT;
  }

  return 0;



ERR_FIND_LINES:
  ERR_INFO("find lines!!!");
  return -1;

OPEN_CONF_ERR:
  ERR_INFO("open config file error!!!");
  return -1;
ERR_FIND_CONTENT:
  ERR_INFO("find content error!!!");
  return -1;
}

static int find_lines(int fd_file)
{
  int ret = 0;
  unsigned long length_file = 0;
  int count_char = 0;
  int count_line = 0;
  char* tmp_line = NULL;
  memset(read_buf, 0, sizeof(read_buf));
  
  length_file = lseek(fd_file, 0, SEEK_END);
  //DEBUG_INFO("length_file = %ul", length_file);
  lseek(fd_file, 0, SEEK_SET);

  if(length_file > LINE_CHAR*COL_CHAR)
  {
    goto FILE_LENGTH_OVERFLOW;
  }

  ret = read(fd_file, read_buf, sizeof(read_buf));
  //DEBUG_INFO("fd_file = %d, sizeof(read_buf) = %d", fd_file, sizeof(read_buf));
  if(ret < 0)
  {
    goto ERR_READ_CON_FIL;
  }
  memset(read_line, 0, sizeof(read_line));/*clear lines pointer*/
  tmp_line = read_buf;/*the first line*/
  
  /*split lines and copy lines*/
  for(count_char=0; count_char<length_file; count_char++)
  {
    
    if(read_buf[count_char] == '\n')
    {
      read_buf[count_char] = 0x0;/*split line*/
      
      /*copy each line*/
      read_line[count_line] = (char*)malloc(strlen(tmp_line)+1);
      
      if(read_line[count_line] == NULL)
      {
        goto MALLOC_ERROR;
      }
      memset(read_line[count_line], 0, strlen(tmp_line)+1);
      memcpy(read_line[count_line], tmp_line, strlen(tmp_line)+1);
      count_line++;
      tmp_line = &read_buf[count_char+1];
      
    } 
  }
 
  close(fd_file);
  return 0;


MALLOC_ERROR:
  ERR_INFO("read_line malloc error");
  return -1;
FILE_LENGTH_OVERFLOW:
  ERR_INFO("config file overflow error!!!");
  return -1;
ERR_READ_CON_FIL:
  ERR_INFO("read config file error!!!");
  perror("read error");
  return -1;
}
/*4 parameters in one line*//*fmt = "%d %d %d %d"*//*need fix*/
static int find_content(char* readline[], char* fmt, int* a, int* b, int* c, int* d)
{
  int i = 0;
  char* p_ret = NULL;
  int ret = 0;
  while(readline[i])
  {
    p_ret = strstr(readline[i], "#");
    if(p_ret)/*comment lines*/
    {
      i++;
      continue;
    }
    else/*valid lines*/
    {
#if 1/*debug need fix*/
      sscanf(readline[i], fmt, a,b,c,d);
      DEBUG_INFO("valid lines = %s, line = %d", readline[i], i+1);
      printf("a = %d\n", *a);
      printf("b = %d\n", *b);
      printf("c = %d\n", *c);
      printf("d = %d\n", *d);
#endif
      i++;
    }
    
  }
  return 0;
}
static int resolve(char* readline)
{

}
static int freelines(char* readline[])
{
  int i = 0;
  while(readline[i])
  {
    free(readline[i]);
    readline[i] = NULL;
    i++;
  }
  
}
