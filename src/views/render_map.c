/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/16 23:19:42 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "mlx.h"
#include "renderer.h"

void	render_map(t_renderer *renderer, t_map *map)
{
	int	x;
	int	y;

	if (!renderer || !map || !map->grid)
		return ;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width && map->grid[y][x])
		{
			if (map->grid[y][x] == PLAYER)
				render_tile(renderer, EMPTY, x, y);
			else if (map->grid[y][x] == COLLECT)
				render_tile(renderer, EMPTY, x, y);
			else if (map->grid[y][x] == EXIT)
				render_tile(renderer, EMPTY, x, y);
			else
				render_tile(renderer, map->grid[y][x], x, y);
			x++;
		}
		y++;
	}
}
