/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:20:59 by fausto            #+#    #+#             */
/*   Updated: 2021/10/25 16:21:00 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_setup(t_data *game)
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
				game->player_y = y;
				break;
			}
			y++;
		}
		x++;
	}
	game->moviments = 0;
}
