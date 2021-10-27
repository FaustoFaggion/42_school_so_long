/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:10 by fausto            #+#    #+#             */
/*   Updated: 2021/10/27 17:10:27 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*static void	score_print(t_data *game, int n)
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
	
static void	score(t_data *game)
{
	int	n;
	int	dec;
	int	x;

	x = 9;	
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
}*/

static void	key_up(t_data *game)
{
	if (game->map[game->player_y - 2][game->player_x] != '1')
	{
		if (game->map[game->player_y - 2][game->player_x] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y - 2][game->player_x] == 'E' && game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit_bonus(game);
		}
		if (game->map[game->player_y - 2][game->player_x] != 'E' || game->map_c_count == 0)
		{
			//mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, game->player_x * game->img_width, (game->player_y) * game->img_height);
			//mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, game->player_x * game->img_width, (game->player_y - 1) * game->img_height);
			game->map[game->player_y - 1][game->player_x] = '0';
			game->map[game->player_y - 2][game->player_x] = 'P';
			game->player_y = game->player_y - 1;
			game->moviments++;
			map_to_win_bonus(game);
			//score(game);
		}
	}
}

static void	key_down(t_data *game)
{
	if (game->map[game->player_y][game->player_x] != '1')
	{
		if (game->map[game->player_y][game->player_x] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y][game->player_x] == 'E' && game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit_bonus(game);
		}
		if (game->map[game->player_y][game->player_x] != 'E' || game->map_c_count == 0)
		{
			//mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, game->player_x * game->img_width, (game->player_y) * game->img_height);
			//mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, game->player_x * game->img_width, (game->player_y + 1) * game->img_height);
			game->map[game->player_y - 1][game->player_x] = '0';
			game->map[game->player_y][game->player_x] = 'P';
			game->player_y = game->player_y + 1;
			game->moviments++;
			map_to_win_bonus(game);
			//score(game);
		}
	}
}

static void	key_left(t_data *game)
{
	if (game->map[game->player_y - 1][game->player_x - 1] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x - 1] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y - 1][game->player_x - 1] == 'E' && game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit_bonus(game);
		}
		if (game->map[game->player_y - 1][game->player_x - 1] != 'E' || game->map_c_count == 0)
		{
			//mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, game->player_x * game->img_width, (game->player_y) * game->img_height);
			//mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, (game->player_x - 1) * game->img_width, (game->player_y) * game->img_height);
			game->map[game->player_y - 1][game->player_x] = '0';
			game->map[game->player_y - 1][game->player_x - 1] = 'P';
			game->player_x = game->player_x - 1;
			game->moviments++;
			map_to_win_bonus(game);
			//score(game);
		}
	}
}

static void	key_right(t_data *game)
{
	if (game->map[game->player_y - 1][game->player_x + 1] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x + 1] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y - 1][game->player_x + 1] != 'E' || game->map_c_count == 0)
		{
			//mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, game->player_x * game->img_width, (game->player_y) * game->img_height);
			//mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, (game->player_x + 1) * game->img_width, (game->player_y) * game->img_height);
			game->map[game->player_y - 1][game->player_x] = '0';
			game->map[game->player_y - 1][game->player_x + 1] = 'P';
			game->player_x = game->player_x + 1;
			game->moviments++;
			map_to_win_bonus(game);
			//score(game);
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
	/*if (game->map[game->player_y - 1][game->player_x] == 'C')
	{
		game->map[game->player_y - 1][game->player_x] = '0';
		game->map_c_count--;
	}*/
	/*if (game->map[game->player_y - 1][game->player_x] == 'E' && game->map_c_count == 0)
	{
		printf("Game Finished!!");       
		game_exit_bonus(game);
	}*/
	return (0);
}
