#ifndef  __CONFIG_H__
#define  __CONFIG_H__

#define  FILE_POSTFIX  "conf"
#define  STRING(conf)  #conf
#define  CONFIG_FILE(name) STRING(name)



/*function*/

/*
*analyze config dir 
*/
int analyze_dir(const char* config_dir);



/*
*analyze config file for content and symbol
*/
int analyze_config_file(const char* config_file, char* fmt, int* a, int* b, int* c, int* d);

/*
*find symbol 
*/
static int find_lines(int fd_file);

/*
*find content
*/
static int find_content(char* readline[], char* fmt, int* a, int* b, int* c, int* d);

/*
*resolve parameters
*/
static int resolve(char* readline);


/*
*free each line
*/
static int freelines(char* readline[]);

#endif
