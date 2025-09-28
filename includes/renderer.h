/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/28 10:30:38 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "collectible_state.h"
# include "constants.h"
# include "game_state.h"
# include "map.h"
# include "player.h"
# include "vector2d.h"
# define WALL_TEXTURE_PATH "assets/textures/wall.xpm"
# define EMPTY_TEXTURE_PATH "assets/textures/empty.xpm"
# define PLAYER_TEXTURE_PATH "assets/textures/player.xpm"
# define COLLECT_TEXTURE_PATH "assets/textures/collect.xpm"
# define EXIT_TEXTURE_PATH "assets/textures/exit.xpm"

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
void				render_map(t_renderer *renderer, t_map *map);
void				render_player(t_renderer *renderer, t_player *player);
void				render_collectibles(t_renderer *renderer,
						t_collectible_state *state);
void				render_exit(t_renderer *renderer, t_map *map);
t_texture			*get_texture_for_tile(t_renderer *r, char tile);
void				render_game(t_game_state *game);
t_texture			*init_texture(void);

#endif
