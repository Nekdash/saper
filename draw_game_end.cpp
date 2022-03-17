#include "saper.h"


bool draw_game_bang(SDL_Window* window, SDL_Renderer* render, SDL_Event event, vector<vector<int> > &bombs, int cell) {
    draw_winlose(render, false);
    for (int y1 = 0; y1 < bombs[0].size(); y1++) {
        for (int x1 = 0; x1 < bombs[0].size(); x1++) {
            if (bombs[y1][x1] == 1) {
                draw_num(render, -2, x1 * cell, 100 + y1 * cell, cell, true);
            }
        }
    }
    SDL_RenderPresent(render);
    return end_game(event);
}

bool draw_game_win(SDL_Window* window, SDL_Renderer* render, SDL_Event event, vector<vector<int> > &bombs, vector<vector<bool> > &revealed, vector<vector<bool> > &flags, int cell) {
    int near;
    draw_winlose(render, true);
    for (int y1 = 0; y1 < bombs.size(); y1++) {
        for (int x1 = 0; x1 < bombs.size(); x1++) {
            near = count_bombs(x1, y1, bombs);
            set_color(render, "g");
            draw_game_win_1(render, window, bombs, revealed, flags, cell, x1, y1);
        }
    }
    SDL_RenderPresent(render);
    return end_game(event);
}

void draw_game_win_1(SDL_Renderer* render, SDL_Window* window, vector<vector<int> > &bombs, vector<vector<bool> > &revealed, vector<vector<bool> > &flags, int cell, int x1, int y1) {
    bool l;
    int near = count_bombs(x1, y1, bombs);
    if ((x1 + y1) % 2 == 0) {
        l = false;
        set_color(render, "g");
        rect(render, x1 * cell, 100 + y1 * cell, cell, cell);
        if (flags[y1][x1]) draw_num(render, -1, x1 * cell, 100 + y1 * cell, cell, l);
        else {
            revealed[y1][x1] = true;
            rect(render, x1 * cell, 100 + y1 * cell, cell, cell, "ddg");
        }
    }
    else {
        l = true;
        set_color(render, "lg");
        rect(render, x1 * cell, 100 + y1 * cell, cell, cell);
        if (flags[y1][x1]) draw_num(render, -1, x1 * cell, 100 + y1 * cell, cell, l);
        else {
            revealed[y1][x1] = true;
            rect(render, x1 * cell, 100 + y1 * cell, cell, cell, "dg");
        }
    }
    if (near > 0 && revealed[y1][x1]) draw_num(render, near, x1 * cell, 100 + y1 * cell, cell, l);
}