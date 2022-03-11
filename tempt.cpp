#include "saper.h"


void print_field(vector<vector<int> >& bombs) {
    for (int y = 0; y < bombs.size(); y++) {
        for (int x = 0; x < bombs[0].size(); x++) {
            cout << bombs[y][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_field_b(vector<vector<bool> >& bombs) {

    for (int y = 0; y < bombs.size(); y++) {
        for (int x = 0; x < bombs[0].size(); x++) {
            cout << bombs[y][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
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