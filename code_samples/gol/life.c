#include "life.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * get_grid creates new memory for a "grid".
 * x is the height and y is the width.
 */
char** get_grid(int x, int y){
	char** grid = (char**) malloc(x * sizeof(char* ));
	for(int i=0; i<x; i++){
		grid[i] = (char*)malloc(y * sizeof(char));
	}
	return grid;
}

/*
 * print_grid attempts to print an x height
 * by y width grid stored at the location
 * provided by grid
 */
void print_grid(int x, int y, char** grid){
	for(int i=0; i<x; ++i){
		for(int j=0; j<y; ++j){
			if(grid[i][j] == 0){
				printf(" . ");
			} else {
				printf(" X ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

/*
 * mutate takes a grid and mutates that grid
 * according to Conway's rules.  A new grid
 * is returned.
 */
char** mutate(int x, int y, char** grid){
	char** new_grid = get_grid(x,y);
	for(int i=0; i<x; ++i){
		for(int j=0; j<y; ++j){
			int neighbors = get_neighbors(i, j, x, y, grid);
			if(grid[i][j] == 1){
				if(neighbors <2 || neighbors >3){
					new_grid[i][j] = 0;
				} else {
					new_grid[i][j] = 1;
				}
			} else {
				if(neighbors == 3){
					new_grid[i][j] = 1;
				}
			}
		}
	}
	return new_grid;
}

/* get_neighbors is a helper method that returns
 * the number of live neighbors a cell has.
 */
int get_neighbors(int i, int j, int x, int y, char** grid){
	int neighbors = 0;
	for(int a=-1; a<2; ++a){
		for(int b=-1; b<2; ++b){
			if(a==0 && b==0){
				continue;
			}
			int m = i+a;
			int n = j+b;
			if( m >=0 && m< x && n >=0 && n<y){
				neighbors += grid[m][n];
			}
		}
	}
	return neighbors;
}
