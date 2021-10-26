/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:28 by fausto            #+#    #+#             */
/*   Updated: 2021/10/26 11:21:54 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	position_validation(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[y][x] == 'E')
				game->map_e_count++;
			if (game->map[y][x] == 'P')
				game->map_p_count++;
			if (game->map[y][x] == 'C')
				game->map_c_count++;
			y++;
		}
		x++;
	}
	if (game->map_e_count != 1 || game->map_p_count != 1 || game->map_c_count == 0)
		return (0);
	return (1);
}

static int	wall_validation(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[0][x] != '1' || game->map[game->map_height - 1][x] != '1'
				|| game->map[y][0] != '1' || game->map[y][game->map_width - 1] != '1')
				return (0);
			y++;
		}
		if (y != game->map_height)
			return (0);
		x++;
	}
	return (1);
}

static int	characters_validation(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[y][x] != '0' && game->map[y][x] != '1' && game->map[y][x] != 'C'
				&& game->map[y][x] != 'E' && game->map[y][x] != 'P' && game->map[y][x] != 'V')
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
	game->map_height = 0;
	game->map_width = (int)ft_strlen(game->map[0]);
	while (game->map[game->map_height])
	{
		game->map_height++;
	}
	if (game->map)
	{
		if (position_validation(game) && wall_validation(game) 
			&& characters_validation(game) && extension_validation(file_path))
			return (1);
	}
	return (0);
}
