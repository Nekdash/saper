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
void set_color(SDL_Renderer* render, string color); // love of my life

//saper.cpp
void set_level(int level, int& width, int& height, int& num_bombs, int &cell);
void clear_bombs(int width, int height, vector<vector<int> >& bombs);
void set_bombs(int& num_bombs, int width, int height, vector<vector<int> >& bombs);
void setup(vector<vector<int> >& bombs, vector<vector<bool> >& revealed, vector<vector<bool> >& flags, const int& width, const int& height);
void set_flag(int x, int y);
void reveal(int x, int y, vector<vector<bool> >& revealed, vector<vector<int> >& bombs);
int count_bombs(int x, int y, vector<vector <int> >& bombs);
bool bounds(int x, int y, vector<vector <int> >& bombs);


//scenes.cpp
//main is here as well
void rules(SDL_Window* window, SDL_Renderer* render, SDL_Event event, int level);
void play(SDL_Window* window, SDL_Renderer* render, SDL_Event event);
void start(SDL_Window* window, SDL_Renderer* render, SDL_Event event);

//buttons.cpp - useless place, like me
bool easy_button(int x, int y);
bool medium_button(int x, int y);
bool hard_button(int x, int y);
bool close(int x, int y);

//game.cpp

void game(SDL_Window* window, SDL_Renderer* render, SDL_Event event, int level);