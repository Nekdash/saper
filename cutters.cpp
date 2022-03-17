#include "saper.h"

void sdl_end(SDL_Renderer* render, SDL_Window* window) {
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


bool end_game(SDL_Event event) {
    int x, y;
    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN) {

            SDL_GetMouseState(&x, &y);
            if (event.button.button == SDL_BUTTON_LEFT) {
                if (x < 600 - 10 && x > 600 - 60 && y > 10 && y < 60) { // cross button
                    return false;
                }
                if (x < 530 && x > 480 && y > 10 && y < 60) { // restart button
                    return true;
                }
            }
        }
    }
}