#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){
	pid_t child;
	
	// Who is the ppid here?
	int main = (int)getppid();
	int parent = (int)getpid();

	printf("Main process id is %d.\n\n", main);
	child = fork();
	if(child != 0){
		printf("Hello from a parent: %d with a child %d.\n", parent, child);
	} else {
		// Note I am calling getpid() here instead of just using child
		// for "proof".  Also note the child has all the variables
		// the parent had.
		printf("Hi, I'm a kiddo.  My id is %d.  My parent is %d.\n", (int)getpid(), parent);
	}
}
