#include "saper.h"


void draw_square_game(SDL_Window* window, SDL_Renderer* render, vector<vector<int> > bombs, vector<vector<bool> > revealed, vector<vector<bool> > flags, int x1, int y1, int cell) {
    int near = count_bombs(x1, y1, bombs);
    bool l;
    set_color(render, "g");
    if ((x1 + y1) % 2 == 0) {
        l = false;
        draw_square_game_2(window, render, bombs, revealed, flags, x1, y1, cell);
    }
    else {
        l = true;
        draw_square_game_1(window, render, bombs, revealed, flags, x1, y1, cell);
    }
    if (near > 0 && revealed[y1][x1]) {
        draw_num(render, near, x1 * cell, 100 + y1 * cell, cell, l);
    }
}

void draw_square_game_1(SDL_Window* window, SDL_Renderer* render, vector<vector<int> > bombs, vector<vector<bool> > revealed, vector<vector<bool> > flags, int x1, int y1, int cell) {
    bool l = true;
    set_color(render, "lg");
    rect(render, x1 * cell, 100 + y1 * cell, cell, cell);
    if (flags[y1][x1]) {
        draw_num(render, -1, x1 * cell, 100 + y1 * cell, cell, l);
    }
    else if (revealed[y1][x1]) {
        set_color(render, "dg");
        rect(render, x1 * cell, 100 + y1 * cell, cell, cell);
    }
}

void draw_square_game_2(SDL_Window* window, SDL_Renderer* render, vector<vector<int> > bombs, vector<vector<bool> > revealed, vector<vector<bool> > flags, int x1, int y1, int cell) {
    bool l = false;
    set_color(render, "g");
    rect(render, x1 * cell, 100 + y1 * cell, cell, cell);
    if (flags[y1][x1]) {
        draw_num(render, -1, x1 * cell, 100 + y1 * cell, cell, l);
    }
    else if (revealed[y1][x1]) {
        set_color(render, "ddg");
        rect(render, x1 * cell, 100 + y1 * cell, cell, cell);
    }
}