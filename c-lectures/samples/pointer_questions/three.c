#include <stdio.h>

int main(int argc, char** argv)
{
	int *ptr;
	int x;

	ptr = &x;
	*ptr = 0;

	printf(" x = %dn", x);
	printf(" *ptr = %dn", *ptr);

	*ptr += 5;
	printf(" x  = %dn", x);
	printf(" *ptr = %dn", *ptr);

	(*ptr)++;
	printf(" x = %dn", x);
	printf(" *ptr = %dn", *ptr);

	return 0;
}
