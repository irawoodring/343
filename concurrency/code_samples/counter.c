#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct params {
	int id;
} params_t;

void* say_hi(void* arg){
	int id;
	id = (*(params_t*)(arg)).id;
	printf("Hello from %d\n", id);
}

int main(int argc, char** argv){
	pthread_t threads[10];
	params_t params;
	for(int i=0; i<10; i++){
		params.id = i;
		if(pthread_create(&threads[i], NULL, say_hi, &params)){
			// Thread created.
		}
	}

	for(int i=0; i<10; i++){
		pthread_join(threads[i], NULL);
	}
}
