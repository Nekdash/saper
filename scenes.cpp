#include "saper.h"

void rules(SDL_Window* window, SDL_Renderer* render, SDL_Event event, int level) {
    int x = 0, y = 0;
    set_color(render, "g");
    SDL_RenderClear(render);
    rect(render, 150, 600, 75, 300, "lg");
    rect(render, 540, 10, 50, 50, "lg");
    SDL_RenderPresent(render);
    while (1) {
        SDL_PollEvent(&event);
        if (SDL_PollEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_GetMouseState(&x, &y);
            if (x > 150 && x < 450 && y > 600 && y < 675) {
                bool b = true;
                while (b) b = game(window, render, event, level);
                break;
            }
            if (x < 600 - 10 && x > 600 - 60 && y > 10 && y < 60) break;// cross button - break to play scene -> break to start scene
        }
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            SDL_DestroyRenderer(render);
            SDL_DestroyWindow(window);
            SDL_Quit();
            cout << "rules scene destroyed WINDWOW CLOSURE" << endl;
            break;
        }
    }
}


void play(SDL_Window* window, SDL_Renderer* render, SDL_Event event) {
    int x = 0, y = 0;
    int level = 0;
    set_color(render, "g");
    SDL_RenderClear(render);
    rect(render, 540, 10, 50, 50, "lg"); // back to start button
    rect(render, 150, 150, 100, 300, "lg"); // easy mode
    rect(render, 150, 300, 100, 300, "lg"); // medium mode
    rect(render, 150, 450, 100, 300, "lg"); // hard mode
    SDL_RenderPresent(render);
    while (1) {
        SDL_PollEvent(&event);
        if (SDL_PollEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_GetMouseState(&x, &y);
            if (x > 150 && x < 600 - 150 && y > 150 && y < 250){ // easy button
                level = 0;
                rules(window, render ,event, 0);
                break;
            } 
            if (x > 150 && x < 600 - 150 && y > 300 && y < 400){ // medium button
                level = 1;
                rules(window, render, event, 1);
                break;
            } 
            if (x > 150 && x < 600 - 150 && y > 450 && y < 550){ // hard button
                level = 2;
                rules(window, render, event, 2);
                break;
            } 
            if (x < 600 - 10 && x > 600 - 60 && y > 10 && y < 60) break;
        }
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            SDL_DestroyRenderer(render);
            SDL_DestroyWindow(window);
            SDL_Quit();
            break;
        }
    }
}




void start(SDL_Window* window, SDL_Renderer* render, SDL_Event event) {
    int window_width = 600, x = 0, y = 0;
    bool exit = true;
    while (exit) {
        set_color(render, "lg");
        SDL_PollEvent(&event);
        SDL_RenderClear(render);
        SDL_SetRenderDrawColor(render, 200, 200, 200, 0);
        rect(render, window_width - 60, 10, 50, 50, "g"); // cross button
        rect(render, 150, 400, 75, window_width - 300, "g"); // play button
        SDL_RenderPresent(render);
        while (1) {
            SDL_PollEvent(&event);
            if (SDL_PollEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&x, &y);
                if (x < 600 - 10 && x > 600 - 60 && y > 10 && y < 60) { // cross button
                    exit = false;
                    break;
                }
                if (x < 600 - 150 && x > 150 && y > 400 && y < 475) { // play button
                    play(window, render, event);
                    break;
                }
            }
            if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
                exit = false;
                break;
            }
        }
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* render;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(600, 700, 0, &window, &render);
    SDL_SetRenderDrawColor(render, 255, 255, 255, 0);
    SDL_PollEvent(&event);

    start(window, render, event);
    return 0;
}