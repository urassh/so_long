/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/18 23:10:24 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "map.h"
#include "vector2d.h"

static int	find_tile(const t_map *map, int *x, int *y, char tile);

int	find_player(const t_map *map, int *x, int *y)
{
	return (find_tile(map, x, y, PLAYER));
}

int	find_exit(const t_map *map, int *x, int *y)
{
	return (find_tile(map, x, y, EXIT));
}

static int	find_tile(const t_map *map, int *x, int *y, char tile)
{
	int	map_x;
	int	map_y;

	if (!map || !x || !y)
		return (ERROR);
	*x = 0;
	*y = 0;
	map_y = 0;
	while (map_y < map->height)
	{
		map_x = 0;
		while (map_x < map->width)
		{
			if (map->grid[map_y][map_x] == tile)
			{
				*x = map_x;
				*y = map_y;
				return (OK);
			}
			map_x++;
		}
		map_y++;
	}
	return (ERROR);
}

t_vector2d	find_player_position(const t_map *map)
{
	t_vector2d	position;
	int			x;
	int			y;

	position.x = 0;
	position.y = 0;
	if (find_player(map, &x, &y) == 1)
	{
		position.x = x;
		position.y = y;
	}
	return (position);
}

t_vector2d	find_exit_position(const t_map *map)
{
	t_vector2d	position;
	int			x;
	int			y;

	position.x = 0;
	position.y = 0;
	if (find_exit(map, &x, &y) == OK)
	{
		position.x = x;
		position.y = y;
	}
	return (position);
}
