/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:50 by fausto            #+#    #+#             */
/*   Updated: 2021/10/26 12:21:38 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

# define FREE_SPACE		"/home/fausto/42SP/so_long/images/free_space.xpm"
# define COLLECTABLE	"/home/fausto/42SP/so_long/images/collectable.xpm"
# define WALL			"/home/fausto/42SP/so_long/images/wall.xpm" 
# define EXIT			"/home/fausto/42SP/so_long/images/exit.xpm" 
# define PLAYER			"/home/fausto/42SP/so_long/images/player.xpm" 
# define PATROL			"/home/fausto/42SP/so_long/images/patrol.xpm"
# define MOV			"/home/fausto/42SP/so_long/images/moviments.xpm"
 
# define KEY_ESC		65307
# define KEY_W			119
# define KEY_S			115 
# define KEY_A			97
# define KEY_D			100
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		mlx_win_width;
	int		mlx_win_height;
	char	**map;
	int		map_fd;
	int		map_e_count;
	int		map_s_count;
	int		map_c_count;
	int		map_p_count;
	int		map_width;
	int		map_height;
	void	*img_free_space;
	void	*img_collectable;
	void	*img_wall;
	void	*img_exit;
	void	*img_player;
	void	*img_patrol;
	void	*img_moviments;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		moviments;
	int		patrol_mov;

}			t_data;


char	**map_built_bonus(t_data *game, char *flie_path);

int		map_validation_bonus(t_data *game, char *file_path);

void	map_to_win_bonus(t_data *game);

void	img_setup_bonus(t_data *game);

void	game_setup_bonus(t_data *game);

int		key_events_bonus(int key, t_data *game);
//int		win_events(t_data *game);

int		game_exit_bonus(t_data *game);

//void	patrol_mov(t_data *game);
#endif