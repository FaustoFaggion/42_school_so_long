/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_built_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:21:15 by fausto            #+#    #+#             */
/*   Updated: 2022/01/27 12:36:30 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	empty_line( char *temp)
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
				printf("MAP VALIDATION PROBLEM");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

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
	if (empty_line(temp) == 1)
		return (NULL);
	swap = add_line(&temp);
	map = ft_split(swap, '\n');
	free(swap);
	close(game->map_fd);
	return (map);
}
