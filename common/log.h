#pragma once

#define __DEBUG //日志总开关

// #define _OCR_LOG_

#ifdef __DEBUG

// const char* get_file_base_name(const char *file){
//     if(file == nullptr) return file;
//     char* ret = strrchr((char*)file, '/');
//     if(ret == nullptr){
//         return file;
//     }
//     return ret + 1;
// }

#define __LOG_LEVEL__   1

#define __LV_DEBUG__    1
#define __LV_INFO__     2
#define __LV_WARNING__  3
#define __LV_ERROR__    4
#define __LV_FATAL__    5

#define TITLE(fmt, ...) \
do{\
    printf("[TIME][TITLE]""=====\033[36m " fmt " \033[0m=====""\n", ##__VA_ARGS__);\
}while(0)


#define DEBUG(fmt, ...) \
do{\
    if(__LOG_LEVEL__ <= __LV_DEBUG__){\
        printf("[TIME][\033[1;32mDEBUG  \033[0m][%s(%d) %s]\n" fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
    }\
}while(0) 

#define INFO(fmt, ...) \
do{\
    if(__LOG_LEVEL__ <= __LV_INFO__){\
        printf("[TIME][\033[1;34mINFO   \033[0m][%s(%d) %s]\n" fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
    }\
}while(0)

#define WARNING(fmt, ...) \
do{\
    if(__LOG_LEVEL__ <= __LV_WARNING__){\
        printf("[TIME][\033[1;33mWARNING\033[0m][%s(%d) %s]\n" fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
    }\
}while(0)

#define ERROR(fmt, ...) \
do{\
    if(__LOG_LEVEL__ <= __LV_ERROR__){\
        printf("[TIME][\033[1;31mERROR  \033[0m][%s(%d) %s]\n" fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
    }\
}while(0)

#define FATAL(fmt, ...) \
do{\
    if(__LOG_LEVEL__ <= __LV_FATAL__){\
        printf("[TIME][\033[1;37;41mFATAL  \033[0m][%s(%d) %s]\n" fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
    }\
}while(0)

#else

#define TITLE(fmt, ...)

#define DEBUG(fmt, ...)
#define INFO(fmt, ...)
#define WARNING(fmt, ...)
#define ERROR(fmt, ...)
#define FATAL(fmt, ...)

#endif



