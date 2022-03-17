#include "saper.h"

SDL_Surface* draw_num_choose(int num, bool l) {
	SDL_Surface* file = SDL_LoadBMP("cross.bmp");
	if (l) {
		if (num == -2) file = SDL_LoadBMP("bomb.bmp");
		if (num == -1) file = SDL_LoadBMP("flag_l.bmp");
		if (num == 1) file = SDL_LoadBMP("saper1_l.bmp");
		if (num == 2) file = SDL_LoadBMP("saper2_l.bmp");
		if (num == 3) file = SDL_LoadBMP("saper3_l.bmp");
		if (num == 4) file = SDL_LoadBMP("saper4_l.bmp");
		if (num == 5) file = SDL_LoadBMP("saper5_l.bmp");
		if (num == 6) file = SDL_LoadBMP("saper6_l.bmp");
		if (num == 7) file = SDL_LoadBMP("saper7_l.bmp");
		if (num == 8) file = SDL_LoadBMP("saper8_l.bmp");
	}else{
		if (num == -2) file = SDL_LoadBMP("bomb.bmp");
		if (num == -1) file = SDL_LoadBMP("flag_d.bmp");
		if (num == 1) file = SDL_LoadBMP("saper1_d.bmp");
		if (num == 2) file = SDL_LoadBMP("saper2_d.bmp");
		if (num == 3) file = SDL_LoadBMP("saper3_d.bmp");
		if (num == 4) file = SDL_LoadBMP("saper4_d.bmp");
		if (num == 5) file = SDL_LoadBMP("saper5_d.bmp");
		if (num == 6) file = SDL_LoadBMP("saper6_d.bmp");
		if (num == 7) file = SDL_LoadBMP("saper7_d.bmp");
		if (num == 8) file = SDL_LoadBMP("saper8_d.bmp");}
return file;}

void draw_num(SDL_Renderer* render, int num, int x, int y, int cell, bool l) {
	SDL_Surface* file = draw_num_choose(num,l);
	SDL_Rect bg;
	set_rect(bg, cell, cell, x, y);
	SDL_Texture* one_t = SDL_CreateTextureFromSurface(render, file);
	SDL_RenderCopy(render, one_t, NULL, &bg);
}

void draw_start(SDL_Renderer* render) {
	SDL_Surface* file = SDL_LoadBMP("cross.bmp");
	SDL_Rect bg;
	set_rect(bg, 50, 50, 540, 10);
	SDL_Texture* one_t = SDL_CreateTextureFromSurface(render, file);
	SDL_RenderCopy(render, one_t, NULL, &bg);
	file = SDL_LoadBMP("start.bmp");
	set_rect(bg, 75, 300, 150, 400);
	one_t = SDL_CreateTextureFromSurface(render, file);
	SDL_RenderCopy(render, one_t, NULL, &bg);
	file = SDL_LoadBMP("name.bmp");
	set_rect(bg, 250, 500, 50, 60);
	one_t = SDL_CreateTextureFromSurface(render, file);
	SDL_RenderCopy(render, one_t, NULL, &bg);
}

void draw_play(SDL_Renderer* render) {
	SDL_Surface* file = SDL_LoadBMP("cross.bmp");
	SDL_Rect bg;
	set_rect(bg, 46, 46, 542, 12);
	SDL_Texture* one_t = SDL_CreateTextureFromSurface(render, file);
	SDL_RenderCopy(render, one_t, NULL, &bg);
	file = SDL_LoadBMP("easy.bmp");
	set_rect(bg, 100, 300, 150, 150);
	one_t = SDL_CreateTextureFromSurface(render, file);
	SDL_RenderCopy(render, one_t, NULL, &bg);
	draw_play2(render);
}


void draw_play2(SDL_Renderer* render) {
	SDL_Surface* file = SDL_LoadBMP("medium.bmp");
	SDL_Rect bg;
	set_rect(bg, 100, 300, 150, 300);
	SDL_Texture* one_t = SDL_CreateTextureFromSurface(render, file);
	SDL_RenderCopy(render, one_t, NULL, &bg);
	file = SDL_LoadBMP("hard.bmp");
	set_rect(bg, 100, 300, 150, 450);
	one_t = SDL_CreateTextureFromSurface(render, file);
	SDL_RenderCopy(render, one_t, NULL, &bg);
}
