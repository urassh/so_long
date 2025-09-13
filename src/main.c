/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:34:00 by surayama          #+#    #+#             */
/*   Updated: 2025/09/11 18:41:48 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"
#include <stdio.h>

void	test_map_validation(const char *map_path, const char *test_name)
{
	t_map	*map;
	int		result;

	printf("Testing: %s\n", test_name);
	printf("Map file: %s\n", map_path);
	
	map = load_map(map_path);
	if (!map)
	{
		printf("Result: FAILED (Could not load map)\n");
		printf("----------------------------------------\n\n");
		return;
	}
	
	result = validate_map(map);
	if (result == OK)
		printf("Result: VALID\n");
	else
		printf("Result: INVALID\n");
	
	free_map(map);
	printf("----------------------------------------\n\n");
}

int	main(void)
{
	printf("=== SO_LONG MAP VALIDATION TESTS ===\n\n");
	
	// 有効なマップのテスト
	test_map_validation("assets/map/test_valid", "Valid Map Test");
	
	// 無効なマップのテスト
	test_map_validation("assets/map/test_multiple_players", "Multiple Players Test (should be INVALID)");
	test_map_validation("assets/map/test_multiple_exits", "Multiple Exits Test (should be INVALID)");
	test_map_validation("assets/map/test_no_collectibles", "No Collectibles Test (should be INVALID)");
	test_map_validation("assets/map/test_not_surrounded", "Not Surrounded by Walls Test (should be INVALID)");
	test_map_validation("assets/map/test_not_rectangular", "Not Rectangular Test (should be INVALID)");
	test_map_validation("assets/map/test_invalid_character", "Invalid Character Test (should be INVALID)");
	test_map_validation("assets/map/test_not_clearable", "Not Clearable Test (should be INVALID)");
	
	// 元のマップも追加でテスト
	test_map_validation("assets/map/map", "Original Map Test");
	
	printf("=== ALL TESTS COMPLETED ===\n");
	return (0);
}
