#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include "saper.h"

using namespace std;

//WELCOME TO HEADER FILE!!

//draw.cpp
void verticalLine(SDL_Renderer* render, int x, int y, int length);
void rect(SDL_Renderer* render, int x, int y, int h, int w);
void rect(SDL_Renderer* render, int x, int y, int h, int w, string color);
void verticalLine(SDL_Renderer* render, int x, int y, int length, string color);
void set_color(SDL_Renderer* render, string color);




void set_level(int level);
void set_bombs();
void setup();
void set_flag(int x, int y);
void reveal(int x, int y);
void draw_num(int x, int y);
int count_bombs(int x, int y);
bool bounds(int x, int y);

//scenes.cpp
//main is here as well
void play(SDL_Window* window, SDL_Renderer* render, SDL_Event event);
void start(SDL_Window* window, SDL_Renderer* render, SDL_Event event);

//buttons.cpp
bool play_button(SDL_Event event);
bool close(SDL_Event event);