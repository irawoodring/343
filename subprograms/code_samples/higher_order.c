#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
	return a + b;
}

int mult(int a, int b){
	return a * b;
}

int main(int argc, char** argv){
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = atoi(argv[3]);

	int (*fun)(int,int) = &add;
	if(c != 0){
		fun = &mult;
	}
	int result = (*fun)(a,b);
	printf("%d\n", result);
}
