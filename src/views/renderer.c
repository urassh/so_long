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
#include "game_state.h"
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
	free_textures(renderer);
	free(renderer);
}

void render_game(t_game_state *game) {
    clear_screen(game->renderer);
    render_map(game->renderer, game->map);
    present_screen(game->renderer);
}
