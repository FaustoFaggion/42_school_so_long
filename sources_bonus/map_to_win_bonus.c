/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_win_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:24 by fausto            #+#    #+#             */
/*   Updated: 2021/10/26 14:06:59 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*static void	draw_score(t_data *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_moviments, 0, 0);
}*/

static void	draw_map(t_data *game, int x)
{
	int	y;
	
	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_wall, x * game->img_width, (y + 1) * game->img_height);
		else if (game->map[y][x] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, x * game->img_width, (y + 1) * game->img_height);
		else if (game->map[y][x] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_collectable, x * game->img_width, (y + 1) * game->img_height);
		else if (game->map[y][x] == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, x * game->img_width, (y + 1) * game->img_height);
		else if (game->map[y][x] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_exit, x * game->img_width, (y + 1) * game->img_height);
		else if (game->map[y][x] == 'V')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_patrol, x * game->img_width, (y + 1) * game->img_height);
		y++;
	}
}
void	map_to_win_bonus(t_data *game)
{
	int	x;
	
	//draw_score(game);
	x = 0;
	while (x < game->map_width)
	{
		draw_map(game, x);
		x++;
	}
}
