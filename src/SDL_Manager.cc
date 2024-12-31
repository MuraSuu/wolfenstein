#include "SDL_Manager.hh"

SDL_Manager::SDL_Manager(const char* name, int width, int height) : window(nullptr), render(nullptr)
{
    if(SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if(window == nullptr)
        {
            std::fprintf(stderr, "Failed to create SDL_Window. Error: %s\n", SDL_GetError());
        }
        
        render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
        if(render == nullptr)
        {
            std::fprintf(stderr, "Failed to create SDL_Renderer. Error: %s\n", SDL_GetError());
            std::exit(-1);
        }
        
    }else{
        std::fprintf(stderr, "Failed to initialize SDL. Error: %s\n", SDL_GetError());
    }
}

SDL_Manager::~SDL_Manager()
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    render = nullptr;
    window = nullptr;
    
    std::fprintf(stderr, "Done\n");
    
    SDL_Quit();
}

