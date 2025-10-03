/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_valid_characters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:52:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/11 20:52:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

int	validate_map_valid_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] != EMPTY && map->grid[i][j] != WALL
				&& map->grid[i][j] != COLLECT && map->grid[i][j] != EXIT
				&& map->grid[i][j] != PLAYER)
			{
				ft_putstr("Error: map data should be valid characters");
				ft_putstr("(0, 1, C, E, P)\n");
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (OK);
}
