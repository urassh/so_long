/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_surrounded_by_walls.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:52:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/11 20:52:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

static int	all_walls(const char *row);

int	validate_map_surrounded_by_walls(t_map *map)
{
	int	i;

	if (map->grid[0] == NULL || map->grid[map->height - 1] == NULL)
		return (ERROR);
	if (ft_strcmp(map->grid[0], map->grid[map->height - 1]) != 0)
		return (ERROR);
	if (!all_walls(map->grid[0]) || !all_walls(map->grid[map->height - 1]))
		return (ERROR);
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (ERROR);
		i++;
	}
	return (OK);
}

static int	all_walls(const char *row)
{
	while (*row)
	{
		if (*row != WALL)
			return (0);
		row++;
	}
	return (1);
}
