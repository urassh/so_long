/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/16 23:35:30 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vector2d.h"
# include <stdbool.h>

typedef enum e_player_state
{
	PLAYER_IDLE = 0,
	PLAYER_MOVING = 1,
	PLAYER_DEAD = 2,
	PLAYER_WINNING = 3
}					t_player_state;

typedef struct s_player
{
	t_vector2d		position;
	t_vector2d		previous_position;
	t_player_state	state;
	int				collect_count;
	bool			position_changed;
}					t_player;

void				destroy_player(t_player *player);
void				reset_player(t_player *player, int start_x, int start_y);
void				clear_player_position_changed_flag(t_player *player);

void				set_player_position(t_player *player, int x, int y);
t_vector2d			get_player_position(const t_player *player);

void				set_player_state(t_player *player, t_player_state state);
t_player_state		get_player_state(const t_player *player);

void				increment_collect(t_player *player);
int					get_collect_count(const t_player *player);

#endif
