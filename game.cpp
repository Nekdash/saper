#include "saper.h"

void print_field(vector<vector<int> > &bombs) {
    for (int y = 0; y < bombs.size(); y++) {
        for (int x = 0; x < bombs[0].size(); x++) {
            cout << bombs[y][x] << " " ;
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



void game(SDL_Window* window, SDL_Renderer* render, SDL_Event event, int level) {
    cout << "game started" << endl;
	int width, height, num_bombs, flags_left, cell;
    set_level(level, width, height, num_bombs, cell);
	vector<vector<int> > bombs(height, vector<int> (width));
	vector<vector<bool> > revealed(height, vector<bool>(width)), flags(height, vector<bool>(width));
    setup(bombs, revealed, flags, width, height);

    flags_left = num_bombs;
    
    SDL_RenderClear(render);
    set_color(render, "lg");
    

    rect(render, 0, 0, 100, 600, "g");
    rect(render, 540, 10, 50, 50, "lg"); // cross 
    rect(render, 10, 10, 50, 75, "lg"); // flags - no idea how to do it - add function redraw_flags()???
    bool exit_b = true;
    bool first_click = true;
    int x = 0, y = 0;
    int near;

    
    
    //after each click

    while (exit_b) {
        for (int y1 = 0; y1 < height; y1++) {
            for (int x1 = 0; x1 < width; x1++) {
                near = count_bombs(x1, y1, bombs);
                set_color(render, "g");
                
               
                if ((x1 + y1) % 2 == 0) {
                    set_color(render, "lg");
                    if (flags[y1][x1]) {
                        set_color(render, "r");
                        
                    }
                    else if (revealed[y1][x1]) {
                        set_color(render, "db");
                        
                    }
                }
                else {
                    set_color(render, "g");
                    if (flags[y1][x1]) {
                        set_color(render, "dr");
                    }
                    else if (revealed[y1][x1]) {
                        set_color(render, "dr");
                    }
                }
                rect(render, x1 * cell, 100 + y1 * cell, cell, cell);
                //cout << "near = " << near << endl;
                if (near != 0 && revealed[y][x]) {

                    if (near == 1)set_color(render, "bl");
                    if (near == 2) set_color(render, "gn");
                    if (near == 3) set_color(render, "r");
                    if (near == 4) set_color(render, "db");
                    if (near == 5) set_color(render, "dr");
                    if (near == 6) set_color(render, "t");
                    if (near == 7) set_color(render, "b");
                    if (near == 8) set_color(render, "b");

                    rect(render, x1 * cell, 100 +y1 * cell, cell / 2, cell / 2);
                }
            }
        }
        SDL_RenderPresent(render);
        
        while (1) {
            if (SDL_PollEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN) {
                
                SDL_GetMouseState(&x, &y);
                if (x < 600 - 10 && x > 600 - 60 && y > 10 && y < 60) {
                    exit_b = false;
                    break;
                }
                if (y > 100) {
                    cout << "smth detected in the field" << endl;
                    x = x / cell;
                    y = (y - 100) / cell;
                    cout << "x: " << x << "  y: " << y << "  value:  " << bombs[y][x] << endl;
                    
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        cout << "left button click!!" << endl;
                        if (first_click) {
                            first_click = false;
                            do {
                                clear_bombs(width, height, bombs);
                                set_bombs(num_bombs, width, height, bombs);
                            } while (count_bombs(x, y, bombs) == 1);
                            cout << "field set up complete !!" << endl;
                        }
                        if (bombs[y][x] == 1) {
                            cout << "Bang!" << endl;;
                            //exit_b = false;
                            break;
                        }
                        else {
                            reveal(x, y, revealed, bombs);
                            cout << "reveal complete" << endl;
                            break;
                        }
                    }
                    else {
                        flags[y][x] = !flags[y][x];
                        break;
                    }
                }
            }
        }
        print_field(bombs);
        print_field_b(revealed);
    }
    cout << "bomb worked, now what?" << endl;
}