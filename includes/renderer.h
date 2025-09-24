/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/16 23:14:27 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "constants.h"
# include "vector2d.h"

struct s_map;
struct s_game_state;
struct s_player;
struct s_collectible_state;

typedef struct s_mlx_context
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
}					t_mlx_context;

typedef struct s_texture
{
	void			*img_ptr;
	char			*data;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_texture;

typedef struct s_renderer
{
	t_mlx_context	*mlx;
	t_texture		*wall_texture;
	t_texture		*empty_texture;
	t_texture		*player_texture;
	t_texture		*collect_texture;
	t_texture		*exit_texture;
}					t_renderer;

t_renderer			*init_renderer(t_mlx_context *mlx);
void				free_renderer(t_renderer *renderer);
int					load_textures(t_renderer *renderer);
void				free_textures(t_renderer *renderer);
void				free_texture(void *mlx_ptr, t_texture *texture);
void				clear_screen(t_renderer *renderer);
void				present_screen(t_renderer *renderer);

void				render_tile(t_renderer *r, char tile, int x, int y);
void				render_map(t_renderer *renderer, struct s_map *map);
void				render_player(t_renderer *renderer, struct s_player *player);
void				render_collectibles(t_renderer *renderer,
						struct s_collectible_state *state);
void				render_exit(t_renderer *renderer, struct s_map *map);
t_texture			*get_texture_for_tile(t_renderer *r, char tile);
void				render_game(struct s_game_state *game);

t_texture			*init_texture(void);

#endif
