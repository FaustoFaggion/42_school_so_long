# include "so_long_bonus.h"

void	patrol_mov_x(t_data *game, int x, int y)
{
	int	i;
	int j;

	i = game->player_line - x;
	j = game->player_col - y;
	if (j > 0)
	{
		if (game->map[x + 1][y] != '1' && game->map[x + 1][y] != 'C' 
			&& game->map[x + 1][y] != 'v' && game->map[x + 1][y] != 'V')
		{
			game->map[x][y] = '0';
			game->map[x + 1][y] = 'v';
		}
		else if (game->map[x + 1][y] != '1' && game->map[x + 1][y] == 'C' 
			&& (game->map[x + 2][y] == '0' || game->map[x + 2][y] == 'P'))
		{
			game->map[x][y] = '0';
			game->map[x + 2][y] = 'v';
		}
		else if (game->map[x + 1][y] == '1' && game->map[x][y + 1] == '0'
			&& game->map[x][y + 1] == 'P')
		{
			game->map[x][y] = '0';
			game->map[x][y + 1] = 'v';
		}
		else if (game->map[x + 1][y] == '1' && game->map[x][y - 1] == '0'
			&& game->map[x][y - 1] == 'P')
		{
			game->map[x][y] = '0';
			game->map[x][y - 1] = 'v';
		}
	}
	else if ( j < 0)
	{
		if (game->map[x - 1][y] != '1' && game->map[x - 1][y] != 'C'
			&& game->map[x - 1][y] != 'v' && game->map[x - 1][y] != 'V')
		{
			game->map[x][y] = '0';
			game->map[x - 1][y] = 'v';
		}
		else if (game->map[x - 1][y] != '1' && game->map[x - 1][y] == 'C'
			&& (game->map[x - 2][y] == '0' || game->map[x - 2][y] == 'P'))
		{
			game->map[x][y] = '0';
			game->map[x - 2][y] = 'v';
		}
		else if (game->map[x - 1][y] == '1' && game->map[x][y + 1] == '0')
		{
			game->map[x][y] = '0';
			game->map[x][y + 1] = 'v';
		}
		else if (game->map[x - 1][y] == '1' && game->map[x][y - 1] == '0')
		{
			game->map[x][y] = '0';
			game->map[x][y - 1] = 'v';
		}
	}
}
