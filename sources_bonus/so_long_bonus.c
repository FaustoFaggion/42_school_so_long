/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:35 by fausto            #+#    #+#             */
/*   Updated: 2022/01/28 17:46:04 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	game_play(t_data *game)
{
	game->mlx_ptr = mlx_init();
	img_setup_bonus(game);
	game->mlx_win = mlx_new_window(game->mlx_ptr,
			game->img_width * game->map_col,
			game->img_height * game->map_line, "SO_LONG");
	game_setup_bonus(game);
	map_to_win_bonus(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_events_bonus, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, game_exit_bonus, game);
	mlx_loop_hook(game->mlx_ptr, animation, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (extension_validation(argv[1]) == 1)
		return (1);
	if (argc == 2)
	{
		game.map = map_built_bonus(&game, argv[1]);
		if (game.map == NULL || *game.map == NULL)
		{
			ft_clear_split(game.map);
			return (1);
		}
		if (map_validation_bonus(&game) == 0)
			game_play(&game);
		else
		{
			ft_clear_split(game.map);
			exit (1);
		}
	}
	else
		printf("Error\nPath to map not found!\n");
	return (0);
}
