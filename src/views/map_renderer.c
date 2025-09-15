/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/15 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "map.h"
#include "mlx.h"

static t_texture	*get_texture_for_tile(t_renderer *r, char tile)
{
	if (tile == WALL)
		return (r->wall_texture);
	else if (tile == EMPTY)
		return (r->empty_texture);
	else if (tile == PLAYER)
		return (r->player_texture);
	else if (tile == COLLECT)
		return (r->collectible_texture);
	else if (tile == EXIT)
		return (r->exit_texture);
	return (NULL);
}

void	render_tile(t_renderer *r, char tile, int x, int y)
{
	t_texture	*texture;
	
	if (!r || !r->mlx)
		return ;
	
	texture = get_texture_for_tile(r, tile);
	if (texture && texture->img_ptr)
	{
		mlx_put_image_to_window(r->mlx->mlx_ptr, r->mlx->win_ptr,
			texture->img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	}
}

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
			render_tile(renderer, map->grid[y][x], x, y);
			x++;
		}
		y++;
	}
}
