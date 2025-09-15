/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/15 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "mlx.h"
#include <stdlib.h>

t_renderer	*init_renderer(t_mlx_context *mlx)
{
	t_renderer	*renderer;

	if (!mlx)
		return (NULL);
	renderer = malloc(sizeof(t_renderer));
	if (!renderer)
		return (NULL);
	renderer->mlx = mlx;
	renderer->wall_texture = NULL;
	renderer->empty_texture = NULL;
	renderer->player_texture = NULL;
	renderer->collectible_texture = NULL;
	renderer->exit_texture = NULL;
	return (renderer);
}

void	free_renderer(t_renderer *renderer)
{
	if (!renderer)
		return ;
	free(renderer);
}

void	render_tile(t_renderer *r, char tile, int x, int y)
{
	if (!r || !r->mlx)
		return ;
	(void)tile;
	(void)x;
	(void)y;
}

void	draw_texture_at(t_renderer *r, t_texture *tex, t_vector2d pos)
{
	if (!r || !tex)
		return ;
	(void)pos;
}
