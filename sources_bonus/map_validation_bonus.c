/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:28 by fausto            #+#    #+#             */
/*   Updated: 2021/10/28 19:10:23 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	position_validation(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_line)
	{
		y = 0;
		while (y < game->map_col)
		{
			if (game->map[x][y] == 'E')
				game->map_e_count++;
			if (game->map[x][y] == 'P')
				game->map_p_count++;
			if (game->map[x][y] == 'C')
				game->map_c_count++;
			y++;
		}
		x++;
	}
	if (game->map_e_count != 1 || game->map_p_count != 1 || game->map_c_count == 0)
		return (0);
	return (1);
}
// -1 pois começa do 0.
// x = 1 pois x = 0 está o score
static int	wall_validation(t_data *game)
{
	int	x;
	int	y;

	x = 1;
	while (x < game->map_line)
	{
		y = 0;
		while (y < game->map_col)
		{
			if (game->map[1][y] != '1' || game->map[game->map_line - 1][y] != '1'
				|| game->map[x][0] != '1' || game->map[x][game->map_col - 1] != '1')
				return (0);
			y++;
		}
		if (y != game->map_col)
			return (0);
		x++;
	}
	return (1);
}

static int	characters_validation(t_data *game)
{
	int	x;
	int	y;

	x = 1;
	while (x < game->map_line)
	{
		y = 0;
		while (y < game->map_col)
		{
			if (game->map[x][y] != '0' && game->map[x][y] != '1' && game->map[x][y] != 'C'
				&& game->map[x][y] != 'E' && game->map[x][y] != 'P' && game->map[x][y] != 'V')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

static int	extension_validation(char *file)
{
	char	*ext;

	if (!file)
		return (0);
	ext = ft_strrchr(file, '.');
	if (ft_strncmp(ext, ".ber", 5))
		return (0);
	return (1);
}

// *file path = argv[1]
int	map_validation_bonus(t_data *game, char *file_path)
{
	game->map_e_count = 0;
	game->map_s_count = 0;
	game->map_c_count = 0;
	game->map_p_count = 0;
	game->map_line = 0;
	game->map_col = (int)ft_strlen(game->map[0]);
	while (game->map[game->map_line])
	{
		game->map_line++;
	}
	if (game->map)
	{
		if (position_validation(game) && wall_validation(game) 
			&& characters_validation(game) && extension_validation(file_path))
			return (1);
	}
	printf("MAP VALIDATION PROBLEM");
	return (0);
}
