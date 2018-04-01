#include <stdio.h>
#include <stdarg.h>

void print_args(const char *str, ...){
	va_list ap;
	va_start(ap, str);
	while(str){
		printf("%s\n", str);	
		str = va_arg(ap, const char *);
	}
	va_end(ap);
}

int main(int argc, char** argv){
	print_args("Ira", "Jacob", "Woodring", NULL);
}
