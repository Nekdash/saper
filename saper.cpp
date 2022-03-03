#include <iostream>
#include <vector>
using namespace std;

//set the variables and fields
int width, height, num_bombs;
vector<vector<int> > bombs;
vector<vector<bool> > revealed;
vector<vector<bool> >flags;


//check for bounds
bool bounds(int x, int y) {
    return x < 0 || y < 0 || y >= bombs.size() || x >= bombs[0].size();
}


//count bombs around
int count_bombs(int x, int y) {
    int r = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!bounds(x + i, j + i)) r += bombs[i + x][j + y];
        }
        return r;
    }

//reveal fields
void reveal(int x, int y){
        if (bounds( x, y))return;
        if (revealed[y][x])return;
        revealed[x][y] = true;
        if (bombs[x][y] == 1) return;
        if (count_bombs( x, y) != 0)return;
        reveal(x - 1, y - 1);
        reveal(x - 1, y + 1);
        reveal(x + 1, y - 1);
        reveal(x + 1, y + 1);
        reveal(x - 1, y);
        reveal(x + 1, y);
        reveal(x, y - 1);
        reveal(x, y + 1);
    }

void handle_mouse() {
    
}


int main()
   {
        cin >> width;
        cin >> height;


   }

