#include "saper.h"

void verticalLine(SDL_Renderer* render, int x, int y, int length) {
    SDL_SetRenderDrawColor(render, 255, 0, 0, 0);
    bool side = false;
    if (length < 0) {
        side = true;
        length *= -1;
    }
    for (int i = 0; i < length; i++) {
        SDL_RenderDrawPoint(render, x, y);
        if (side)
            y += 1;
        else
            y -= 1;
    }
}

void rect(SDL_Renderer* render, int x, int y, int h, int w) {
    SDL_SetRenderDrawColor(render, 255, 0, 0, 0);
    for (int i = 0; i < w; i++) {
        verticalLine(render, x, y, h);
        x += 1;
    }
}