#include "so_long_bonus.h"

/*static void	patrol_decision(t_data *game, int x, int y)
{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, x * game->img_width, y * game->img_height);
		game->map[y][x] = '0';
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, x * game->img_width, (y - 1) * game->img_height);
		game->map[y - 1][x] = 'V';
}*/

void	patrol_mov(t_data *game)
{
	int	x;
	int	y;

	game->patrol_mov += game->patrol_mov;
	x = 0;
	if (game->patrol_mov == 3)
	{
		while (x < game->map_width)
		{
			y = 0;
			while (y < game->map_height)
			{
				if (game->map[y][x] == 'V')
				{	
					//patrol_decision(game, x, y);
					mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, x * game->img_width, y * game->img_height);
					game->map[y][x] = '0';
					mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, x * game->img_width, (y - 1) * game->img_height);
					game->map[y - 1][x] = 'V';
				}
				y++;
			}
			x++;
		}
		game->patrol_mov = 0;
	}
}
