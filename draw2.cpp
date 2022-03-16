#include "saper.h"

void draw_bomb(SDL_Renderer* render, int x, int y, int cell) {
    set_color(render, "black");
    draw_circle(render, x + cell / 2, y + cell / 2, cell / 2 - 3);
}

void draw_circle(SDL_Renderer* renderer, int x, int y, int radius)
{
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void draw_cross() {
    
}