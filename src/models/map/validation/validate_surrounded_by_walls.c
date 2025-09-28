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
static int	error_surrounded_by_walls(void);

int	validate_map_surrounded_by_walls(t_map *map)
{
	int	i;

	if (map->grid[0] == NULL || map->grid[map->height - 1] == NULL)
		return (error_surrounded_by_walls());
	if (ft_strcmp(map->grid[0], map->grid[map->height - 1]) != 0)
		return (error_surrounded_by_walls());
	if (!all_walls(map->grid[0]) || !all_walls(map->grid[map->height - 1]))
		return (error_surrounded_by_walls());
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (error_surrounded_by_walls());
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

static int	error_surrounded_by_walls(void)
{
	ft_putstr("Error: map data should be surrounded by walls\n");
	return (ERROR);
}
