/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:35 by fausto            #+#    #+#             */
/*   Updated: 2021/11/24 11:20:14 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_play(t_data *game)
{
	game->mlx_ptr = mlx_init();
	img_setup(game);
	game->mlx_win = mlx_new_window(game->mlx_ptr,
		game->img_width * game->map_width,
		game->img_height * game->map_height, "SO_LONG");
	map_to_win(game);
	game_setup(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_events, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, game_exit, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (extension_validation(argv[1]) == 1)
		return (1);
	setbuf(stdout, NULL);
	if (argc == 2)
	{
		game.map = map_built(&game, argv[1]);
		if (game.map == NULL || *game.map == NULL)
		{
			ft_clear_split(game.map);
			return (1);
		}
		if (map_validation(&game) == 0)
			game_play(&game);
		else
		{
			ft_clear_split(game.map);
			exit(1);
		}
	}
	else
		printf("Path to map not found!\n");
	return (0);
}
