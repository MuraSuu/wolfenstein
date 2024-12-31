#include "SDL_Manager.hh"
#include "graphics.hh"

using Point = std::pair<double, double>;

//One thing to note is how the rotation part is exactly the result of a rotation matrix.
void UpdatePlayer(Point& player_pos, Point& dir, Point& plane, const SDL_KeyboardEvent* keyevent, double move_speed, double rot_speed)
{
    if (keyevent->keysym.sym == SDLK_UP) //Move forward
    {
      if(map[int(player_pos.first + dir.first * move_speed)][int(player_pos.second)] == false) player_pos.first += dir.first * move_speed;
      if(map[int(player_pos.first)][int(player_pos.second + dir.second * move_speed)] == false) player_pos.second += dir.second * move_speed;
    }
    
    if (keyevent->keysym.sym == SDLK_DOWN) //Move backwards
    {
      if(map[int(player_pos.first - dir.second * move_speed)][int(player_pos.second)] == false) player_pos.first -= dir.first * move_speed;
      if(map[int(player_pos.first)][int(player_pos.second - dir.second * move_speed)] == false) player_pos.second -= dir.second * move_speed;
    }
    
    if (keyevent->keysym.sym == SDLK_RIGHT) //Rotate to the right
    {
      //Both camera direction and camera plane must be rotated
      double old_dir_x = dir.first; //Auxiliary variable to implement the rotation matrix thing.
      dir.first = dir.first * std::cos(-rot_speed) - dir.second * std::sin(-rot_speed);
      dir.second = old_dir_x * std::sin(-rot_speed) + dir.second * std::cos(-rot_speed);
      double old_plane_x = plane.first;//Auxiliary variable to implement the rotation matrix thing.
      plane.first = plane.first * std::cos(-rot_speed) - plane.second * std::sin(-rot_speed);
      plane.second = old_plane_x * std::sin(-rot_speed) + plane.second * std::cos(-rot_speed);
    }
    
    if (keyevent->keysym.sym == SDLK_LEFT) //Rotate to the left.
    {
      //Both camera direction and camera plane must be rotated
      double old_dir_x = dir.first;//Auxiliary variable to implement the rotation matrix thing.
      dir.first = dir.first * std::cos(rot_speed) - dir.second * std::sin(rot_speed);
      dir.second = old_dir_x * std::sin(rot_speed) + dir.second * std::cos(rot_speed);
      double old_plane_x = plane.first;//Auxiliary variable to implement the rotation matrix thing.
      plane.first = plane.first * std::cos(rot_speed) - plane.second * std::sin(rot_speed);
      plane.second = old_plane_x * std::sin(rot_speed) + plane.second * std::cos(rot_speed);
    }
}

int main()
{
    SDL_Manager manager("Wolfenstein", 480, 360);
    bool quit = false;
    double move_speed = 0.0f;
    double rot_speed = 0.0f; 

    Point player_pos {22.0, 12.0};  //x and y start position
    Point dir { -1.0, 0.0};//initial direction Point
    Point plane { 0.0, 0.66}; //the 2d raycaster version of camera plane
    
    while(quit == false)
    {
        Uint32 start = SDL_GetPerformanceCounter();
        
        SDL_Event event;
        //Reading the documentation I learned that it must be a while loop
        //so it can read all events in the queue.
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                quit = true;
            if(event.type == SDL_KEYDOWN)
                UpdatePlayer(player_pos, dir, plane, &event.key, move_speed, rot_speed);
        }

        SDL_SetRenderDrawColor(manager.render, 0, 0, 0, 255);
        SDL_RenderClear(manager.render);

        RayCast(manager.render, dir, plane, player_pos);

        SDL_RenderPresent(manager.render);

        Uint32 end = SDL_GetPerformanceCounter();
        float elapsed_ms = (end - start) / static_cast<float>(SDL_GetPerformanceFrequency()) * 1000.0f;

        move_speed = elapsed_ms * 0.1; //squares/second
        rot_speed = elapsed_ms * 0.1; //radians/second

        SDL_Delay(std::floor(16.666f - elapsed_ms));
    }
}