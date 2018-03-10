#include <stdio.h>

char doSomething(int successful){
	if(successful>0){
		return 'a';
	} 
	return -1;
}

int main(int argc, char** argv){
	char result = doSomething(1);
	printf("%d\n", result);
	result = doSomething(-1);
	printf("%d\n", result);
}
