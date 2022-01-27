/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:24 by fausto            #+#    #+#             */
/*   Updated: 2022/01/26 21:53:06 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data *game, int x)
{
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_wall, x * game->img_width, y * game->img_height);
		if (game->map[y][x] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_free_space,
				x * game->img_width, y * game->img_height);
		if (game->map[y][x] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_collectable,
				x * game->img_width, y * game->img_height);
		if (game->map[y][x] == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_player, x * game->img_width, y * game->img_height);
		if (game->map[y][x] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_exit, x * game->img_width, y * game->img_height);
		y++;
	}
}

int	map_to_win(t_data *game)
{
	int	x;

	x = 0;
	while (x < game->map_width)
	{
		draw_map(game, x);
		x++;
	}
	return (0);
}
