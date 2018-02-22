#ifndef			__ZOOMJOYSTRONG__
#define			__ZOOMJOYSTRONG__

#include <SDL2/SDL.h>

#define			HEIGHT	768
#define			WIDTH	1024

struct color{
	int r;
	int g;
	int b;
};

SDL_Texture* texture;
SDL_Renderer* renderer;
SDL_Window* window;

void setup();
void set_color( int r, int g, int b);
void point( int x, int y );
void line( int x1, int y1, int x2, int y2 );
void circle( int x, int y, int r);
void rectangle( int x, int y, int w, int h);
void finish();
void sdl_ellipse(SDL_Renderer* r, int x0, int y0, int radiusX, int radiusY);
 
#endif
