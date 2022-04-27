#include <stdio.h>
#include <SDL.h>

int main(int argc,char *agrv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *ventana;
    SDL_Surface *superficie;

    ventana =SDL_CreateWindow("Juego ajedrez",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,NULL);
    superficie = SDL_GetWindowSurface(ventana);

    SDL_Delay(3000);
    SDL_DestroyWindow(ventana);
    SDL_Quit();
    return 0;
}
