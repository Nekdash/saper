#include "saper.h"

void set_color(SDL_Renderer* render, string color) {
    if (color == "grey" || color == "g")SDL_SetRenderDrawColor(render, 170, 170, 170, 0);
    if (color == "light grey" || color == "lg") SDL_SetRenderDrawColor(render, 210, 210, 210, 0);
    if (color == "dark grey" || color == "dg")SDL_SetRenderDrawColor(render, 100, 100, 100, 0);
    if (color == "black" || color == "b") SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
    if (color == "white" || color == "w") SDL_SetRenderDrawColor(render, 255, 255, 255, 0);
    if (color == "red" || color == "r") SDL_SetRenderDrawColor(render, 210, 0, 0, 0);
    if (color == "blue" || color == "bl") SDL_SetRenderDrawColor(render, 0, 0, 240, 0);
    if (color == "green" || color == "gn") SDL_SetRenderDrawColor(render, 0, 240, 0, 0);
    if (color == "dark blue" || color == "db") SDL_SetRenderDrawColor(render, 0, 0, 150, 0);
    if (color == "dark red" || color == "dr") SDL_SetRenderDrawColor(render, 150, 0, 0, 0);
    if (color == "dark dark grey" || color == "ddg") SDL_SetRenderDrawColor(render, 40, 40, 40, 0);
}

void verticalLine(SDL_Renderer* render, int x, int y, int length, string color) {
    set_color(render, color);
    verticalLine(render, x, y, length);
}

void rect(SDL_Renderer* render, int x, int y, int h, int w, string color) {
    set_color(render, color);
    rect(render, x, y, h, w);
}

void verticalLine(SDL_Renderer* render, int x, int y, int length) {
    //set_color(render, color);
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
    //set_color(render, color);
    h *= (-1);
    //SDL_SetRenderDrawColor(render, 255, 0, 0, 0);
    for (int i = 0; i < w; i++) {
        verticalLine(render, x, y, h);
        x += 1;
    }
}