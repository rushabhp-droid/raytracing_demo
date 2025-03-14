#include <stdio.h>
#include <SDL2/SDL.h>

#define WIDTH 900
#define HEIGHT 800
#define COLOR_WHITE 0xffffffff

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("raytracing demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0); // icreate window
    SDL_Surface* surface = SDL_GetWindowSurface(window); //
    SDL_Rect rect = (SDL_Rect) {200,200,200,200}; // create a rectangle shape in the window
    SDL_FillRect(surface, &rect, COLOR_WHITE); // :)
    SDL_UpdateWindowSurface(window); // Update window to display rectangle
    SDL_Delay(6000);
}
