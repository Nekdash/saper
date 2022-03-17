#pragma once
#include <iostream>
#include <vector>
#include "SDL2/include/SDL.h"
#include "SDL2_image-2.0.5/include/SDL_image.h"
#include "saper.h"

using namespace std;

//WELCOME TO THE HEADER FILE!!

//draw.cpp
void verticalLine(SDL_Renderer* render, int x, int y, int length);
void rect(SDL_Renderer* render, int x, int y, int h, int w);
void rect(SDL_Renderer* render, int x, int y, int h, int w, string color);
void verticalLine(SDL_Renderer* render, int x, int y, int length, string color);
void set_color(SDL_Renderer* render, string color); // love of my life


//saper.cpp
void set_level(int level, int& width, int& height, int& num_bombs, int &cell, int& flags_left);
void setup(vector<vector<int> >& bombs, vector<vector<bool> >& revealed, vector<vector<bool> >& flags, const int& width, const int& height);




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
bool game(SDL_Window* window, SDL_Renderer* render, SDL_Event event, int level);
void draw_field(SDL_Window* window, SDL_Renderer* render, vector<vector<int> > bombs, vector<vector<bool> > revealed, vector<vector<bool> > flags, int cell);
void field_click(SDL_Event event, vector<vector<int> > &bombs, vector<vector<bool> > &revealed, vector<vector<bool> > &flags, int &cell, int& num_bombs, bool& first_click, bool& exit_b, bool& bang, int& flags_left, bool& if_win, int &x, int &y);


//tempt.cpp
bool win(vector<vector<int> >& bombs, vector<vector<bool> >& flags, vector<vector<bool> >& revealed);
void set_rect(SDL_Rect& bg, int h, int w, int x, int y);

//saper2.cpp
void clear_bombs(int width, int height, vector<vector<int> >& bombs);
void set_bombs(int& num_bombs, int width, int height, vector<vector<int> >& bombs);
void reveal(int x, int y, vector<vector<bool> >& revealed, vector<vector<int> >& bombs);
int count_bombs(int x, int y, vector<vector <int> >& bombs);
bool bounds(int x, int y, vector<vector <int> >& bombs);

//pics.cpp
void draw_num(SDL_Renderer* render, int num, int x, int y, int cell, bool l);
void draw_start(SDL_Renderer* render);
void draw_play(SDL_Renderer* render);
void draw_play2(SDL_Renderer* render);
SDL_Surface* draw_num_choose(int num, bool l);


//pics2.cpp
void draw_rules(SDL_Renderer* render);
void draw_winlose(SDL_Renderer* render, bool win);
void draw_game(SDL_Renderer* render);

//cutters.cpp
void sdl_end(SDL_Renderer* render, SDL_Window* window);
bool end_game(SDL_Event event);

//draw_game_end.cpp
bool draw_game_bang(SDL_Window* window, SDL_Renderer* render, SDL_Event event, vector<vector<int> > &bombs, int cell);
bool draw_game_win(SDL_Window* window, SDL_Renderer* render, SDL_Event event, vector<vector<int> > &bombs, vector<vector<bool> > &revealed, vector<vector<bool> > &flags, int cell);
void draw_game_win_1(SDL_Renderer* render, SDL_Window* window, vector<vector<int> > &bombs, vector<vector<bool> > &revealed, vector<vector<bool> > &flags, int cell, int x1, int y1);

//mouse_handle.cpp
void right_click(vector<vector<int> >& bombs, vector<vector<bool> >& revealed, vector<vector<bool> >& flags, int x, int y, int& flags_left, bool& exit_b, bool& if_win);
void left_click(vector<vector<int> >& bombs, vector<vector<bool> >& revealed, vector<vector<bool> >& flags, int x, int y, int& num_bombs, bool& exit_b, bool& bang, bool& first_click);


//draw_file.cpp
void draw_square_game(SDL_Window* window, SDL_Renderer* render, vector<vector<int> > bombs, vector<vector<bool> > revealed, vector<vector<bool> > flags, int x1, int y1, int cell);
void draw_square_game_1(SDL_Window* window, SDL_Renderer* render, vector<vector<int> > bombs, vector<vector<bool> > revealed, vector<vector<bool> > flags, int x1, int y1, int cell);
void draw_square_game_2(SDL_Window* window, SDL_Renderer* render, vector<vector<int> > bombs, vector<vector<bool> > revealed, vector<vector<bool> > flags, int x1, int y1, int cell);