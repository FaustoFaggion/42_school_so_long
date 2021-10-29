/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_win_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:24 by fausto            #+#    #+#             */
/*   Updated: 2021/10/29 10:04:42 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*static void	draw_score(t_data *game)
{	
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_S, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 0 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_C, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 1 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_O, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 2 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_R, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 3 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_E, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 4 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_0, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 6 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_0, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 7 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_0, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 8 * game->img_width, 0 * game->img_height);
	game->score_img = mlx_xpm_file_to_image(game->mlx_ptr, SCORE_0, &game->img_width, &game->img_height);	
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->score_img, 9 * game->img_width, 0 * game->img_height);
}
*/
static void	draw_map(t_data *game, int x)
{
	int	y;
	
	y = 0;
	while (y < game->map_col)
	{
		if (game->map[x][y] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_wall, y * game->img_width, x * game->img_height);
		else if (game->map[x][y] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_free_space, y * game->img_width, x * game->img_height);
		else if (game->map[x][y] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_collectable, y * game->img_width, x * game->img_height);
		else if (game->map[x][y] == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, y * game->img_width, x * game->img_height);
		else if (game->map[x][y] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_exit, y * game->img_width, x * game->img_height);
		else if (game->map[x][y] == 'V')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_patrol, y * game->img_width, x * game->img_height);
		y++;
	}
}

void	map_to_win_bonus(t_data *game)
{
	int	x;

	score_bonus(game);
	x = 1;
	while (x < game->map_line)
	{
		draw_map(game, x);
		x++;
	}
}
