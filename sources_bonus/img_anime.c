/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_anime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 10:06:04 by fausto            #+#    #+#             */
/*   Updated: 2021/10/30 10:54:47 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Called by map_to_win function when put 'C' image.
void	img_anime(t_data *game, int x, int y)
{
	static int	flag;
	static int	i;

	i++;
	if (i > 30)
	{
		if (flag == 0)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_collectable, y * game->img_width,
				x * game->img_height);
			flag = 1;
		}
		else if (flag == 1)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_collectable_2, y * game->img_width,
				x * game->img_height);
			flag = 0;
		}
		i = 0;
	}
}
