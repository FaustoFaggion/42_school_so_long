/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:44:35 by fagiusep          #+#    #+#             */
/*   Updated: 2022/01/26 20:44:43 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_square(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		if ((int)ft_strlen(game->map[i]) != game->map_width)
			return (1);
		i++;
	}
	return (0);
}
