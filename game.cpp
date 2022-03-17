#include "saper.h"

bool game(SDL_Window* window, SDL_Renderer* render, SDL_Event event, int level) {
	int width, height, num_bombs, flags_left, cell, near, x= 0, y = 0;
    set_level(level, width, height, num_bombs, cell, flags_left);
	vector<vector<int> > bombs(height, vector<int> (width));
	vector<vector<bool> > revealed(height, vector<bool>(width)), flags(height, vector<bool>(width));
    setup(bombs, revealed, flags, width, height);
    SDL_RenderClear(render);
    set_color(render, "lg");
    draw_game(render);
    bool exit_b = true, first_click = true, bang = false, if_win = false, l;
    while (exit_b) {
        draw_field(window, render, bombs, revealed, flags, cell);
        SDL_RenderPresent(render);
        while (1) {
            if (SDL_PollEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&x, &y);
                if (x < 600 - 10 && x > 600 - 60 && y > 10 && y < 60) return false;
                if (x < 530 && x > 480 && y > 10 && y < 60) return true;
                if (y > 100) { field_click(event, bombs, revealed, flags, cell, num_bombs, first_click, exit_b, bang, flags_left, if_win, x, y); break; }
    }}}
    if (bang) return draw_game_bang(window, render, event, bombs, cell);
    if (if_win) return draw_game_win(window, render, event, bombs, revealed, flags, cell);
    return false;
}

void draw_field(SDL_Window* window, SDL_Renderer* render, vector<vector<int> > bombs, vector<vector<bool> > revealed, vector<vector<bool> > flags,  int cell) {
    for (int y1 = 0; y1 < bombs.size(); y1++) {
        for (int x1 = 0; x1 < bombs.size(); x1++) {
            draw_square_game(window, render, bombs, revealed, flags, x1, y1, cell);
        }
    }
}

void field_click(SDL_Event event, vector<vector<int> > &bombs, vector<vector<bool> > &revealed, vector<vector<bool> > &flags, int &cell, int &num_bombs, bool&first_click, bool&exit_b, bool& bang, int& flags_left, bool &if_win, int &x, int &y) {
    x = x / cell;
        y = (y - 100) / cell;
        if (event.button.button == SDL_BUTTON_LEFT) left_click(bombs, revealed, flags, x, y, num_bombs, exit_b, bang, first_click);
        else right_click(bombs, revealed, flags, x, y, flags_left, exit_b, if_win);
}