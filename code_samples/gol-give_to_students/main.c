/*
 * Game of Life
 * 
 * A version of John Conway's classic Game of Life, written in C.
 * CIS 343 - Winter 2019
 * 
 * Author:  BE SURE TO PUT YOUR NAME HERE
 *
 * This program saves and loads games using the following format:
 * The first byte of the file is the height.
 * The second byte of the file is the width.
 * The remaining bytes of the file are either zeros or ones,
 * where a one is a live cell and a zero is no cell.
 * Unlike some versions we will not keep track of where a cell
 * was when it died; i.e. when a cell dies it is just gone.
 * If the height of the file is h and the width is w, the
 * total size of the file in bytes would then be (h x w) + 2.
 */

#include "file_library.h"
#include "life.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	// The program requires a file name to start.
	if(argc != 2){
		printf("This program requires a file name and no other parameters to start.\n\n");
		return(1);
	}

	// This char* will hold the bytes read from the file.
	char* grid_text;

	// Since C has no objects, we can't ask the array how
	// long it is.  So we must keep track ourselves.
	size_t bytes_read = read_file(argv[1], &grid_text);	
	// The first and second byte in the file is height and width.
	int x = grid_text[0];
	int y = grid_text[1];

	// grid holds the game board.  The game board
	// is x arrays of arrays of length y
	// Notice that here x refers to the "row" and
	// y to the "column" if you want to view the
	// structure that way.
	char** grid = get_grid(x, y);

	printf("Beginning with grid size %d, %d.\n\n", x, y);

	// We read the file in as a sequence of bytes.  Now we
	// need to convert that into a x*y grid.
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			// Fill the values in the grid from the file.
			grid[i][j] = *(grid_text+(i*y)+j+2);
		}
	}

	print_grid(x, y, grid);

	// Now, we will accept input in a loop until the user
	// asks us to quit.
	while(1){
		char fn[5];
		printf("Press q to quit, w to save to disk,\n");
		printf("n to iterate multple times, or any other\n");
		printf("key to continue to the next generation.\n");
		fgets(fn, 5, stdin);
		printf("-------------------------\n");

		switch(fn[0]){

			case 'q':
				// Case 'q' results in exiting the game.  We must free
				// our memory here.
				return 0;

			case 'w':
				// Case 'w' writes the current board to disk.  Since
				// a file is just a string of bytes, we must first
				// convert our grid to some representation that is
				// a string of bytes.  We will use the representation
				// described in the top of this file.
				printf("Enter a filename: ");
				char filename[254];
				fgets(filename, 254, stdin);

				// Convert our board to a string of bytes
				char* contents = (char*) malloc( sizeof(char) * ((x*y)+2));
				for(int i=0;i<x;++i){
					for(int j=0; j<y; ++j){
						contents[i*y+j] = grid[i][j];
					}
				}
				for(int i=(x*y)+2; i>1; --i){
					contents[i] = contents[i-2];
				}
				// Make sure the first two bytes are the
				// height and width.
				contents[0] = x;
				contents[1] = y;
				write_file(filename, contents, bytes_read); 
				break;

			case 'n':
				// 'n' causes us to ask the user how
				// many evolutions to perform in a row,
				// then executes them in a loop.
				printf("How many iterations? ");
				int num = 0;
				char buf[5];
				fgets(buf, 5, stdin);
				num = atoi(buf);

				printf("Iterating %d times.\n\n", num);
				for(int i=0; i<num; ++i){
					grid = mutate(x, y, grid);
					print_grid(x, y, grid);
				}	
				break;

			default:
				// Any other key and we evolve one iteration,
				// print, and keep going.
				grid = mutate(x, y, grid);
				print_grid(x, y, grid);
		}
	}
}
