#include "so_long_bonus.h"

static void	game_over(t_data *game)
{
	int			x;
	int			y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[y][x] == 'V')
			{	
				if (game->player_x == x && game->player_y == y)
				{
					printf("GAME OVER!!!");
					game_exit_bonus(game);
				}
			}
			y++;
		}
		x++;
	}	
}

static void	patrol_decision(t_data *game, int x, int y)
{
	int	i;
	int j;

	i = game->player_x - x;
	j = (game->player_y - 1) - y;
	if ( i == 0 || j < i)
		patrol_mov_x(game, x, y);
	if ( j == 0 || i < j)
		patrol_mov_y(game, x, y);
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
	static int	speed;

	game_over(game);
	speed++;
	x = 0;
	if (speed == 10000)
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
