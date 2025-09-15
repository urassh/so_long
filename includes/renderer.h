/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/15 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "vector2d.h"
# include "constants.h"

struct s_map;

typedef struct s_mlx_context
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
}			t_mlx_context;

typedef struct s_texture
{
	void	*img_ptr;
	char	*data;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_texture;

typedef struct s_renderer
{
	t_mlx_context	*mlx;
	t_texture		*wall_texture;
	t_texture		*empty_texture;
	t_texture		*player_texture;
	t_texture		*collectible_texture;
	t_texture		*exit_texture;
}					t_renderer;

t_renderer	*init_renderer(t_mlx_context *mlx);
void		free_renderer(t_renderer *renderer);
int			load_textures(t_renderer *renderer);
void		free_textures(t_renderer *renderer);
void		clear_screen(t_renderer *renderer);
void		present_screen(t_renderer *renderer);

void		render_tile(t_renderer *r, char tile, int x, int y);
void		draw_texture_at(t_renderer *r, t_texture *tex, t_vector2d pos);
void		render_map(t_renderer *renderer, struct s_map *map);
void		render_game(t_game_state *game);

t_texture	*init_texture(void);
t_texture	*load_texture_from_file(void *mlx_ptr, const char *file_path);
void		free_texture(void *mlx_ptr, t_texture *texture);
int			is_texture_valid(t_texture *texture);

#endif
