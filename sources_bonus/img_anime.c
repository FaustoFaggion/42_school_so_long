# include "so_long_bonus.h"

int	img_anime(t_data *game)
{
	int			x;
	int			y;
	static int	speed;
	static int	flag;

	x = 0;
	speed++;
	if (speed == 1000)
	{
		while (x < game->map_line)
		{
			y = 0;
			while (y < game->map_col)
			{
				if (game->map[x][y] == 'C')
				{
					if (flag == 0)
					{	
						mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_collectable, y * game->img_width, x * game->img_height);
						flag = 1;
					}
					else if (flag == 1)
					{	
						mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_patrol, y * game->img_width, x * game->img_height);
						flag = 0;
					}
				}
				y++;
			}
			x++;
		}
		speed = 0;
	}
	return (0);
}