#include <iostream>
#include <vector>
//#include <SDL.h>
#include "saper.h"
#include "SDL2/include/SDL.h"


void set_level(int level, int& width, int& height, int& num_bombs, int& cell, int& flags_left) { // define num of bombs and field size, set the vector size
    if (level == 0) {
        num_bombs = 10;
        width = 9;
        height = 9;
        cell = 66;
    }
    else if (level == 1) {
        num_bombs = 40;
        width = 16;
        height = 16;
        cell = 37;
    }
    else if (level == 2) {
        num_bombs = 99;
        width = 22;
        height = 22;
        cell = 27;
    }
    flags_left = num_bombs;
}

void setup(vector<vector<int> >& bombs, vector<vector<bool> >& revealed, vector<vector<bool> >& flags, const int& width, const int& height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            bombs[i][j] = 0;
            flags[i][j] = false;
            revealed[i][j] = false;
        }
    }
}



