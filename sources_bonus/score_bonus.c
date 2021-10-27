/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:10 by fausto            #+#    #+#             */
/*   Updated: 2021/10/27 17:53:39 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	score_print(t_data *game, int n)
{
	if (n == 0)
		game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_0, &game->img_width, &game->img_height);	
	else if (n == 1)
		game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_1, &game->img_width, &game->img_height);
	else if (n == 2)
		game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_2, &game->img_width, &game->img_height);
	else if (n == 3)
		game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_3, &game->img_width, &game->img_height);
	else if (n == 4)
		game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_4, &game->img_width, &game->img_height);
	else if (n == 5)
		game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_5, &game->img_width, &game->img_height);
	else if (n == 6)
		game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_6, &game->img_width, &game->img_height);
	else if (n == 7)
		game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_7, &game->img_width, &game->img_height);
	else if (n == 8)
		game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_8, &game->img_width, &game->img_height);
	else if (n == 9)
		game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_9, &game->img_width, &game->img_height);
}
	
void	score_bonus(t_data *game)
{
	int	n;
	int	dec;
	int	x;
	
	x = 9;
	if (game->moviments != 0)
	{
		n = game->moviments % 10;
		score_print(game, n);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, x * game->img_width, 0 * game->img_height);	
		dec = game->moviments / 10;
		while (dec > 0)
		{
			x--;
			n = dec % 10;
			score_print(game, n);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, x * game->img_width, 0 * game->img_height);	
			dec = dec / 10;
		}
	}
}