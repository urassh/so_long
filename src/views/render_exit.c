/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 23:15:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/24 23:15:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "map.h"
#include "mlx.h"
#include "renderer.h"
#include "utils.h"

void	render_exit(t_renderer *renderer, t_map *map)
{
	t_vector2d	pos;

	if (!renderer || !map)
		return ;
	if (!renderer->exit_texture || !renderer->exit_texture->img_ptr)
		return ;
	pos = find_exit_position(map);
	mlx_put_image_to_window(renderer->mlx->mlx_ptr,
		renderer->mlx->win_ptr,
		renderer->exit_texture->img_ptr,
		pos.x * TILE_SIZE,
		pos.y * TILE_SIZE);
}
