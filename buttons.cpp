#include "saper.h"

bool close(SDL_Event event) {
    SDL_PollEvent(&event);
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);
    if (SDL_PollEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN) {
        SDL_GetMouseState(&x, &y);
        if (x < 600 - 10 && x > 600 - 60 && y > 10 && y < 60) return true;
    }

    return false;
}

bool play_button(SDL_Event event) {
    SDL_PollEvent(&event);
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);
    if (SDL_PollEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN) {
        SDL_GetMouseState(&x, &y);
        if (x < 600 - 150 && x > 150 && y > 400 && y < 475) return true;
    }
    return false;
}