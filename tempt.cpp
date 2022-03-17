#include "saper.h"


void set_rect(SDL_Rect& bg, int h, int w, int x, int y) {
    bg.h = h;
    bg.w = w;
    bg.x = x;
    bg.y = y;
}

bool win(vector<vector<int> >& bombs, vector<vector<bool> >& flags, vector<vector<bool> >& revealed) {
    bool r = true;
    for (int y = 0; y < bombs.size(); y++) {
        for (int x = 0; x < bombs[0].size(); x++) {
            
            if (bombs[y][x] == 1 ) {
                if (flags[y][x]) r = true;
                else return false;
            }
            if (flags[y][x]) {
                if (bombs[y][x] == 1) r = true;
                else return false;
            }
        }
    }
    return true;
}