/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:46:31 by urassh            #+#    #+#             */
/*   Updated: 2025/09/13 09:53:40 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "rules/map_rule.h"

// マップのバリデーションルール
// 1. 形が長方形である事。
// 2. 壁で囲まれている事。
// 3. Playerの数は1である事。
// 4. Exitの数が1である事。
// 5. Collectibleの数が1以上である事。
// 6. 必ず、クリア可能である事。
// 7. map.hに定義されていない文字が含まれていない事。
int	validate_map(t_map *map)
{
	if (!map)
		return (ERROR);
	if (validate_map_rectangular(map) != OK)
		return (ERROR);
	if (validate_map_surrounded_by_walls(map) != OK)
		return (ERROR);
	if (validate_map_single_player(map) != OK)
		return (ERROR);
	if (validate_map_single_exit(map) != OK)
		return (ERROR);
	if (validate_map_collectibles_exist(map) != OK)
		return (ERROR);
	if (validate_map_valid_characters(map) != OK)
		return (ERROR);
	if (validate_map_clearable(map) != OK)
		return (ERROR);
	return (OK);
}
