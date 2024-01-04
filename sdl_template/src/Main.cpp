#include <SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {

    std::cout << "Hello sdl_template" << std::endl;

    SDL_Window* window = nullptr;

    SDL_Surface* windowSurface = nullptr;

    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL2 Could Not Initialize - SDL_Error:" << SDL_GetError() << std::endl;
        SDL_Quit();
        return 0;
    }


    const int WIDTH = 640;
    const int HEIGHT = 480;
    window = SDL_CreateWindow(
        "sdl_template",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if ( window == NULL )
    {
        std::cout << "Window could not be created - SDL_Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        windowSurface = SDL_GetWindowSurface( window );

        SDL_FillRect( windowSurface, NULL, SDL_MapRGB( windowSurface->format, 0x22, 0x9C, 0xBA ) );

        SDL_UpdateWindowSurface( window );

        // Keep Window Open
        SDL_Event e;
        bool quit = false;
        while ( quit == false )
        {
            while ( SDL_PollEvent( &e ) )
            {
                if ( e.type == SDL_QUIT )
                    quit = true;
            }
        }
    }

    SDL_DestroyWindow( window );

    SDL_Quit();

    return 0;
}
