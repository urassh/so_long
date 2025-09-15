/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
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

static int	allocate_textures(t_renderer *renderer)
{
	renderer->wall_texture = NULL;
	renderer->empty_texture = NULL;
	renderer->player_texture = NULL;
	renderer->collectible_texture = NULL;
	renderer->exit_texture = NULL;
	return (OK);
}

static int	load_all_texture_files(t_renderer *renderer)
{
	renderer->wall_texture = load_texture_from_file(
		renderer->mlx->mlx_ptr, "assets/textures/wall.xpm");
	renderer->empty_texture = load_texture_from_file(
		renderer->mlx->mlx_ptr, "assets/textures/empty.xpm");
	renderer->player_texture = load_texture_from_file(
		renderer->mlx->mlx_ptr, "assets/textures/player.xpm");
	renderer->collectible_texture = load_texture_from_file(
		renderer->mlx->mlx_ptr, "assets/textures/collect.xpm");
	renderer->exit_texture = load_texture_from_file(
		renderer->mlx->mlx_ptr, "assets/textures/exit.xpm");

	if (!renderer->wall_texture || !renderer->empty_texture ||
		!renderer->player_texture || !renderer->collectible_texture ||
		!renderer->exit_texture)
		return (ERROR);
	return (OK);
}

int	load_textures(t_renderer *renderer)
{
	if (!renderer || !renderer->mlx)
		return (ERROR);
	if (allocate_textures(renderer) != OK)
		return (ERROR);
	if (load_all_texture_files(renderer) != OK)
	{
		free_textures(renderer);
		return (ERROR);
	}
	return (OK);
}

void	free_textures(t_renderer *renderer)
{
	if (!renderer)
		return ;
	if (renderer->wall_texture)
		free_texture(renderer->mlx->mlx_ptr, renderer->wall_texture);
	if (renderer->empty_texture)
		free_texture(renderer->mlx->mlx_ptr, renderer->empty_texture);
	if (renderer->player_texture)
		free_texture(renderer->mlx->mlx_ptr, renderer->player_texture);
	if (renderer->collectible_texture)
		free_texture(renderer->mlx->mlx_ptr, renderer->collectible_texture);
	if (renderer->exit_texture)
		free_texture(renderer->mlx->mlx_ptr, renderer->exit_texture);
    renderer->wall_texture = NULL;
    renderer->empty_texture = NULL;
    renderer->player_texture = NULL;
    renderer->collectible_texture = NULL;
    renderer->exit_texture = NULL;
}
