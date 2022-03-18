#include "saper.h"


void right_click(vector<vector<int> >& bombs, vector<vector<bool> >& revealed, vector<vector<bool> >& flags, int x, int y, int& flags_left, bool& exit_b, bool& if_win) {
    if (!revealed[y][x] && flags_left > 0) {
        flags[y][x] = !flags[y][x];
        if (flags[y][x] == 1) flags_left--;
        else flags_left++;
    }
    if (flags_left == 0 && win(bombs, flags, revealed)) {
        if_win = true;
        exit_b = false;
    }
    else if (flags_left == 0) {
        if (flags[y][x]) {
            flags[y][x] == false;
            flags_left++;
        }
    }
}


void left_click(vector<vector<int> >& bombs, vector<vector<bool> >& revealed, vector<vector<bool> >& flags, int x, int y, int& num_bombs, bool& exit_b, bool& bang, bool& first_click) {
    if (first_click) {
        first_click = false;
        do {
            clear_bombs(bombs.size(), bombs.size(), bombs);
            set_bombs(num_bombs, bombs.size(), bombs.size(), bombs);
        } while (count_bombs(x, y, bombs) != 0);

    }
    if (!flags[y][x]) {
        if (bombs[y][x] == 1) {
            exit_b = false;
            bang = true;
        }
        else {
            reveal(x, y, revealed, bombs, flags);
        }
    }
}
