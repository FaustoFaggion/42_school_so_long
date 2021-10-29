# include "so_long_bonus.h"

static int	xy_neg_free(t_data *game)
{
	if (game->map[game->patrol_line][game->patrol_col - 1] != '1' 
		&& game->map[game->patrol_line][game->patrol_col - 1] != 'C' 
		&& game->map[game->patrol_line][game->patrol_col - 1] != 'v'
		&& game->map[game->patrol_line][game->patrol_col - 1] != 'V')
	{
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line][game->patrol_col - 1] = 'v';
		return (0);
	}
	else if (game->map[game->patrol_line][game->patrol_col - 1] != '1'
	 	&& game->map[game->patrol_line][game->patrol_col - 1] == 'C'
		&& (game->map[game->patrol_line][game->patrol_col - 2] == '0'
	 	|| game->map[game->patrol_line][game->patrol_col - 2] == 'P'))
	{
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line][game->patrol_col - 2] = 'v';
		return (0);
	}
	return (1);
}

static int	xy_neg_wall(t_data *game)
{
	if (game->map[game->patrol_line][game->patrol_col - 1] == '1'
		&& (game->map[game->patrol_line + 1][game->patrol_col] == '0'
		|| game->map[game->patrol_line + 1][game->patrol_col] == 'P'))
	{
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line + 1][game->patrol_col] = 'v';
		return (0);
	}
	else if (game->map[game->patrol_line][game->patrol_col - 1] == '1'
		&& (game->map[game->patrol_line - 1][game->patrol_col] == '0'
		|| game->map[game->patrol_line - 1][game->patrol_col] == 'P'))
	{
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line - 1][game->patrol_col] = 'v';
		return (0);
	}
	return (1);
}

static int	xy_pos_free(t_data *game)
{
	if (game->map[game->patrol_line][game->patrol_col + 1] != '1' 
		&& game->map[game->patrol_line][game->patrol_col + 1] != 'C' 
		&& game->map[game->patrol_line][game->patrol_col + 1] != 'v'
		&& game->map[game->patrol_line][game->patrol_col + 1] != 'V')
	{
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line][game->patrol_col + 1] = 'v';
		return (0)
;	}
	else if (game->map[game->patrol_line][game->patrol_col + 1] != '1'
	 	&& game->map[game->patrol_line][game->patrol_col + 1] == 'C'
		&& (game->map[game->patrol_line][game->patrol_col + 2] == '0'
	 	|| game->map[game->patrol_line][game->patrol_col + 2] == 'P'))
	{
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line][game->patrol_col + 2] = 'v';
		return (0);
	}
	return (1);
}

static int	xy_pos_wall(t_data *game)
{
	if (game->map[game->patrol_line][game->patrol_col + 1] == '1'
		&& (game->map[game->patrol_line + 1][game->patrol_col] == '0'
		|| game->map[game->patrol_line + 1][game->patrol_col] == 'P'))
	{
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line + 1][game->patrol_col] = 'v';
		return (0);
	}
	else if (game->map[game->patrol_line][game->patrol_col + 1] == '1'
		&& (game->map[game->patrol_line - 1][game->patrol_col] == '0'
		|| game->map[game->patrol_line - 1][game->patrol_col] == 'P'))
	{
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line - 1][game->patrol_col] = 'v';
		return (0);
	}
	return (1);
}

void	patrol_mov_xy(t_data *game)
{
	static int	flag;
	
	printf("EEEEE");
	if (flag ==0)
	{
		if(xy_neg_free(game))
			xy_neg_wall(game);	
		flag = 1
	}
	else if (falg == 1))
	{
		if (xy_pos_free(game))
			xy_pos_wall(game);
		flag = 0;
	}
}	