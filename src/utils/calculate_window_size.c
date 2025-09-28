/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_window_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/18 22:51:30 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "map.h"
#include "vector2d.h"

t_vector2d	calculate_window_size(const t_map *map)
{
	t_vector2d	window_size;

	if (!map)
	{
		window_size.x = 0;
		window_size.y = 0;
		return (window_size);
	}
	window_size.x = map->width * TILE_SIZE;
	window_size.y = map->height * TILE_SIZE;
	return (window_size);
}

int	get_window_dimensions(const t_map *map, int *width, int *height)
{
	if (!map || !width || !height)
		return (ERROR);
	*width = map->width * TILE_SIZE;
	*height = map->height * TILE_SIZE;
	return (OK);
}

int	is_valid_window_size(const t_map *map)
{
	if (!map)
		return (0);
	if (map->width <= 0 || map->height <= 0)
		return (0);
	if (map->width * TILE_SIZE > 3840 || map->height * TILE_SIZE > 2160)
		return (0);
	if (map->width * TILE_SIZE < TILE_SIZE || map->height
		* TILE_SIZE < TILE_SIZE)
		return (0);
	return (1);
}
