# include "so_long_bonus.h"

void	patrol_mov_y(t_data *game, int x, int y)
{
	int	i;
	int j;

	i = game->player_line - x;
	j = game->player_col - y;
		if (i > 0)
		{
			if (game->map[x][y + 1] != '1' && game->map[x][y + 1] != 'C'
				&& game->map[x][y + 1] != 'v' && game->map[x][y + 1] != 'V')
			{
				game->map[x][y] = '0';
				game->map[x][y + 1] = 'v';
			}
			else if (game->map[x][y + 1] != '1' && game->map[x][y + 1] == 'C'
				&& (game->map[x][y + 2] == '0' || game->map[x][y + 2] == 'P'))
			{
				game->map[x][y] = '0';
				game->map[x][y + 2] = 'v';
			}
			else if (game->map[x][y + 1] == '1' && game->map[x + 1][y] == '0')
			{
				game->map[x][y] = '0';
				game->map[x + 1][y] = 'v';
			}
			else if (game->map[x][y + 1] == '1' && game->map[x - 1][y] == '0')
			{
				game->map[x][y] = '0';
				game->map[x - 1][y] = 'v';
			}
		}
		else if ( i < 0)
		{
			if (game->map[x][y - 1] != '1' && game->map[x][y - 1] != 'C'
				&& game->map[x][y - 1] != 'v' && game->map[x][y - 1] != 'V')
			{
				game->map[x][y] = '0';
				game->map[x][y - 1] = 'v';
			}
			else if (game->map[x][y - 1] != '1' && game->map[x][y - 1] == 'C'
				 && (game->map[x][y - 2] == '0' || game->map[x][y - 2] == 'P'))
			{
				game->map[x][y] = '0';
				game->map[x][y - 2] = 'v';
			}
			else if (game->map[x][y - 1] == '1' && game->map[x + 1][y] == '0')
			{
				game->map[x][y] = '0';
				game->map[x + 1][y] = 'v';
			}
			else if (game->map[x][y - 1] == '1' && game->map[x - 1][y] == '0')
			{
				game->map[x][y] = '0';
				game->map[x - 1][y] = 'v';
			}
		}
}