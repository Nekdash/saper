#include "saper.h"


bool bounds(int x, int y, vector<vector <int> >& bombs) {
    return x < 0 || y < 0 || y >= bombs.size() || x >= bombs[0].size();
}


int count_bombs(int x, int y, vector<vector <int> >& bombs) {
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

void reveal(int x, int y, vector<vector<bool> >& revealed, vector<vector<int> >& bombs, vector<vector<bool> >& flags) {
    if (bounds(x, y, bombs)) return;
    if (bombs[y][x] == 1) return;
    if (flags[y][x]) return;
    if (revealed[y][x]) return;
    //cout << "revealing :  " << x << " " << y << endl;
    revealed[y][x] = true;

    if (count_bombs(x, y, bombs) == 0) {
        reveal(x - 1, y - 1, revealed, bombs, flags);
        reveal(x - 1, y + 1, revealed, bombs, flags);
        reveal(x + 1, y - 1, revealed, bombs, flags);
        reveal(x + 1, y + 1, revealed, bombs, flags);
        reveal(x - 1, y, revealed, bombs, flags);
        reveal(x + 1, y, revealed, bombs, flags);
        reveal(x, y - 1, revealed, bombs, flags);
        reveal(x, y + 1, revealed, bombs, flags);
    }
}
