/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:50 by fausto            #+#    #+#             */
/*   Updated: 2021/10/27 14:13:13 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

# define FREE_SPACE		"./images/free_space.xpm"
# define COLLECTABLE	"./images/collectable.xpm"
# define WALL			"./images/wall.xpm"
# define EXIT			"./images/exit.xpm"
# define PLAYER			"./images/player.xpm"
# define PATROL			"./images/patrol.xpm"
# define SCORE_S		"./images/score_s.xpm"
# define SCORE_C		"./images/score_c.xpm"
# define SCORE_O		"./images/score_o.xpm"
# define SCORE_R		"./images/score_r.xpm"
# define SCORE_E		"./images/score_e.xpm"
# define SCORE_0		"./images/score_0.xpm"
# define SCORE_1		"./images/score_1.xpm"
# define SCORE_2		"./images/score_2.xpm"
# define SCORE_3		"./images/score_3.xpm"
# define SCORE_4		"./images/score_4.xpm"
# define SCORE_5		"./images/score_5.xpm"
# define SCORE_6		"./images/score_6.xpm"
# define SCORE_7		"./images/score_7.xpm"
# define SCORE_8		"./images/score_8.xpm"
# define SCORE_9		"./images/score_9.xpm"

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
	void	*score_img;
	void	*score;
	void	*score_1;
	void	*score_2;
	void	*score_3;
	void	*score_4;
	char	*score_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		patrol_mov;

}			t_data;


char	**map_built_bonus(t_data *game, char *flie_path);

int		map_validation_bonus(t_data *game, char *file_path);

void	map_to_win_bonus(t_data *game);

void	img_setup_bonus(t_data *game);

void	game_setup_bonus(t_data *game);

int		key_events_bonus(int key, t_data *game);

int		game_exit_bonus(t_data *game);

int		patrol_mov(t_data *game);

void 	player_var_i_0(t_data *game, int i, int j);

void 	player_var_j_0(t_data *game, int i, int j);
#endif