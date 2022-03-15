#include "saper.h"

void one(SDL_Renderer* render, SDL_Window* window, int x, int y, int cell) {
	SDL_Surface* one = IMG_Load("saper1.png");
	SDL_Surface* scr = NULL;
	scr = SDL_GetWindowSurface(window);

	if (one == NULL) {
		cout << "can't load pic:  " << IMG_GetError() << endl;
		return;
	}

	one = SDL_ConvertSurface(one, scr->format, NULL);

	if (one == NULL) {
		cout << "can't convert:   " << IMG_GetError() << endl;
		return;
	}

	SDL_Rect bg_one;
	bg_one.h = cell;
	bg_one.w = cell;
	bg_one.x = x;
	bg_one.y = y;
	SDL_BlitScaled(one, NULL, scr, &bg_one);
	SDL_RenderPresent(render);
	SDL_UpdateWindowSurface(window);
	//SDL_Delay(3000);
}