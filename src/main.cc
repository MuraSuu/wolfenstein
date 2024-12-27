#include "SDL_Manager.hh"
#include "graphics.hh"

int main()
{
    SDL_Manager manager("Wolfenstein", 480, 360);
    bool quit = false;

    std::pair<double, double> player_pos {22.0, 12.0};  //x and y start position
    std::pair<double, double> dir { -1.0, 0.0};//initial direction vector
    std::pair<double, double> plane { 0.0, 0.66}; //the 2d raycaster version of camera plane
    
    while(quit == false)
    {
        Uint32 start = SDL_GetPerformanceCounter();
        quit = manager.ProcessInput();

        SDL_SetRenderDrawColor(manager.render, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(manager.render);

        RayCast(manager.render, dir, plane, player_pos);

        Uint32 end = SDL_GetPerformanceCounter();
        float elapsed_ms = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

        SDL_Delay(std::floor(16.666f - elapsed_ms));
    }
}