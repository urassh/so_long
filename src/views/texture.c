/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/16 23:14:27 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "renderer.h"
#include <stdlib.h>

t_texture	*init_texture(void)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->img_ptr = NULL;
	texture->data = NULL;
	texture->width = 0;
	texture->height = 0;
	texture->bits_per_pixel = 0;
	texture->line_length = 0;
	texture->endian = 0;
	return (texture);
}

t_texture	*get_texture_for_tile(t_renderer *r, char tile)
{
	if (tile == WALL)
		return (r->wall_texture);
	else if (tile == EMPTY)
		return (r->empty_texture);
	else if (tile == PLAYER)
		return (r->player_texture);
	else if (tile == COLLECT)
		return (r->collect_texture);
	else if (tile == EXIT)
		return (r->exit_texture);
	return (NULL);
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
	if (renderer->collect_texture)
		free_texture(renderer->mlx->mlx_ptr, renderer->collect_texture);
	if (renderer->exit_texture)
		free_texture(renderer->mlx->mlx_ptr, renderer->exit_texture);
	renderer->wall_texture = NULL;
	renderer->empty_texture = NULL;
	renderer->player_texture = NULL;
	renderer->collect_texture = NULL;
	renderer->exit_texture = NULL;
}

void	free_texture(void *mlx_ptr, t_texture *texture)
{
	if (!texture)
		return ;
	if (texture->img_ptr && mlx_ptr)
		mlx_destroy_image(mlx_ptr, texture->img_ptr);
	free(texture);
}
