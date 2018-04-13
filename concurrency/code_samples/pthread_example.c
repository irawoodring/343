#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct args {
	int x;
	float y;
} params;

void* function_to_thread(void* arguments){
	params args = *((params*)arguments);
	printf("Hello!  I am %d and I got %f!\n", args.x, args.y);

	return NULL;
}

int main(int argc, char** argv){
	pthread_t threads[10];
	for(int i=0; i<10; i++){
		params p;
		p.x = i;
		p.y = 3.14;
		int result = pthread_create(&threads[i], NULL, function_to_thread, &p);
	}

	for(int i=0; i<10; i++){
		int result = pthread_join(threads[i], NULL);
	}
}
