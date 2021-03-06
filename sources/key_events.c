/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:10 by fausto            #+#    #+#             */
/*   Updated: 2022/01/27 11:29:16 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	key_up(t_data *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y - 1][game->player_x] == 'E'
			&& game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit(game);
		}
		if (game->map[game->player_y - 1][game->player_x] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y - 1][game->player_x] = 'P';
			map_to_win(game);
			game->player_y = game->player_y - 1;
			game->moviments++;
			printf("Movements: %d\n", game->moviments);
		}
	}
}

static void	key_down(t_data *game)
{
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		if (game->map[game->player_y + 1][game->player_x] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y + 1][game->player_x] == 'E'
			&& game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit(game);
		}
		if (game->map[game->player_y + 1][game->player_x] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y + 1][game->player_x] = 'P';
			map_to_win(game);
			game->player_y = game->player_y + 1;
			game->moviments++;
			printf("Movements: %d\n", game->moviments);
		}
	}
}

static void	key_left(t_data *game)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		if (game->map[game->player_y][game->player_x - 1] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y][game->player_x - 1] == 'E'
			&& game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit(game);
		}
		if (game->map[game->player_y][game->player_x - 1] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y][game->player_x - 1] = 'P';
			map_to_win(game);
			game->player_x = game->player_x - 1;
			game->moviments++;
			printf("Movements: %d\n", game->moviments);
		}
	}
}

static void	key_right(t_data *game)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		if (game->map[game->player_y][game->player_x + 1] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y][game->player_x + 1] == 'E'
			&& game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit(game);
		}
		if (game->map[game->player_y][game->player_x + 1] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y][game->player_x + 1] = 'P';
			map_to_win(game);
			game->player_x = game->player_x + 1;
			game->moviments++;
			printf("Movements: %d\n", game->moviments);
		}
	}
}

int	key_events(int key, t_data *game)
{
	if (key == KEY_ESC)
		game_exit(game);
	else if (key == KEY_UP || key == KEY_W)
		key_up(game);
	else if (key == KEY_DOWN || key == KEY_S)
		key_down(game);
	else if (key == KEY_LEFT || key == KEY_A)
		key_left(game);
	else if (key == KEY_RIGHT || key == KEY_D)
		key_right(game);
	return (0);
}
