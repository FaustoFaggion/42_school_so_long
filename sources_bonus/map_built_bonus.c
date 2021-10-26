/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_built_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:15 by fausto            #+#    #+#             */
/*   Updated: 2021/10/25 18:38:30 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**map_built_bonus(t_data *game, char *file_path)
{
	char	**map;
	char	*swap;
	char	*line;
	char	*temp;

	game->map_fd = open(file_path, O_RDONLY);
	if (game->map_fd == -1)
		return (NULL);
	temp = ft_strdup("");
	while (1)
	{
		line = ft_get_next_line(game->map_fd);
		if (!line)
			break;
		swap = temp;
		temp = ft_strjoin(swap, line);
		free(swap);
		free(line);
	}
	map = ft_split(temp, '\n');
	free(temp);
	close(game->map_fd);
	return (map);
}
