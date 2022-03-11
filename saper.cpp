#include <iostream>
#include <vector>
//#include <SDL.h>
#include "saper.h"
#include "SDL2/include/SDL.h"


bool bounds(int x, int y, vector<vector <int> >& bombs) {
    return x < 0 || y < 0 || y >= bombs.size() || x >= bombs[0].size();
}


int count_bombs(int x, int y, vector<vector <int> > &bombs) {
    int r = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (bombs[y][x] == 0) {
                if (!bounds(x + j, y + i, bombs)) r += bombs[y + i][x + j];
            }
            
        }
        
    }
    return r;
}

void clear_bombs(int width, int height, vector<vector<int> >& bombs) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            bombs[y][x] = 0;
        }
    }
}

void set_bombs(int& num_bombs, int width, int height, vector<vector<int> >& bombs) {//define bombs
    int i = 0, x, y;
    while (i < num_bombs) {
        x = rand() % width;
        y = rand() % height;
        if (bombs[y][x] != 1)
        {
            bombs[y][x] = 1;
            i++;
        }
    }
}

void reveal(int x, int y, vector<vector<bool> > &revealed, vector<vector<int> > &bombs) {
    if (bounds( x, y, bombs)) return;
    if (bombs[y][x] == 1) return;
    if (revealed[y][x]) return;
    cout << "revealing :  " << x << " " << y << endl;
    revealed[y][x] = true;
    
    if (count_bombs(x, y, bombs) == 0) {

        reveal(x - 1, y - 1, revealed, bombs);
        reveal(x - 1, y + 1, revealed, bombs);
        reveal(x + 1, y - 1, revealed, bombs);
        reveal(x + 1, y + 1, revealed, bombs);
        reveal(x - 1, y, revealed, bombs);
        reveal(x + 1, y, revealed, bombs);
        reveal(x, y - 1, revealed, bombs);
        reveal(x, y + 1, revealed, bombs);
    }
}
/*
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
*/

void set_level(int level, int& width, int& height, int& num_bombs, int& cell) { // define num of bombs and field size, set the vector size
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



