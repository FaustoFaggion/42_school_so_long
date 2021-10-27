# include "so_long_bonus.h"

void	patrol_mov_x(t_data *game, int x, int y)
{
	int	i;
	int j;

	i = game->player_x - x;
	j = game->player_y - y;
	if (j > 0)
	{
		if (game->map[y + 1][x] != '1' && game->map[y + 1][x] != 'C' 
			&& game->map[y + 1][x] != 'v' && game->map[y + 1][x] != 'V')
		{
			game->map[y][x] = '0';
			game->map[y + 1][x] = 'v';
		}
		else if (game->map[y + 1][x] != '1' && game->map[y + 1][x] == 'C' 
			&& (game->map[y + 2][x] == '0' || game->map[y + 2][x] == 'P'))
		{
			game->map[y][x] = '0';
			game->map[y + 2][x] = 'v';
		}
		else if (game->map[y + 1][x] == '1' && game->map[y][x + 1] == '0'
			&& game->map[y][x + 1] == 'P')
		{
			game->map[y][x] = '0';
			game->map[y][x + 1] = 'v';
		}
		else if (game->map[y + 1][x] == '1' && game->map[y][x - 1] == '0'
			&& game->map[y][x - 1] == 'P')
		{
			game->map[y][x] = '0';
			game->map[y][x - 1] = 'v';
		}
	}
	else if ( j < 0)
	{
		if (game->map[y - 1][x] != '1' && game->map[y - 1][x] != 'C'
			&& game->map[y - 1][x] != 'v' && game->map[y - 1][x] != 'V')
		{
			game->map[y][x] = '0';
			game->map[y - 1][x] = 'v';
		}
		else if (game->map[y - 1][x] != '1' && game->map[y - 1][x] == 'C'
			&& (game->map[y - 2][x] == '0' || game->map[y - 2][x] == 'P'))
		{
			game->map[y][x] = '0';
			game->map[y - 2][x] = 'v';
		}
		else if (game->map[y - 1][x] == '1' && game->map[y][x + 1] == '0')
		{
			game->map[y][x] = '0';
			game->map[y][x + 1] = 'v';
		}
		else if (game->map[y - 1][x] == '1' && game->map[y][x - 1] == '0')
		{
			game->map[y][x] = '0';
			game->map[y][x - 1] = 'v';
		}
	}
}
