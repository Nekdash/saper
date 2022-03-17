#include "saper.h"

void rules(SDL_Window* window, SDL_Renderer* render, SDL_Event event, int level) {
    int x = 0, y = 0;
    set_color(render, "g");
    SDL_RenderClear(render);
    rect(render, 540, 10, 50, 50, "lg"); // cross button
    draw_rules(render);
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
            sdl_end(render, window);
            break;
        }
    }
}


void play(SDL_Window* window, SDL_Renderer* render, SDL_Event event) {
    int x = 0, y = 0;
    int level = 0;
    set_color(render, "g");
    SDL_RenderClear(render);
    draw_play(render);
    SDL_RenderPresent(render);
    while (1) {
        SDL_PollEvent(&event);
        if (SDL_PollEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_GetMouseState(&x, &y);
            if (x > 150 && x < 600 - 150 && y > 150 && y < 250){ // easy button
                rules(window, render ,event, 0);
                break;} 
            if (x > 150 && x < 600 - 150 && y > 300 && y < 400){ // medium button
                rules(window, render, event, 1);
                break;} 
            if (x > 150 && x < 600 - 150 && y > 450 && y < 550){ // hard button
                rules(window, render, event, 2);
                break;} 
            if (x < 600 - 10 && x > 600 - 60 && y > 10 && y < 60) break;
        }
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            sdl_end(render, window);
            break;}}}

void start(SDL_Window* window, SDL_Renderer* render, SDL_Event event) {
    int window_width = 600, x = 0, y = 0;
    bool exit = true;
    while (exit) {
        set_color(render, "lg");
        SDL_RenderClear(render);
        SDL_SetRenderDrawColor(render, 200, 200, 200, 0);
        draw_start(render);
        SDL_RenderPresent(render);
        while (1) {
            SDL_PollEvent(&event);
            if (SDL_PollEvent(&event) && event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&x, &y);
                if (x < 600 - 10 && x > 600 - 60 && y > 10 && y < 60) { // cross button
                    exit = false;
                    break;}
                if (x < 600 - 150 && x > 150 && y > 400 && y < 475) { // play button
                    play(window, render, event);
                    break;}}
            if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
                exit = false;
                break;
    }}}
    sdl_end(render, window);
}


int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* render;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    //IMG_Init(IMG_INIT_PNG);
    SDL_CreateWindowAndRenderer(600, 700, 0, &window, &render);
    SDL_SetRenderDrawColor(render, 255, 255, 255, 0);
    SDL_PollEvent(&event);

    //one_bmp(render, window, 0, 0, 10);
    //SDL_RenderPresent(render);
    //SDL_Delay(3000);
    start(window, render, event);
    return 0;
}