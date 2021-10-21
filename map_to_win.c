#include "so_long.h"

/*void    img_setup(t_data *game)
{
    game->img_width = 50;
    game->img_height = 50;
    game->img_free_space = mlx_xpm_file_to_image(game->mlx_ptr, FREE_SPACE, &game->img_width, &game->img_height);
    game->img_collectable = mlx_xpm_file_to_image(game->mlx_ptr, COLLECTABLE, &game->img_width, &game->img_height);
    game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL, &game->img_width, &game->img_height);
    game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT, &game->img_width, &game->img_height);
    game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER, &game->img_width, &game->img_height);
}*/

void    map_to_win(t_data *game)
{
    int x;
    int y;

    x = 0;
    while (x < game->map_width)
    {
        y = 0;
        while (y < game->map_height)
        {
            if(game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_wall, x * game->img_width, y * game->img_height);
            if(game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, x * game->img_width, y * game->img_height);
            if(game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_collectable, x * game->img_width, y * game->img_height);
            if(game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, x * game->img_width, y * game->img_height);
            if(game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_exit, x * game->img_width, y * game->img_height);

            y++;
        }
        x++;
    }
}