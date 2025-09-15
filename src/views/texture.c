/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
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

t_texture	*load_texture_from_file(void *mlx_ptr, const char *file_path)
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

void	free_texture(void *mlx_ptr, t_texture *texture)
{
	if (!texture)
		return ;
	if (texture->img_ptr && mlx_ptr)
		mlx_destroy_image(mlx_ptr, texture->img_ptr);
	free(texture);
}

int	is_texture_valid(t_texture *texture)
{
	if (!texture)
		return (0);
	if (!texture->img_ptr)
		return (0);
	if (texture->width <= 0 || texture->height <= 0)
		return (0);
	return (1);
}

void	draw_texture_at(t_renderer *r, t_texture *tex, t_vector2d pos)
{
	if (!r || !tex || !tex->img_ptr)
		return ;
	mlx_put_image_to_window(r->mlx->mlx_ptr, r->mlx->win_ptr,
		tex->img_ptr, pos.x, pos.y);
}
