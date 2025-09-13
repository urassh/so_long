/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_valid_characters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:52:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/11 20:52:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_rule.h"

// 7. map.hに定義されていない文字が含まれていない事
// マップ内の全ての文字が有効（'0', '1', 'C', 'E', 'P'）であることを確認
int	validate_map_valid_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] != EMPTY && map->grid[i][j] != WALL
				&& map->grid[i][j] != COLLECT && map->grid[i][j] != EXIT
				&& map->grid[i][j] != PLAYER)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (OK);
}
