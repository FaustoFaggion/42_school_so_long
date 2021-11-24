/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_built_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:15 by fausto            #+#    #+#             */
/*   Updated: 2021/11/24 10:47:51 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*add_line(char **temp)
{
	int		i;
	char	*new;
	char	*swap;

	i = 0;
	while ((*temp)[i] != '\n' && (*temp)[i] != '\0')
		i++;
	new = ft_calloc((i + 2), sizeof(char));
	new[i] = '\n';
	while (i > 0)
	{
		new[i - 1] = 'S';
		i--;
	}
	swap = *temp;
	*temp = ft_strjoin(new, swap);
	free(new);
	free(swap);
	return (*temp);
}

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
			break ;
		swap = temp;
		temp = ft_strjoin(swap, line);
		free(line);
		free(swap);
	}
	swap = add_line(&temp);
	map = ft_split(swap, '\n');
	printf("map = %s", *map);
	free(swap);
	close(game->map_fd);
	return (map);
}
