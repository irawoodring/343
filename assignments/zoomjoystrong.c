#include "zoomjoystrong.h"
#include <math.h>
#include <SDL2/SDL.h>
#include <unistd.h>

struct color current;

void setup(){
	window = SDL_CreateWindow
		(
		 "ZoomJoyString", SDL_WINDOWPOS_UNDEFINED,
		 SDL_WINDOWPOS_UNDEFINED,
		 WIDTH,
		 HEIGHT,
		 SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_SHOWN
		);

	renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT);
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderSetScale( renderer, 3.0, 3.0 );

	SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
	SDL_RenderClear( renderer );
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255);	
	current.r = 0;
	current.b = 0;
	current.g = 0;
}

void set_color( int r, int g, int b){
	current.r = r;
	current.b = g;
	current.g = b;
	SDL_SetRenderDrawColor( renderer, r, g, b, 255);
}

void point( int x, int y ){
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderDrawPoint(renderer, x, y);	
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void line( int x1, int y1, int x2, int y2 ){
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void circle(int x, int y, int r){
	for(float i=0; i<2 * 3.14; i+=.01){
		float u = x + r * cos(i);
		float v = y + r * sin(i);
		point(u, v);
	}
} 

void rectangle(int x, int y, int w, int h){
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderDrawRect(renderer, &rect);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void finish(){
	SDL_Delay(5000);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

/*
 * From https://stackoverflow.com/questions/38334081/howto-draw-circles-arcs-and-vector-graphics-in-sdl
 */

void sdl_ellipse(SDL_Renderer* r, int x0, int y0, int radiusX, int radiusY)
{
	float pi  = 3.14159265358979323846264338327950288419716939937510;
	float pih = pi / 2.0; //half of pi

	//drew  28 lines with   4x4  circle with precision of 150 0ms
	//drew 132 lines with  25x14 circle with precision of 150 0ms
	//drew 152 lines with 100x50 circle with precision of 150 3ms
	const int prec = 27; // precision value; value of 1 will draw a diamond, 27 makes pretty smooth circles.
	float theta = 0;     // angle that will be increased each loop

	//starting point
	int x  = (float)radiusX * cos(theta);//start point
	int y  = (float)radiusY * sin(theta);//start point
	int x1 = x;
	int y1 = y;

	//repeat until theta >= 90;
	float step = pih/(float)prec; // amount to add to theta each time (degrees)
	for(theta=step;  theta <= pih;  theta+=step)//step through only a 90 arc (1 quadrant)
	{
		//get new point location
		x1 = (float)radiusX * cosf(theta) + 0.5; //new point (+.5 is a quick rounding method)
		y1 = (float)radiusY * sinf(theta) + 0.5; //new point (+.5 is a quick rounding method)

		//draw line from previous point to new point, ONLY if point incremented
		if( (x != x1) || (y != y1) )//only draw if coordinate changed
		{
			SDL_RenderDrawLine(r, x0 + x, y0 - y,    x0 + x1, y0 - y1 );//quadrant TR
			SDL_RenderDrawLine(r, x0 - x, y0 - y,    x0 - x1, y0 - y1 );//quadrant TL
			SDL_RenderDrawLine(r, x0 - x, y0 + y,    x0 - x1, y0 + y1 );//quadrant BL
			SDL_RenderDrawLine(r, x0 + x, y0 + y,    x0 + x1, y0 + y1 );//quadrant BR
		}
		//save previous points
		x = x1;//save new previous point
		y = y1;//save new previous point
	}
	//arc did not finish because of rounding, so finish the arc
	if(x!=0)
	{
		x=0;
		SDL_RenderDrawLine(r, x0 + x, y0 - y,    x0 + x1, y0 - y1 );//quadrant TR
		SDL_RenderDrawLine(r, x0 - x, y0 - y,    x0 - x1, y0 - y1 );//quadrant TL
		SDL_RenderDrawLine(r, x0 - x, y0 + y,    x0 - x1, y0 + y1 );//quadrant BL
		SDL_RenderDrawLine(r, x0 + x, y0 + y,    x0 + x1, y0 + y1 );//quadrant BR
	}
}
