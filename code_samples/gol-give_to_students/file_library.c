#include "file_library.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

/* read_file reads a string of bytes into memory
 * at the location provided by contents.
 */
size_t read_file(char* file_name, char** contents){
	struct stat st;
	stat(file_name, &st);
	FILE* file = fopen(file_name, "r");
	*contents = (char*) malloc(st.st_size * sizeof(char));
	size_t num_bytes = fread(*contents, st.st_size, 1, file);
	fclose(file);
	return st.st_size;
}

/* write_file writes a string of bytes to disk */
size_t write_file(char* file_name, char* contents, size_t size){

}
