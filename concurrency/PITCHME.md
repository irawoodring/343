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

An example of competition might be a shared counter among four threads.
---
Languages provide support for concurrency in a variety of different ways.  It can be built into the language, provided by a library, etc.
