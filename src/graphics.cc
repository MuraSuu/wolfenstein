#include "graphics.hh"
#include <cstdlib>
#include <utility>

extern const int SCREEN_WIDTH;

void RayCast(SDL_Renderer* render, const std::pair<double, double>& player, 
                const std::pair<double,double> camera_dir)
{
    std::pair<double, double> ray_dir;
    //Parametrizing the curve with the parameter
    for(int x = 0; x < SCREEN_WIDTH; ++x)
    {
        double param = (2.0*x/static_cast<double>(SCREEN_WIDTH)) - 1.0; 
        ray_dir.first = camera_dir.first*param + player.first;
        ray_dir.second = camera_dir.first*param + player.second;

        std::pair<int, int> map_pos {static_cast<int>(player.first), static_cast<int>(player.second)};

        //length of ray from one x or y-side to next x or y-side
        double delta_dist_x = (ray_dir.first == 0) ? 1e30 : std::abs(1/ray_dir.first);
        double delta_dist_y = (ray_dir.second == 0) ? 1e30 : std::abs(1/ray_dir.second);
        

        //what direction to step in x or y-direction (either +1 or -1)
        int step_x;
        int step_y;
        double side_dist_x;
        double side_dist_y;

        //calculate step and initial sideDist
        if(ray_dir.first < 0)
        {
            step_x = -1;
            side_dist_x = (player.first - map_pos.first) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = (map_pos.first + 1.0 - player.first) * delta_dist_x;
        }
        if (ray_dir.second < 0)
        {
            step_y = -1;
            side_dist_y = (player.second - map_pos.second) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_pos.second + 1.0 - player.second) * delta_dist_y;
        }

        int side; //was a NS or a EW wall hit?
        
        //Perform DDA
        bool hit = false;
        while(hit == false)
        {
            if(side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_pos.first += step_x;
                side = 0;
            }
            else {
                
                side_dist_y += delta_dist_y;
                map_pos.second += step_y;
                side = 1;
            }

            if(map[map_pos.first][map_pos.second] != 0) hit = true;
        }
        double perpWallDist;
        
    }


}