/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_win_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:24 by fausto            #+#    #+#             */
/*   Updated: 2022/01/27 12:04:08 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_map(t_data *game, int x)
{
	int	y;

	y = 0;
	while (y < game->map_col)
	{
		if (game->map[x][y] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_wall, y * game->img_width, x * game->img_height);
		else if (game->map[x][y] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_free_space, y * game->img_width,
				x * game->img_height);
		else if (game->map[x][y] == 'C')
			img_anime(game, x, y);
		else if (game->map[x][y] == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_player, y * game->img_width, x * game->img_height);
		else if (game->map[x][y] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_exit, y * game->img_width, x * game->img_height);
		else if (game->map[x][y] == 'V')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_patrol, y * game->img_width, x * game->img_height);
		y++;
	}
}

int	map_to_win_bonus(t_data *game)
{
	int	x;

	score_bonus(game);
	x = 1;
	while (x < game->map_line)
	{
		draw_map(game, x);
		x++;
	}
	return (0);
}
