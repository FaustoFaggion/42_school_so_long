#include "so_long.h"

void    game_setup(t_data *game)
{
    int x;
    int y;

    x = 0;
    while (x < game->map_width)
    {
        y = 0;
        while (y < game->map_height)
        {
            if(game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
            }
            y++;
        }
        x++;
    }
    game->moviments = 0;
}