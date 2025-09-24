/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/16 23:14:27 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collectible_state.h"
#include "game_state.h"
#include "mlx.h"
#include "renderer.h"
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
	renderer->collect_texture = NULL;
	renderer->exit_texture = NULL;
	return (renderer);
}

void	free_renderer(t_renderer *renderer)
{
	if (!renderer)
		return ;
	free_textures(renderer);
	free(renderer);
}

void	render_game(t_game_state *game)
{
	clear_screen(game->renderer);
	render_map(game->renderer, game->map);
	render_collectibles(game->renderer, game->collectibles);
	render_player(game->renderer, game->player);
	present_screen(game->renderer);
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
