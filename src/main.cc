#include <cmath>
#include <array>
#include "SDL_Manager.hh"

extern const std::size_t SCREEN_WIDTH = 640;
constexpr std::size_t SCREEN_HEIGHT = 480;

void HandleInput() {/*Todo.*/}
void RayCast() {/*Todo, but it also needs DDA*/}
void DDA() {} //I put this inside raycast.

int main()
{
    SDL_Manager manager("Wolfenstein", SCREEN_WIDTH, SCREEN_HEIGHT);
    bool quit = true;
    
    while(quit == true)
    {
        HandleInput();
        RayCast();
    }
}