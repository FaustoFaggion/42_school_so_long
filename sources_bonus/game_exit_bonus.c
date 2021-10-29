/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:20:40 by fausto            #+#    #+#             */
/*   Updated: 2021/10/29 17:54:46 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_clear_split(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

int	game_exit_bonus(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img_free_space);
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
	mlx_destroy_image(game->mlx_ptr, game->img_collectable);
	mlx_destroy_image(game->mlx_ptr, game->img_collectable_2);
	mlx_destroy_image(game->mlx_ptr, game->img_exit);
	mlx_destroy_image(game->mlx_ptr, game->img_player);
	mlx_destroy_image(game->mlx_ptr, game->img_patrol);
	mlx_destroy_image(game->mlx_ptr, game->score_s);
	mlx_destroy_image(game->mlx_ptr, game->score_c);
	mlx_destroy_image(game->mlx_ptr, game->score_o);
	mlx_destroy_image(game->mlx_ptr, game->score_r);
	mlx_destroy_image(game->mlx_ptr, game->score_e);
	mlx_destroy_image(game->mlx_ptr, game->score_0);
	mlx_destroy_image(game->mlx_ptr, game->score_1);
	mlx_destroy_image(game->mlx_ptr, game->score_2);
	mlx_destroy_image(game->mlx_ptr, game->score_3);
	mlx_destroy_image(game->mlx_ptr, game->score_4);
	mlx_destroy_image(game->mlx_ptr, game->score_5);
	mlx_destroy_image(game->mlx_ptr, game->score_6);
	mlx_destroy_image(game->mlx_ptr, game->score_7);
	mlx_destroy_image(game->mlx_ptr, game->score_8);
	mlx_destroy_image(game->mlx_ptr, game->score_9);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_clear_split(game->map);
	exit(0);
}
