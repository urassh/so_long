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
			"assets/textures/wall.xpm");
	if (!renderer->wall_texture)
		return (print_texture_error("assets/textures/wall.xpm"));
	renderer->empty_texture = load_texture_from_file(renderer->mlx->mlx_ptr,
			"assets/textures/empty.xpm");
	if (!renderer->empty_texture)
		return (print_texture_error("assets/textures/empty.xpm"));
	renderer->player_texture = load_texture_from_file(renderer->mlx->mlx_ptr,
			"assets/textures/player.xpm");
	if (!renderer->player_texture)
		return (print_texture_error("assets/textures/player.xpm"));
	renderer->collect_texture = load_texture_from_file(renderer->mlx->mlx_ptr,
			"assets/textures/collect.xpm");
	if (!renderer->collect_texture)
		return (print_texture_error("assets/textures/collect.xpm"));
	renderer->exit_texture = load_texture_from_file(renderer->mlx->mlx_ptr,
			"assets/textures/exit.xpm");
	if (!renderer->exit_texture)
		return (print_texture_error("assets/textures/exit.xpm"));
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
