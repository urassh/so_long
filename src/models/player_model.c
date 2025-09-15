/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_model.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/15 16:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "player_model.h"

/* ************************************************************************** */
/*                           PLAYER MODEL MANAGEMENT                         */
/* ************************************************************************** */

/**
 * プレイヤーモデルを作成・初期化する
 * @param start_x 開始X座標
 * @param start_y 開始Y座標
 * @return 初期化されたプレイヤーモデル
 */
t_player_model	*create_player_model(int start_x, int start_y)
{
	t_player_model	*player;

	player = (t_player_model *)malloc(sizeof(t_player_model));
	if (!player)
		return (NULL);
	
	reset_player_model(player, start_x, start_y);
	return (player);
}

/**
 * プレイヤーモデルを破棄する
 * @param player プレイヤーモデル
 */
void	destroy_player_model(t_player_model *player)
{
	if (player)
		free(player);
}

void	reset_player_model(t_player_model *player, int start_x, int start_y)
{
	if (!player)
		return ;
	
	player->position.x = start_x;
	player->position.y = start_y;
	player->previous_position.x = start_x;
	player->previous_position.y = start_y;
	player->facing_direction = DIR_DOWN;
	player->state = PLAYER_IDLE;
	player->health = 100;
	player->score = 0;
	player->collectibles_count = 0;
	player->position_changed = false;
	player->animation_time = 0.0f;
}

/* ************************************************************************** */
/*                              POSITION MANAGEMENT                          */
/* ************************************************************************** */

/**
 * プレイヤーの位置を設定する
 * @param player プレイヤーモデル
 * @param x X座標
 * @param y Y座標
 */
void	set_player_position(t_player_model *player, int x, int y)
{
	if (!player)
		return ;
	
	player->previous_position = player->position;
	player->position.x = x;
	player->position.y = y;
	player->position_changed = true;
	player->animation_time = 0.0f;
}

/**
 * プレイヤーの現在位置を取得する
 * @param player プレイヤーモデル
 * @return 現在位置
 */
t_vector2d	get_player_position(const t_player_model *player)
{
	t_vector2d	empty_pos = {0, 0};
	
	if (!player)
		return (empty_pos);
	return (player->position);
}

/**
 * プレイヤーが指定位置にいるかチェックする
 * @param player プレイヤーモデル
 * @param x X座標
 * @param y Y座標
 * @return true if プレイヤーが指定位置にいる
 */
bool	is_player_at_position(const t_player_model *player, int x, int y)
{
	if (!player)
		return (false);
	return (player->position.x == x && player->position.y == y);
}

/* ************************************************************************** */
/*                              STATE MANAGEMENT                             */
/* ************************************************************************** */

/**
 * プレイヤーの状態を設定する
 * @param player プレイヤーモデル
 * @param state 新しい状態
 */
void	set_player_state(t_player_model *player, t_player_state state)
{
	if (!player)
		return ;
	player->state = state;
}

/**
 * プレイヤーの現在状態を取得する
 * @param player プレイヤーモデル
 * @return 現在の状態
 */
t_player_state	get_player_state(const t_player_model *player)
{
	if (!player)
		return (PLAYER_DEAD);
	return (player->state);
}

/**
 * プレイヤーの向きを設定する
 * @param player プレイヤーモデル
 * @param direction 新しい向き
 */
void	set_player_direction(t_player_model *player, t_direction direction)
{
	if (!player)
		return ;
	player->facing_direction = direction;
}

/**
 * プレイヤーの現在の向きを取得する
 * @param player プレイヤーモデル
 * @return 現在の向き
 */
t_direction	get_player_direction(const t_player_model *player)
{
	if (!player)
		return (DIR_NONE);
	return (player->facing_direction);
}

/* ************************************************************************** */
/*                            SCORE & STATISTICS                             */
/* ************************************************************************** */

/**
 * プレイヤーのスコアを加算する
 * @param player プレイヤーモデル
 * @param points 加算するポイント
 */
void	add_player_score(t_player_model *player, int points)
{
	if (!player)
		return ;
	player->score += points;
}

/**
 * プレイヤーの現在スコアを取得する
 * @param player プレイヤーモデル
 * @return 現在のスコア
 */
int	get_player_score(const t_player_model *player)
{
	if (!player)
		return (0);
	return (player->score);
}

/**
 * コレクタブル取得数を増加させる
 * @param player プレイヤーモデル
 */
void	increment_collectibles(t_player_model *player)
{
	if (!player)
		return ;
	player->collectibles_count++;
}

/**
 * コレクタブル取得数を取得する
 * @param player プレイヤーモデル
 * @return コレクタブル取得数
 */
int	get_collectibles_count(const t_player_model *player)
{
	if (!player)
		return (0);
	return (player->collectibles_count);
}

/* ************************************************************************** */
/*                          ANIMATION & UPDATE                               */
/* ************************************************************************** */

/**
 * プレイヤーのアニメーション状態を更新する
 * @param player プレイヤーモデル
 * @param delta_time フレーム間の経過時間
 */
void	update_player_animation(t_player_model *player, float delta_time)
{
	if (!player)
		return ;
	
	player->animation_time += delta_time;
	
	// アニメーション完了チェック
	if (player->animation_time > 0.3f && player->state == PLAYER_MOVING)
	{
		player->state = PLAYER_IDLE;
		player->animation_time = 0.0f;
	}
}

/**
 * プレイヤーの位置が変更されたかチェックする
 * @param player プレイヤーモデル
 * @return true if 位置が変更された
 */
bool	is_player_position_changed(const t_player_model *player)
{
	if (!player)
		return (false);
	return (player->position_changed);
}

/**
 * 位置変更フラグをクリアする（描画完了後に呼ぶ）
 * @param player プレイヤーモデル
 */
void	clear_player_position_changed_flag(t_player_model *player)
{
	if (!player)
		return ;
	player->position_changed = false;
}

/* ************************************************************************** */
/*                               UTILITIES                                   */
/* ************************************************************************** */

/**
 * 方向をベクトルに変換する
 * @param direction 方向
 * @return 対応するベクトル
 */
t_vector2d	direction_to_vector(t_direction direction)
{
	t_vector2d	vector = {0, 0};
	
	if (direction == DIR_UP)
		vector.y = -1;
	else if (direction == DIR_DOWN)
		vector.y = 1;
	else if (direction == DIR_LEFT)
		vector.x = -1;
	else if (direction == DIR_RIGHT)
		vector.x = 1;
	
	return (vector);
}

/**
 * ベクトルを方向に変換する
 * @param vector ベクトル
 * @return 対応する方向
 */
t_direction	vector_to_direction(const t_vector2d *vector)
{
	if (!vector)
		return (DIR_NONE);
	
	if (vector->x == 0 && vector->y == -1)
		return (DIR_UP);
	else if (vector->x == 0 && vector->y == 1)
		return (DIR_DOWN);
	else if (vector->x == -1 && vector->y == 0)
		return (DIR_LEFT);
	else if (vector->x == 1 && vector->y == 0)
		return (DIR_RIGHT);
	
	return (DIR_NONE);
}
