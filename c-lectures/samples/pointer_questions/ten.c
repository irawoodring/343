#include<stdio.h> 
void f(int *p, int *q) 
{ 
	p = q; 
	*p = 2; 
} 
int i = 0, j = 1; 
int main(int argc, char** argv) 
{ 
	f(&i, &j); 
	printf("%d %d n", i, j); 
	getchar(); 
	return 0; 
}
