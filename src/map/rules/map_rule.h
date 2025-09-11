/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rule.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:52:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/11 20:52:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_RULE_H
# define MAP_RULE_H

# include "../../../includes/map.h"

// バリデーションルール関数の宣言

// 1. 形が正方形である事（矩形である事）
int	validate_map_rectangular(t_map *map);

// 2. 壁で囲まれている事
int	validate_map_surrounded_by_walls(t_map *map);

// 3. Playerの数は1である事
int	validate_map_single_player(t_map *map);

// 4. Exitの数が1である事
int	validate_map_single_exit(t_map *map);

// 5. Collectibleの数が1以上である事
int	validate_map_collectibles_exist(t_map *map);

// 6. 必ず、クリア可能である事
int	validate_map_clearable(t_map *map);

// 7. map.hに定義されていない文字が含まれていない事
int	validate_map_valid_characters(t_map *map);

#endif
