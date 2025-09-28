/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/16 23:14:29 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "renderer.h"
#include "libft.h"
#include <stdlib.h>

static int			load_all_texture_files(t_renderer *renderer);
static t_texture	*load_texture_from_file(void *mlx_ptr,
						const char *file_path);
static int			allocate_textures(t_renderer *renderer);
static int			print_texture_error(const char *file_path);

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

static int	allocate_textures(t_renderer *renderer)
{
	renderer->wall_texture = NULL;
	renderer->empty_texture = NULL;
	renderer->player_texture = NULL;
	renderer->collect_texture = NULL;
	renderer->exit_texture = NULL;
	return (OK);
}

static int	load_all_texture_files(t_renderer *renderer)
{
	renderer->wall_texture = load_texture_from_file(renderer->mlx->mlx_ptr,
			WALL_TEXTURE_PATH);
	if (!renderer->wall_texture)
		return (print_texture_error(WALL_TEXTURE_PATH));
	renderer->empty_texture = load_texture_from_file(renderer->mlx->mlx_ptr,
			EMPTY_TEXTURE_PATH);
	if (!renderer->empty_texture)
		return (print_texture_error(EMPTY_TEXTURE_PATH));
	renderer->player_texture = load_texture_from_file(renderer->mlx->mlx_ptr,
			PLAYER_TEXTURE_PATH);
	if (!renderer->player_texture)
		return (print_texture_error(PLAYER_TEXTURE_PATH));
	renderer->collect_texture = load_texture_from_file(renderer->mlx->mlx_ptr,
			COLLECT_TEXTURE_PATH);
	if (!renderer->collect_texture)
		return (print_texture_error(COLLECT_TEXTURE_PATH));
	renderer->exit_texture = load_texture_from_file(renderer->mlx->mlx_ptr,
			EXIT_TEXTURE_PATH);
	if (!renderer->exit_texture)
		return (print_texture_error(EXIT_TEXTURE_PATH));
	return (OK);
}

static t_texture	*load_texture_from_file(void *mlx_ptr,
		const char *file_path)
{
	t_texture	*texture;

	if (!mlx_ptr || !file_path)
		return (NULL);
	texture = init_texture();
	if (!texture)
		return (NULL);
	texture->img_ptr = mlx_xpm_file_to_image(mlx_ptr, (char *)file_path,
			&texture->width, &texture->height);
	if (!texture->img_ptr)
	{
		free_texture(mlx_ptr, texture);
		return (NULL);
	}
	texture->data = mlx_get_data_addr(texture->img_ptr,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	return (texture);
}

static int	print_texture_error(const char *file_path)
{
	ft_putstr("Error: Failed to load texture file: ");
	ft_putstr(file_path);
	ft_putstr("\n");
	return (ERROR);
}
