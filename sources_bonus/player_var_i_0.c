# include "so_long_bonus.h"

void	player_var_i_0(t_data *game, int x, int y)
{
	int	i;
	int j;

	i = game->player_x - x;
	j = game->player_y - y;
	if (i == 0)
	{
		if (j > 0)
		{
			if (game->map[y + 1][x] != '1')
			{
				game->map[y][x] = '0';
				game->map[y + 1][x] = 'v';
			}
		}
		if ( j < 0)
		{
			if (game->map[y - 1][x] != '1')
			{
				game->map[y][x] = '0';
				game->map[y - 1][x] = 'v';
			}
		}
	}
}