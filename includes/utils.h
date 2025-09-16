/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/17 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "map.h"
# include "vector2d.h"

/* ************************************************************************** */
/*                          WINDOW SIZE UTILITIES                           */
/* ************************************************************************** */

t_vector2d	calculate_window_size(const t_map *map);
int			get_window_dimensions(const t_map *map, int *width, int *height);
int			is_valid_window_size(const t_map *map);

/* ************************************************************************** */
/*                          PLAYER UTILITIES                                */
/* ************************************************************************** */

/**
 * @brief マップからプレイヤーの位置を検索
 * @param map マップモデル
 * @param x プレイヤーのx座標を格納するポインタ
 * @param y プレイヤーのy座標を格納するポインタ
 * @return プレイヤーが見つかった場合は1、見つからない場合は0、エラーの場合は-1
 */
int			find_player(const t_map *map, int *x, int *y);

/**
 * @brief マップからプレイヤーの位置をt_vector2dで取得
 * @param map マップモデル
 * @return プレイヤーの位置（見つからない場合は(0,0)）
 */
t_vector2d	find_player_position(const t_map *map);

/**
 * @brief プレイヤーがマップに存在するかチェック
 * @param map マップモデル
 * @return プレイヤーが存在する場合は1、存在しない場合は0
 */
int			has_player(const t_map *map);

#endif
