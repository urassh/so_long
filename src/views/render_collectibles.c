/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_collectibles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 23:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/24 23:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collectible_state.h"
#include "constants.h"
#include "mlx.h"
#include "renderer.h"

static void	render_collectible(t_renderer *renderer, t_collectible *collectible)
{
	if (!renderer || !collectible)
		return ;
	if (!renderer->collect_texture || !renderer->collect_texture->img_ptr)
		return ;
	if (!collectible->is_active)
		return ;
	mlx_put_image_to_window(renderer->mlx->mlx_ptr,
		renderer->mlx->win_ptr,
		renderer->collect_texture->img_ptr,
		collectible->position.x * TILE_SIZE,
		collectible->position.y * TILE_SIZE);
}

void	render_collectibles(t_renderer *renderer, t_collectible_state *state)
{
	int	i;

	if (!renderer || !state || !state->items)
		return ;
	i = 0;
	while (i < state->count)
	{
		render_collectible(renderer, &state->items[i]);
		i++;
	}
}
