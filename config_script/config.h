#ifndef  __CONFIG_H__
#define  __CONFIG_H__

#define  FILE_POSTFIX  "conf"
#define  STRING(conf)  #conf
#define  CONFIG_FILE(name) STRING(name)



/*function*/

/*
analyze config dir 
*/
int analyze_dir(const char* config_dir);



/*
analyze config file for content and symbol
*/
int analyze_config_file(const char* config_file);

/*
find symbol 
*/
int find_symbol(const char* config_file);

/*
find content
*/
int find_content(const char* config_file);

/*

*/

#endif
