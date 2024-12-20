#include "graphics.hh"

void RayCast(SDL_Renderer* render, const std::pair<double, double>& dir, 
                const std::pair<double,double> camera_plane,
                const std::pair<double, double>& player_pos)
{
    std::pair<double, double> ray_dir;
    //Parametrizing the curve with the parameter
    for(int x = 0; x < SCREEN_WIDTH; ++x)
    {
        double param = (2.0*x/static_cast<double>(SCREEN_WIDTH)) - 1.0; 
        ray_dir.first = camera_plane.first*param + dir.first;
        ray_dir.second = camera_plane.first*param + dir.second;

        std::pair<int, int> map_pos {static_cast<int>(player_pos.first), static_cast<int>(player_pos.second)};

        //length of ray from one x or y-side to next x or y-side
        //There is no risk of something bad happening here. If the denominator is 0, then
        //C++ will just set the entire thing as 0.0. This is the case for floating point, not
        //sure about integers.
        double delta_dist_x = std::fabs(1/ray_dir.first);
        double delta_dist_y = std::fabs(1/ray_dir.second);
        

        //what direction to step in x or y-direction (either +1 or -1)
        int step_x = 0;
        int step_y = 0;
        double side_dist_x = 0.0;
        double side_dist_y = 0.0;

        //It could be done differently, but it would involve using division.
        //Division is something that I know is bad for this sort of thing. 
        if(ray_dir.first < 0)
        {
            step_x = -1;
            side_dist_x = (player_pos.first - map_pos.first) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = (map_pos.first + 1.0 - player_pos.first) * delta_dist_x;
        }
        if (ray_dir.second < 0)
        {
            step_y = -1;
            side_dist_y = (player_pos.second - map_pos.second) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_pos.second + 1.0 - player_pos.second) * delta_dist_y;
        }

        //This variable is used to optimize the calculation of the
        //perpendicular wall distance. If we hit a wall on our side, West or East
        //then we do one thing. Otherwise we will do other.
        bool side = false;
        
        //Perform DDA
        bool hit = false;
        while(hit == false)
        {
            if(side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_pos.first += step_x;
                side = false;
            }
            else {
                side_dist_y += delta_dist_y;
                map_pos.second += step_y;
                side = true;
            }

            if(map[map_pos.first][map_pos.second] != 0) hit = true;
        }

        //TODO: Improve this.
        double perp_wall_dist;
        if(side == false) perp_wall_dist = side_dist_x - delta_dist_x;
        else perp_wall_dist = side_dist_y - delta_dist_y;



        //SDL works with integers.
        int line_height = static_cast<int>(SCREEN_HEIGHT / perp_wall_dist);

        // Calculate lowest and highest pixel to fill in current stripe
        int draw_start = std::max(0, -line_height / 2 + SCREEN_HEIGHT / 2);
        int draw_end = std::min(SCREEN_HEIGHT - 1, line_height / 2 + SCREEN_HEIGHT / 2);

        SDL_Color color;
        switch(map[map_pos.first][map_pos.second])
        {
            case 1:  color.r = 255;  break; //red
            case 2:  color.g = 255;  break; //green
            case 3:  color.b = 255;   break; //blue
            case 4:  color = {255, 255,255, 255};  break; //white
            default: color = {255, 255, 0, 0}; break; //yellow
        }

        //give x and y sides different brightness
        if (side == true) 
        {
            color.a /= 2;
            color.r /= 2;
            color.g /= 2;
            color.b /= 2;
        }

        SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(render, x, draw_start, x, draw_end);
    }
}

