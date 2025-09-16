/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/17 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"
#include "mlx.h"
#include "player.h"
#include "renderer.h"

void	render_player(t_renderer *renderer, t_player *player)
{
	t_vector2d	pos;

	if (!renderer || !player)
		return ;
	if (!renderer->player_texture || !renderer->player_texture->img_ptr)
		return ;
	pos = get_player_position(player);
	mlx_put_image_to_window(renderer->mlx->mlx_ptr,
		renderer->mlx->win_ptr,
		renderer->player_texture->img_ptr,
		pos.x * TILE_SIZE,
		pos.y * TILE_SIZE);
}
