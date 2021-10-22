#include "so_long.h"

void    game_exit(t_data *game)
{
    mlx_destroy_image(game->mlx_ptr, FREE_SPACE);
    mlx_destroy_image(game->mlx_ptr, WALL);
    mlx_destroy_image(game->mlx_ptr, COLLECTABLE);
    mlx_destroy_image(game->mlx_ptr, EXIT);
    mlx_destroy_image(game->mlx_ptr, PLAYER);
    mlx_destroy_window(game->mlx_ptr, game->mlx_win);
    mlx_destroy_display(game->mlx_ptr);
    free(game->mlx_ptr);
}