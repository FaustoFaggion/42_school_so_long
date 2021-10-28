/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:20:59 by fausto            #+#    #+#             */
/*   Updated: 2021/10/28 19:55:56 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_setup_bonus(t_data *game)
{
	int x;
	int y;

	x = 0;
	while (x < game->map_line)
	{
		y = 0;
		while (y < game->map_col)
		{
			if(game->map[x][y] == 'P')
			{
				game->player_line = x;
				game->player_col = y;
				break;
			}
			y++;
		}
		x++;
	}
	game->moviments = 0;
	//game->patrol_mov = 0;
}
