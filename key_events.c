#include "so_long.h"

static void key_up(t_data *game)
{
    if (game->map[game->player_y - 1][game->player_x] != '1')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, game->player_x * game->img_width, (game->player_y) * game->img_height);
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, game->player_x * game->img_width, (game->player_y - 1) * game->img_height);
        game->player_y = game->player_y - 1;
    }
}

static void key_down(t_data *game)
{
    if (game->map[game->player_y + 1][game->player_x] != '1')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, game->player_x * game->img_width, (game->player_y) * game->img_height);
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, game->player_x * game->img_width, (game->player_y + 1) * game->img_height);
        game->player_y = game->player_y + 1;
    }
}

static void key_left(t_data *game)
{
    if (game->map[game->player_y][game->player_x - 1] != '1')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, game->player_x * game->img_width, (game->player_y) * game->img_height);
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, (game->player_x - 1) * game->img_width, (game->player_y) * game->img_height);
        game->player_x = game->player_x - 1;
    }
}

static void key_right(t_data *game)
{
    if (game->map[game->player_y][game->player_x + 1] != '1')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, game->player_x * game->img_width, (game->player_y) * game->img_height);
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, (game->player_x + 1) * game->img_width, (game->player_y) * game->img_height);
        game->player_x = game->player_x + 1;
    }
}

int    key_events(int key, t_data *game)
{
    printf("Movements: %d\n", game->moviments);
    if (key == KEY_ESC)
        game_exit(game);
    else if (key == KEY_UP || key == KEY_W)
        key_up(game);
    else if (key == KEY_DOWN || key == KEY_S)
        key_down(game);
    else if (key == KEY_LEFT || key == KEY_A)
        key_left(game);
    else if (key == KEY_RIGHT || key == KEY_D)
        key_right(game);
    game->moviments++;   
    if (game->map[game->player_y][game->player_x] == 'C')
    {
        game->map[game->player_y][game->player_x] = '0';
        game->map_c_count--;
    }
    if (game->map[game->player_y][game->player_x] == 'E' && game->map_c_count == 0)
    {
        printf("Game Finished!!");       
        game_exit(game);
    }
    return (0);
}