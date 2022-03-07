﻿#include <iostream>
#include <vector>
//#include <SDL.h>
#include "saper.h"
#include "SDL2/include/SDL.h"

//set the variables and fields
int width, height, num_bombs, flags_left;
vector<vector<int> > bombs;
vector<vector<bool> > revealed;
vector<vector<bool> > flags;
//vector<vector<int> > nums;
int cell;
//extern int window_width;

//check for bounds
bool bounds(int x, int y) {
    return x < 0 || y < 0 || y >= bombs.size() || x >= bombs[0].size();
}


int count_bombs(int x, int y) {
    int r = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!bounds(x + i, j + i)) r += bombs[i + x][j + y];
        }
        return r;
    }
}

void draw_num(int x ,int y) {
    // calculate cell coordinates;
    // draw png of number there
}

void reveal(int x, int y) {
    if (bounds( x, y)) return;
    if (revealed[y][x]) return;
    revealed[x][y] = true;
    if (bombs[x][y] == 1) return;
    if (count_bombs(x, y) != 0) {
        //draw_num(x, y);
        return;
    } 
        reveal(x - 1, y - 1);
        reveal(x - 1, y + 1);
        reveal(x + 1, y - 1);
        reveal(x + 1, y + 1);
        reveal(x - 1, y);
        reveal(x + 1, y);
        reveal(x, y - 1);
        reveal(x, y + 1);
}

void set_flag(int x, int y) {
    if (!flags[y][x]) {
        flags[y][x] = true;
        flags_left--;
    }
    else {
        flags[y][x] = 0;
        flags_left++;
    }
}


void setup(){
    bombs[height][width];
    flags[height][width];
    revealed[height][width];
    flags_left = num_bombs;
    for(int i =0; i< height; i++){
        for(int j = 0; j < width; j++){
            bombs[i][j] = 0;
            flags[i][j] = false;
            revealed[i][j] = false;
        }
    }
}

void set_bombs(){//define bombs
    int i =0, x, y;
    while(i < num_bombs){
        x = rand()% width;
        y = rand() % height;
        if(bombs[y][x] != 1)
        {bombs[x][y] = 1;
        i++;}
    }
}

void set_level(int level){ // define num of bombs and field size
    if(level == 0){
        num_bombs = 10;
        width = 9;
        height = 9;
    }else if(level == 1){
        num_bombs = 40;
        width = 16;
        height = 16;
    }else if(level == 2){
        num_bombs = 99;
        width = 22;
        height = 22;

    }
}









void settings() {
    vector<int> levels;
}


