#ifndef		__H_LIFE__
#define		__H_LIFE__

char** get_grid(int x, int y);
void print_grid(int x, int y, char** grid);
char** mutate(int x, int y, char** grid);
int get_neighbors(int i, int j, int x, int y, char** grid);

#endif
