---
CIS 343 - Structure of Programming Languages

Ira Woodring

***

Concurrency

(Follows the Sebesta Text Chapter 13)
---
Beginning in the 1950s we had computers that had more than one processor.

The first ones had one general-purpose processor and others for input and output (these were called peripheral processors).
---
In the 1960s we got machines with multiple processors.  At this point the operating system could choose to send individual jobs to the individual processors.

In the mid 1960s we began to get machines that could separate a single stream of code out to multiple processors.
---
Michael Flynn created a way to categorize machines in 1966.  He saw the different types of computer architectures as fitting into one of four categories:

  - SISD - Single-Instruction Single Data
  - SIMD - Single-Instruction Multiple Data
  - MISD - Multiple-Instruction Single Data
  - MIMD - Multiple-Instruction Multiple Data
---
SISD machines are sequential machines with no parallelism.  There is a single instruction stream and a single data stream.
---
SIMD machines have a single instruction stream but multiple data streams.  The single instruction stream operates on all of the data streams at once (via one processor controlling sub-processors).

The are often used for graphics and video processing, but many scientific, financial, and other applications exist.
---
MISD machines have multiple instructions working on one set of data.  These are rare.
---
MIMD have multiple instruction and data streams.  Examples include both distributed systems and multiprocessor systems.
---
There are two categories of concurrency - physical and logical.

Physical concurrency occurs when there are multiple processors and multiple program units from the same program run at the same time.

Logical concurrency is an interleaving of subprograms so it appears that physical concurrency is happening on a single processor.
---
These should appear the same from the programmer's point of view.
---
Programs can have multiple processes or multiple threads.  In general, processes will run in their own memory spaces while threads run in a shared memory space.

Processes may have multiple threads that share the process's resources.
---
Synchronization is imperative for concurrency to work.  There are two types of synchronization:

- Cooperation synchronization
- Competition synchronization
---
Cooperation synchronization happens when some task A must wait for a task B to finish come computation before A can continue.

Competition synchronization occurs when there is a shared resource that two tasks must access, but they cannot access it simultaneously.
---
An example of cooperation is when a process is relying upon some other process to produce some data before computation can continue.

An example of competition might be a shared counter among some threads:
---
```C
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
```
---
Languages provide support for concurrency in a variety of different ways.  It can be built into the language, provided by a library, etc.
---
C does not provide native support for concurrency, but does have the ability through other libraries.

We can control threads and processes through libraries.

For threads, we often use the pthread (POSIX thread) library.
---
Pthreads provides mechanisms for manipulating threads, synchronization of threads, and protection of variables used by threads.

We create threads with the ```pthread_create()``` function.  In general, we usually create threads, let them run, and wait for them to complete.  The "waiting" is usually done by a ```pthread_join()``` - a blocking call.
---
The signatures for these two functions are as follows:

```C
int pthread_create(pthread_t * thread, const pthread_attr_t * attr,
        void * (*start_routine)(void *), void * arg);
int pthread_join(pthread_t thread, void ** status);
```
---
The most important thing to note here is that the start_routine signature.  This is the function that the thread wraps.  It has a void* return type, and can take a single parameter through \*arg.

For instance:
---
```C
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
```
---
We can perform multiprocessing in C as well, by forking off child processes.  Remember, these processes have their own execution environment.  They will have a copy of all the parent process had:

```C
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
```
---
Unlike C, Java has concurrency built-in.  We can do multiprocessing and multithreading in Java, but we usually need a very good reason to do multiprocessing.  This is because each process needs its own version of the JVM, which is quite heavy.
---
We will explore Java's multithreading capabilities here.

Java's API provides Thread objects.  Threads need to adhere to the [Runnable](https://docs.oracle.com/javase/8/docs/api/java/lang/Runnable.html) interface, which dictates they must have a ```void run()``` function.
---
```Java
public class Counter implements Runnable {

        private int my_num;

        public Counter(int my_num){
                this.my_num = my_num;
        }

        public void run(){
                System.out.println("Hello from " + my_num + "!");
        }

        public static void main(String[] args){
                Thread[] threads = new Thread[10];
                for(int i=0; i<10; i++){
                        threads[i] = new Thread(new Counter(i));
                        threads[i].start();
                }

                for(int i=0; i<10; i++){
                        try{
                                threads[i].join();
                        } catch (Exception ex){

                        }
                }
        }

}
```
---
Java provides a huge facility of additional Objects and Interfaces for threading and the sharing of data between threads.
---
