#include "so_long_bonus.h"

static void player_find(t_data *game, int x, int y)
{
	int	i;
	int j;

	i = game->player_x - x;
	j = game->player_y - y;
	if ( i == 0)
		player_var_i_0(game, x, y);
	if ( j == 0)
		player_var_j_0(game, x, y);
}

static void	patrol_decision(t_data *game, int x, int y)
{
	player_find(game, x, y);
	
	/*if (game->map[y + 1][x] == '0')
	{	
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'v';
	}*/
}

static void	map_upper(t_data *game)
{
	int	x;
	int	y;

	x = 0;
		while (x < game->map_width)
		{
			y = 0;
			while (y < game->map_height)
			{
				if (game->map[y][x] == 'v')
				{	
					game->map[y][x] = 'V';
				}
				y++;
			}
			x++;
		}	
}

int	patrol_mov(t_data *game)
{
	int			x;
	int			y;
	static int	speed = 0;

	speed++;
	x = 0;
	if (speed == 40000)
	{
		while (x < game->map_width)
		{
			y = 0;
			while (y < game->map_height)
			{
				if (game->map[y][x] == 'V')
				{	
					patrol_decision(game, x, y);
				}
				y++;
			}
			x++;
		}
		speed = 0;
		map_upper(game);
		map_to_win_bonus(game);
	}
	return (0);
}
