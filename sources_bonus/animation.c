#include "so_long_bonus.h"

static void	game_over(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_line)
	{
		y = 0;
		while (y < game->map_col)
		{
			if (game->map[x][y] == 'V')
			{
				if (game->player_line == x && game->player_col == y)
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

static void	map_upper(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_line)
	{
		y = 0;
		while (y < game->map_col)
		{
			if (game->map[x][y] == 'v')
			{	
				game->map[x][y] = 'V';
			}
			y++;
		}
		x++;
	}
}

static void	patrol_decision(t_data *game)
{
	int				x;
	int 			y;

	x = game->player_line - game->patrol_line;
	y = game->player_col - game->patrol_col;
	if (x < 0)
		x = x * -1;
	if (y < 0)
		y = y * -1;

	if (x < y)
		patrol_mov_x(game);
	else if (x > y)
		patrol_mov_y(game);
	//else if (x == y)
	//	patrol_mov_xy(game);
}

static int	patrol_position(t_data *game, int speed)
{
	int	x;
	int	y;

	x = 0;
	if (speed == 100)
	{
		while (x < game->map_line)
		{
			y = 0;
			while (y < game->map_col)
			{
				if (game->map[x][y] == 'V')
				{
					game->patrol_line = x;
					game->patrol_col = y;
					patrol_decision(game);
				}
				y++;
			}
			x++;
		}
		speed = 0;
	}
	return (speed);
}

int	animation(t_data *game)
{
	static int	speed;

	game_over(game);
	speed++;
	speed = patrol_position(game, speed);
	map_upper(game);
	map_to_win_bonus(game);
	return (0);
}
