/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:04 by fausto            #+#    #+#             */
/*   Updated: 2021/10/30 11:42:46 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_setup(t_data *game)
{
	game->img_width = 50;
	game->img_height = 50;
	game->img_free_space = mlx_xpm_file_to_image(game->mlx_ptr,
			FREE_SPACE, &game->img_width, &game->img_height);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTABLE, &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL, &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT, &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER, &game->img_width, &game->img_height);
}
