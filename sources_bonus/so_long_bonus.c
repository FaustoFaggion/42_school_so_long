/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:35 by fausto            #+#    #+#             */
/*   Updated: 2021/10/27 13:00:36 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	game;

	setbuf(stdout, NULL);
	if (argc == 2)
	{
		game.map = map_built_bonus(&game, argv[1]);
		if (map_validation_bonus(&game, argv[1]))
		{
			game.mlx_ptr = mlx_init();
			img_setup_bonus(&game);
			game.mlx_win = mlx_new_window(game.mlx_ptr, game.img_width * game.map_width, game.img_height * (game.map_height + 1), "SO_LONG");
			map_to_win_bonus(&game);
			game_setup_bonus(&game);
			mlx_hook(game.mlx_win, 2, 1L<<0, key_events_bonus, &game);
			mlx_hook(game.mlx_win, 17, 1L<<0, game_exit_bonus, &game);
			mlx_loop_hook(game.mlx_ptr, patrol_mov, &game);
			mlx_loop(game.mlx_ptr);
		}
	}
	else
	{
		printf("Path to map not found!\n");
	}
	return (0);
}
