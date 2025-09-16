/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_window_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/17 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "map.h"
#include "vector2d.h"

/**
 * @brief マップサイズに基づいてウィンドウサイズを計算
 * @param map マップモデル
 * @return ウィンドウサイズ（幅と高さ）をt_vector2dで返す
 */
t_vector2d	calculate_window_size(const t_map *map)
{
	t_vector2d	window_size;

	if (!map)
	{
		window_size.x = 0;
		window_size.y = 0;
		return (window_size);
	}
	
	window_size.x = map->width * TILE_SIZE;
	window_size.y = map->height * TILE_SIZE;
	
	return (window_size);
}

/**
 * @brief ウィンドウサイズを直接幅と高さで取得
 * @param map マップモデル
 * @param width 計算された幅を格納するポインタ
 * @param height 計算された高さを格納するポインタ
 * @return 成功時は0、エラー時は-1
 */
int	get_window_dimensions(const t_map *map, int *width, int *height)
{
	if (!map || !width || !height)
		return (-1);
	
	*width = map->width * TILE_SIZE;
	*height = map->height * TILE_SIZE;
	
	return (0);
}

int	is_valid_window_size(const t_map *map)
{
	if (!map)
		return (0);
	if (map->width <= 0 || map->height <= 0)
		return (0);
	if (map->width * TILE_SIZE > 3840 || map->height * TILE_SIZE > 2160)
		return (0);
	if (map->width * TILE_SIZE < TILE_SIZE || map->height * TILE_SIZE < TILE_SIZE)
		return (0);
	return (1);
}
