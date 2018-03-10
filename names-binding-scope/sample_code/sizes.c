#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char** argv){
	printf("Type\t\t\tBytes\t\tMin Value\t\tMax Value\n");
	printf("---------------------------------------------------------------------------\n");
	printf("unsigned char\t\t%lu\t\t%d\t\t\t%d\n", sizeof(unsigned char), 0, UCHAR_MAX);
	printf("char\t\t\t%lu\t\t%d\t\t\t%d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
	printf("unsigned int\t\t%lu\t\t%d\t\t\t%u\n", sizeof(unsigned int), 0, UINT_MAX);
	printf("int\t\t\t%lu\t\t%d\t\t%d\n", sizeof(int), INT_MIN, INT_MAX);
	printf("unsigned long\t\t%lu\t\t%d\t\t\t%lu\n", sizeof(unsigned long), 0, ULONG_MAX);
	printf("long\t\t\t%ld\t\t%ld\t%ld\n", sizeof(long), LONG_MIN, LONG_MAX);
	printf("unsigned long long\t%lu\t\t%d\t\t\t%llu\n", sizeof(unsigned long long), 0, ULLONG_MAX);
	printf("long long\t\t%lu\t\t%lld\t%lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
	printf("float\t\t\t%lu\t\t%e\t\t%e\n", sizeof(float), -FLT_MAX, FLT_MAX);
	printf("double\t\t\t%lu\t\t%e\t\t%e\n", sizeof(double), -DBL_MAX, DBL_MAX);
	printf("long double\t\t%lu\t\t%Le\t\t%Le\n", sizeof(long double), -LDBL_MAX, LDBL_MAX);
}
