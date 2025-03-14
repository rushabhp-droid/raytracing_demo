#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>

#define WIDTH 900
#define HEIGHT 800
#define COLOR_WHITE 0xffffffff
#define COLOR_BLACK 0x00000000



struct Circle
{
    double x_c;
    double y_c;
    double radius;
};

void cr_Circle(SDL_Surface* surface, struct Circle circle, Uint32 color)
{
    double radius_squared = pow(circle.radius,2);
    for(double x=circle.x_c-circle.radius;x<=circle.x_c+circle.radius;x++)
    {
        for(double y=circle.y_c-circle.radius;y<=circle.y_c+circle.radius;y++)
            {
                double distance_squared = pow(x-circle.x_c,2) + pow(y-circle.y_c,2);
                if(distance_squared < radius_squared)
                    {
                        SDL_Rect pixel = (SDL_Rect){x,y,1,1};
                        SDL_FillRect(surface, &pixel, color);
                    }
            }
    }
}


int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("raytracing demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0); // create window
    SDL_Surface* surface = SDL_GetWindowSurface(window); // surface creation
    struct Circle circle = {200, 200, 80};
    SDL_Rect erase_rect = {0,0,WIDTH,HEIGHT};

    int sim_running = 1; //true
    SDL_Event event;
    while(sim_running)
    {
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
                {
                    sim_running = 0;
                }
            if (event.type == SDL_MOUSEMOTION && event.motion.state != 0)
                {
                    circle.x_c = event.motion.x;
                    circle.y_c = event.motion.y;
                }
        }
        SDL_FillRect(surface, &erase_rect, COLOR_BLACK);
        cr_Circle(surface, circle, COLOR_WHITE); // create a circle on the window
        SDL_UpdateWindowSurface(window); // Update window to display circle
        SDL_Delay(10);
    }

}
