# include "so_long_bonus.h"

void	patrol_mov_y(t_data *game, int x, int y)
{
	int	i;
	int j;

	i = game->player_x - x;
	j = game->player_y - y;
		if (i > 0)
		{
			if (game->map[y][x + 1] != '1' && game->map[y][x + 1] != 'C'
				&& game->map[y][x + 1] != 'v' && game->map[y][x + 1] != 'V')
			{
				game->map[y][x] = '0';
				game->map[y][x + 1] = 'v';
			}
			else if (game->map[y][x + 1] != '1' && game->map[y][x + 1] == 'C'
				&& game->map[y][x + 2] == '0')
			{
				game->map[y][x] = '0';
				game->map[y][x + 2] = 'v';
			}
			else if (game->map[y][x + 1] == '1' && game->map[y + 1][x] == '0')
			{
				game->map[y][x] = '0';
				game->map[y + 1][x] = 'v';
			}
			else if (game->map[y][x + 1] == '1' && game->map[y - 1][x] == '0')
			{
				game->map[y][x] = '0';
				game->map[y - 1][x] = 'v';
			}
		}
		else if ( i < 0)
		{
			if (game->map[y][x - 1] != '1' && game->map[y][x - 1] != 'C'
				&& game->map[y][x - 1] != 'v' && game->map[y][x - 1] != 'V')
			{
				game->map[y][x] = '0';
				game->map[y][x - 1] = 'v';
			}
			else if (game->map[y][x - 1] != '1' && game->map[y][x - 1] == 'C'
				 && game->map[y][x - 2] == '0')
			{
				game->map[y][x] = '0';
				game->map[y][x - 2] = 'v';
			}
			else if (game->map[y][x - 1] == '1' && game->map[y + 1][x] == '0')
			{
				game->map[y][x] = '0';
				game->map[y + 1][x] = 'v';
			}
			else if (game->map[y][x - 1] == '1' && game->map[y - 1][x] == '0')
			{
				game->map[y][x] = '0';
				game->map[y - 1][x] = 'v';
			}
		}
}