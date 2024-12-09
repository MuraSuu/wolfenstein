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
        
        render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(render == nullptr)
        {
            std::fprintf(stderr, "Failed to create SDL_Renderer. Error: %s\n", SDL_GetError());
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

void SDL_Manager::Update()
{
    SDL_RenderClear(render);
    SDL_RenderPresent(render);
}

bool SDL_Manager::ProcessInput()
{
    for(SDL_Event event; SDL_PollEvent(&event); ) //TODO: Change this. After a while this will get weird to look at.
    {
        if(event.type == SDL_QUIT) //I'm wondering if there is a better way to do this.
        {
            return  true;;
        }
        if(event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE: return true; 
                case SDLK_x: break; 
                case SDLK_1: break; 
                case SDLK_2: break; 
                case SDLK_3: break; 
                case SDLK_q: break; 
                case SDLK_w: break; 
                case SDLK_e: break; 
                case SDLK_a: break; 
                case SDLK_s: break; 
                case SDLK_d: break; 
                case SDLK_z: break; 
                case SDLK_c: break; 
                case SDLK_4: break; 
                case SDLK_r: break; 
                case SDLK_f: break; 
                case SDLK_v: break; 
            }
        }
        if(event.type == SDL_KEYUP)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_x: break; 
                case SDLK_1: break; 
                case SDLK_2: break; 
                case SDLK_3: break; 
                case SDLK_q: break; 
                case SDLK_w: break; 
                case SDLK_e: break; 
                case SDLK_a: break; 
                case SDLK_s: break; 
                case SDLK_d: break; 
                case SDLK_z: break; 
                case SDLK_c: break; 
                case SDLK_4: break; 
                case SDLK_r: break; 
                case SDLK_f: break; 
                case SDLK_v: break; 
            }
        }
    }
    
    return false;
}
