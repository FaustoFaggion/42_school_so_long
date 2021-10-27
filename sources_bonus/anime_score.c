# include "so_long_bonus.h"

int	anime_score(t_data *game)
{
	static int	speed = 0;

	speed++;
	if (speed == 10000)
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
	}
	return (0);
}