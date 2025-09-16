/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/17 00:14:10 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STATE_H
# define GAME_STATE_H

# include "collectible_model.h"
# include "map.h"
# include "player.h"
# include "renderer.h"
# include "vector2d.h"
# include <stdbool.h>
# include <sys/time.h>

typedef enum e_game_status
{
	GAME_RUNNING = 0,
	GAME_PAUSED = 1,
	GAME_OVER = 2,
	GAME_CLEAR = 3,
	GAME_QUIT = 4
}						t_game_status;

typedef struct s_game_state
{
	t_player			*player;
	t_map				*map;
	t_collectible_model	*collectibles;
	t_mlx_context		*mlx;
	t_renderer			*renderer;
	int					move_count;
	t_game_status		status;
	bool				state_changed;
	struct timeval		last_frame_time;
	float				delta_time;
}						t_game_state;

t_game_state			*init_game_state(void);
void					free_game_state(t_game_state *game);
int						load_game_assets(t_game_state *game,
							const char *map_path);
void					reset_game_state(t_game_state *game);

void					update_game_state(t_game_state *game);
void					mark_state_changed(t_game_state *game);

void					set_game_status(t_game_state *game,
							t_game_status status);
t_game_status			get_game_status(const t_game_state *game);
bool					is_game_running(const t_game_state *game);
bool					is_game_over(const t_game_state *game);
bool					is_game_clear(const t_game_state *game);

void					increment_move_count(t_game_state *game);
int						get_move_count(const t_game_state *game);

void					push_game_clear_event(t_game_state *game);

#endif
