#include "so_long.h"

int main(int argc, char **argv)
{
    t_data  game;

    setbuf(stdout, NULL);
    if (argc == 2)
    {
        
        game.map = map_built(&game, argv[1]);
        if (map_validation(&game, argv[1]))
        {
            game.mlx_ptr = mlx_init();
            img_setup(&game);
            game.mlx_win = mlx_new_window(game.mlx_ptr, game.img_width * game.map_width, game.img_height * game.map_height, "SO_LONG");
            map_to_win(&game);
            game_setup(&game);
            mlx_hook(game.mlx_win, 2, 1L<<0, key_events, &game);
            mlx_loop(game.mlx_ptr);
        }
    }
    else
    {
        printf("Path to map not found!\n");
    }
    return (0);
}
