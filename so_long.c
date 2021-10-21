#include "so_long.h"

int main(int argc, char **argv)
{
    t_data  game;

    
    if (argc == 2)
    {
        
        game.map = map_built(&game, argv[1]);
        if (map_validation(&game, argv[1]))
        {
            game.mlx_ptr = mlx_init();
            game.mlx_win = mlx_new_window(game.mlx_ptr, 500, 500, "SO_LONG");
            img_setup(&game);
            map_to_win(&game);
            mlx_loop(game.mlx_ptr);
        }
    }
    else
    {
        printf("Path to map not found!\n");
    }
    return (0);
}
