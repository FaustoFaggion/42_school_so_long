/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_win_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:24 by fausto            #+#    #+#             */
/*   Updated: 2021/10/27 17:53:04 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_score(t_data *game)
{	
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_S, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 0 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_C, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 1 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_O, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 2 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_R, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 3 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_E, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 4 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_0, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 6 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_0, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 7 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_0, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 8 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_0, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 9 * game->img_width, 0 * game->img_height);
}

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
	if (game->moviments == 0)
		draw_score(game);	
	if (game->moviments != 0)
		score_bonus(game);
	x = 0;
	while (x < game->map_width)
	{
		draw_map(game, x);
		x++;
	}
}
