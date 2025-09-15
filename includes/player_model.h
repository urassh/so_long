/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_model.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/15 20:10:09 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_MODEL_H
# define PLAYER_MODEL_H

# include <stdbool.h>
# include "vector2d.h"

typedef enum e_direction
{
	DIR_NONE = 0,
	DIR_UP = 1,
	DIR_DOWN = 2,
	DIR_LEFT = 3,
	DIR_RIGHT = 4
}					t_direction;

typedef enum e_player_state
{
	PLAYER_IDLE = 0,
	PLAYER_MOVING = 1,
	PLAYER_DEAD = 2,
	PLAYER_WINNING = 3
}					t_player_state;

typedef struct s_player_model
{
	t_vector2d		position;
	t_vector2d		previous_position;
	t_direction		facing_direction;
	t_player_state	state;
	int				health;
	int				score;
	int				collectibles_count;
	bool			position_changed;
	float			animation_time;
}					t_player_model;

/* プレイヤーモデル管理 */
t_player_model		*create_player_model(int start_x, int start_y);
void				destroy_player_model(t_player_model *player);
void				reset_player_model(t_player_model *player, int start_x,
						int start_y);

/* 位置管理 */
void				set_player_position(t_player_model *player, int x, int y);
t_vector2d			get_player_position(const t_player_model *player);
bool				is_player_at_position(const t_player_model *player, int x,
						int y);

/* 状態管理 */
void				set_player_state(t_player_model *player,
						t_player_state state);
t_player_state		get_player_state(const t_player_model *player);
void				set_player_direction(t_player_model *player,
						t_direction direction);
t_direction			get_player_direction(const t_player_model *player);

/* スコア・統計管理 */
void				add_player_score(t_player_model *player, int points);
int					get_player_score(const t_player_model *player);
void				increment_collectibles(t_player_model *player);
int					get_collectibles_count(const t_player_model *player);

/* アニメーション・更新 */
void				update_player_animation(t_player_model *player,
						float delta_time);
bool				is_player_position_changed(const t_player_model *player);
void				clear_player_position_changed_flag(t_player_model *player);

/* ユーティリティ */
t_vector2d			direction_to_vector(t_direction direction);
t_direction			vector_to_direction(const t_vector2d *vector);

#endif
