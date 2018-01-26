# The Game of Life

The Game of Life was developed by John Conway (a British mathematician) in the 1970s.  It is an example of a **cellular automaton**, a data structure that seems to evolve iteratively.  You can learn more about them [Here](http://web.stanford.edu/~cdebs/GameOfLife/ "Game of Life information"), and even play with a simulator.

## Assignment

We will be writing a simulator in C.  Our simulator will use the following rules (from the aforementioned web pages if you wish to see them in more detail):

- Any live cell with fewer than two neighbors dies (underpopulation)
- Any live cell with more than three neighbors dies (overcrowding)
- Any live cell with two or more live neighbors lives another generation
- Any dead cell with exactly three live neighbors become a live cell

The following criteria for your program must be met:

- The "universe" will be a dynamically allocated data structure (meaning you must use ```malloc``` to create your arrays).  The size of the universe will be passed in as command-line parameters (i.e. ```./life 4 5)``` will create a 4x5 grid.
- We must be able to save and load the files.
- After each generation the universe will be printed and the user will be asked if they wish to save, load, continue another generation, continue some number of iterations, or quit.
- We will ```free``` all memory we ```malloc```.
- Files will be read and written via two functions
  - ```int read_file( char* filename, char **buffer );
  int write_file( char* filename, char *buffer, int size);
  ```
- File saving/loading functions should be included in the files "file_utilities.h" and "file_utilities.c".

## Rubric

|                                     | Complete (10 pts) | Incomplete (1-9 pts) | Not attempted (0 pts) |
|-------------------------------------|-------------------|----------------------|-----------------------|
| Meets all criteria specified        |                   |                      |                       |
| Adheres to style guide              |                   |                      |                       |
| Compiles without errors or warnings |                   |                      |                       |
| Properly cites resources used       |                   |                      |                       |
| On time                             |                   | 1 day late           | > 1 day late          |

## Submission

Submit your Github clone URL to Blackboard by 2/12/18.
