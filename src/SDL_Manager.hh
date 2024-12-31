#ifndef SDL_MANAGER_HH
#define SDL_MANAGER_HH

#include <cstdio>
#include <cstdlib>

#include <SDL.h>
#include <SDL_video.h>
#include <SDL_render.h>

//The purpose of this "Manager" is to just call the
//SDL_Quit at the end of the program.
struct SDL_Manager
{
    SDL_Window* window;
    SDL_Renderer* render;
    
    SDL_Manager(const char* name, int width, int height);
    ~SDL_Manager();
};

#endif

