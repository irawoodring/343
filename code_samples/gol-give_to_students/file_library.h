#ifndef		__H_FILE_LIBRARY__
#define		__H_FILE_LIBRARY__

#include <stdio.h>

size_t read_file(char* file_name, char** contents);
size_t write_file(char* file_name, char* contents, size_t size);

#endif
