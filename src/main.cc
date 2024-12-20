#include "SDL_Manager.hh"
#include "graphics.hh"

int main()
{
    SDL_Manager manager("Wolfenstein", 480, 360);
    bool quit = false;

    std::pair<double, double> player_pos {22.0, 12.0};  //x and y start position
    std::pair<double, double> dir { -1.0, 0.0};//initial direction vector
    std::pair<double, double> plane { 0.0, 0.66}; //the 2d raycaster version of camera plane

    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame
    
    while(quit == false)
    {
        quit = manager.ProcessInput();

        SDL_SetRenderDrawColor(manager.render, 0, 0, 0, 255);
        SDL_RenderClear(manager.render);

        RayCast(manager.render, dir, plane, player_pos);
    }
}