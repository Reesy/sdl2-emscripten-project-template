#include <stdio.h>
#include <stdlib.h>

#if __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#define SCREEN_WIDTH  200
#define SCREEN_HEIGHT 200

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

int posX=0;
int posY=0;
int sizeW=20;
int sizeH=20;

static int quit = 0;

void render()
{

    SDL_Rect r_scr;
    r_scr.x = posX;
    r_scr.y = posY;
    r_scr.w = sizeW;
    r_scr.h = sizeH;
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0x00, 0x00);
    SDL_RenderDrawRect(renderer, &r_scr);
    SDL_RenderPresent(renderer);
}

#if __EMSCRIPTEN__
void main_tick() {
#else
int main_tick() {
#endif

    SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
            {
                quit = 1;
                break;
            }
            case SDL_KEYDOWN:
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                {
                    if (posY>=20)
                    {
                        posY-=20;
                    }
                    break;
                }
                case SDLK_DOWN:
                {
                    if (posY+sizeH<SCREEN_HEIGHT)
                    {
                        posY += 20;
                    }
                    break;
                }
                case SDLK_LEFT:
                {
                    if (posX>=20)
                    {
                        posX-=20;
                    }
                    break;
                }
                case SDLK_RIGHT:
                {
                    if (posX+sizeW<SCREEN_WIDTH)
                    {
                        posX+=20;
                    }
                    break;
                }
                }
                break;
            }
            }

        }


    render();
    SDL_UpdateWindowSurface(window);

#if !__EMSCRIPTEN__
    return 0;
#endif
}

void main_loop()
{

#if __EMSCRIPTEN__
    emscripten_set_main_loop(main_tick, -1, 1);
#else
    while (0 == quit)
    {
        main_tick();
    }
#endif
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "WEBASM",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

    main_loop();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
