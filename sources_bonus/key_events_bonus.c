/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:10 by fausto            #+#    #+#             */
/*   Updated: 2021/10/26 13:03:42 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	key_up(t_data *game)
{
	if (game->map[game->player_y - 2][game->player_x] != '1')
	{
		if (game->map[game->player_y - 2][game->player_x] != 'E' || game->map_c_count == 0)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, game->player_x * game->img_width, (game->player_y) * game->img_height);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, game->player_x * game->img_width, (game->player_y - 1) * game->img_height);
			game->player_y = game->player_y - 1;
			game->moviments++;
			printf("Movements: %d\n", game->moviments);
		}
	}
}

static void	key_down(t_data *game)
{
	if (game->map[game->player_y][game->player_x] != '1')
	{
		if (game->map[game->player_y][game->player_x] != 'E' || game->map_c_count == 0)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, game->player_x * game->img_width, (game->player_y) * game->img_height);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, game->player_x * game->img_width, (game->player_y + 1) * game->img_height);
			game->player_y = game->player_y + 1;
			game->moviments++;
			printf("Movements: %d\n", game->moviments);
		}
	}
}

static void	key_left(t_data *game)
{
	if (game->map[game->player_y - 1][game->player_x - 1] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x - 1] != 'E' || game->map_c_count == 0)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, game->player_x * game->img_width, (game->player_y) * game->img_height);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, (game->player_x - 1) * game->img_width, (game->player_y) * game->img_height);
			game->player_x = game->player_x - 1;
			game->moviments++;
			printf("Movements: %d\n", game->moviments);
		}
	}
}

static void	key_right(t_data *game)
{
	if (game->map[game->player_y - 1][game->player_x + 1] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x + 1] != 'E' || game->map_c_count == 0)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, game->player_x * game->img_width, (game->player_y) * game->img_height);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, (game->player_x + 1) * game->img_width, (game->player_y) * game->img_height);
			game->player_x = game->player_x + 1;
			game->moviments++;
			printf("Movements: %d\n", game->moviments);
		}
	}
}

int	key_events_bonus(int key, t_data *game)
{
	if (key == KEY_ESC)
		game_exit_bonus(game);
	else if (key == KEY_UP || key == KEY_W)
		key_up(game);
	else if (key == KEY_DOWN || key == KEY_S)
		key_down(game);
	else if (key == KEY_LEFT || key == KEY_A)
		key_left(game);
	else if (key == KEY_RIGHT || key == KEY_D)
		key_right(game); 
	if (game->map[game->player_y - 1][game->player_x] == 'C')
	{
		game->map[game->player_y - 1][game->player_x] = '0';
		game->map_c_count--;
	}
	if (game->map[game->player_y - 1][game->player_x] == 'E' && game->map_c_count == 0)
	{
		printf("Game Finished!!");       
		game_exit_bonus(game);
	}
	return (0);
}
