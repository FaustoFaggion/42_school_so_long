# include "so_long_bonus.h"

void	player_var_j_0(t_data *game, int x, int y)
{
	int	i;
	int j;

	i = game->player_x - x;
	j = game->player_y - y;
	if (j == 0)
	{
		if (i > 0)
		{
			if (game->map[y][x + 1] != '1')
			{
				game->map[y][x] = '0';
				game->map[y][x + 1] = 'v';
			}
		}
		if ( i < 0)
		{
			if (game->map[y][x - 1] != '1')
			{
				game->map[y][x] = '0';
				game->map[y][x - 1] = 'v';
			}
		}
	}
}