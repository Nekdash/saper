#include "saper.h"



void play(SDL_Window* window, SDL_Renderer* render, SDL_Event event) {
	cout << "play scene started" << endl;
    SDL_RenderClear(render);
    rect(render, 150, 300, 100, 300, "lg");
    rect(render, 100, 300, 100, 50, "r");
    rect(render, 450, 300, 100, 50, "r");
    SDL_RenderPresent(render);
    while (1) {
        if (close(event))start(window, render ,event);
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            SDL_DestroyRenderer(render);
            SDL_DestroyWindow(window);
            SDL_Quit();
        }
    }
}




void start(SDL_Window* window, SDL_Renderer* render, SDL_Event event) {
    int window_width = 600;
    //int window_width = 600;
    SDL_PollEvent(&event);
    SDL_RenderClear(render);

    SDL_SetRenderDrawColor(render, 200, 200, 200, 0);
    rect(render, window_width - 60, 10, 50, 50);

    rect(render, 150, 400, 75, window_width - 300, "g"); // play button
   

    SDL_RenderPresent(render);

    string scene = "null";

    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
        if (close(event)) {
            scene == "close";
            break;
        }
        if (play_button(event)) {
            scene = "play";
            break;
        }
        
    }
    if (scene == "play") play(window, render, event);
    
    if (scene == "close") {
        SDL_DestroyRenderer(render);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

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