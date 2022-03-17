#include "saper.h"

void draw_winlose(SDL_Renderer* render, bool win) {
	if (win) {
		SDL_Surface* file = SDL_LoadBMP("win.bmp");
		SDL_Rect bg;
		bg.h = 50;
		bg.w = 300;
		bg.x = 150;
		bg.y = 25;
		SDL_Texture* one_t = SDL_CreateTextureFromSurface(render, file);
		SDL_RenderCopy(render, one_t, NULL, &bg);
	}
	else {
		SDL_Surface* file = SDL_LoadBMP("lose.bmp");
		SDL_Rect bg;
		bg.h = 50;
		bg.w = 300;
		bg.x = 150;
		bg.y = 25;
		SDL_Texture* one_t = SDL_CreateTextureFromSurface(render, file);
		SDL_RenderCopy(render, one_t, NULL, &bg);
	}
}

void draw_game(SDL_Renderer* render) {
	rect(render, 0, 0, 100, 600, "g");
	rect(render, 480, 10, 50, 50, "lg"); // restart
	rect(render, 540, 10, 50, 50, "lg"); // cross
	SDL_Surface* file = SDL_LoadBMP("cross.bmp");
	SDL_Rect bg;
	bg.h = 46;
	bg.w = 46;
	bg.x = 542;
	bg.y = 12;
	SDL_Texture* one_t = SDL_CreateTextureFromSurface(render, file);
	SDL_RenderCopy(render, one_t, NULL, &bg);

	file = SDL_LoadBMP("restart.bmp");
	bg.h = 46;
	bg.w = 46;
	bg.x = 482;
	bg.y = 12;
	one_t = SDL_CreateTextureFromSurface(render, file);
	SDL_RenderCopy(render, one_t, NULL, &bg);
}


void draw_rules(SDL_Renderer* render) {
	SDL_Surface* file = SDL_LoadBMP("cross.bmp");
	SDL_Rect bg;
	bg.h = 46;
	bg.w = 46;
	bg.x = 542;
	bg.y = 12;
	SDL_Texture* one_t = SDL_CreateTextureFromSurface(render, file);
	SDL_RenderCopy(render, one_t, NULL, &bg);
	file = SDL_LoadBMP("play.bmp");
	bg.h = 75;
	bg.w = 300;
	bg.x = 150;
	bg.y = 600;
	one_t = SDL_CreateTextureFromSurface(render, file);
	SDL_RenderCopy(render, one_t, NULL, &bg);
	file = SDL_LoadBMP("rules.bmp");
	bg.h = 500;
	bg.w = 400;
	bg.x = 100;
	bg.y = 60;
	one_t = SDL_CreateTextureFromSurface(render, file);
	SDL_RenderCopy(render, one_t, NULL, &bg);
}
