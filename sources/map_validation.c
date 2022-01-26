/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:28 by fausto            #+#    #+#             */
/*   Updated: 2022/01/26 20:42:47 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (game->map_e_count != 1 || game->map_p_count != 1
		|| game->map_c_count == 0)
		return (1);
	return (0);
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
			if (game->map[0][x] != '1'
				|| game->map[game->map_height - 1][x] != '1'
				|| game->map[y][0] != '1' ||
				game->map[y][game->map_width - 1] != '1')
				return (1);
			y++;
		}
		if (y != game->map_height)
			return (1);
		x++;
	}
	return (0);
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
			if (game->map[y][x] != '0' && game->map[y][x] != '1'
				&& game->map[y][x] != 'C' && game->map[y][x] != 'E'
				&& game->map[y][x] != 'P')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	extension_validation(char *file)
{
	char	*ext;

	if (!file)
		return (1);
	ext = ft_strrchr(file, '.');
	if (ext == NULL)
		return (1);
	if (ft_strncmp(ext, ".ber", 5) == 0)
		return (0);
	printf("extension not ok\n");
	return (1);
}

// *file path = argv[1]
int	map_validation(t_data *game)
{
	int	a;
	int	b;
	int	c;
	int	i;

	game->map_e_count = 0;
	game->map_s_count = 0;
	game->map_c_count = 0;
	game->map_p_count = 0;
	game->map_height = 0;
	game->map_width = (int)ft_strlen(game->map[0]);
	i = map_square(game);
	while (game->map[game->map_height])
		game->map_height++;
	a = position_validation(game);
	b = wall_validation(game);
	c = characters_validation(game);
	if (a == 0 && b == 0 && c == 0 && i == 0)
		return (0);
	printf("MAP VALIDATION PROBLEM");
	return (1);
}
