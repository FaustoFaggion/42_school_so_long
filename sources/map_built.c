/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:15 by fausto            #+#    #+#             */
/*   Updated: 2022/01/26 20:07:40 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	empty_line( char *temp)
{
	int	i;

	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
		{
			if (temp[i + 1] == '\n' && temp [i + 2] == '1')
			{
				free(temp);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

char	**map_built(t_data *game, char *file_path)
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
			break ;
		swap = temp;
		temp = ft_strjoin(swap, line);
		free(swap);
		free(line);
	}
	if (empty_line(temp) == 1)
		return (NULL);
	map = ft_split(temp, '\n');
	free(temp);
	close(game->map_fd);
	return (map);
}
