/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:20:59 by fausto            #+#    #+#             */
/*   Updated: 2021/10/26 11:46:33 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_setup_bonus(t_data *game)
{
	int x;
	int y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if(game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y + 1;
				break;
			}
			y++;
		}
		x++;
	}
	game->moviments = 0;
	game->patrol_mov = 0;
}
