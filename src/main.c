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

int	main(void)
{
	t_map	*map;
	int		i;

	printf("Testing load_map function with assets/map/map:\n");
	printf("===============================================\n");
	
	map = load_map("assets/map/map");
	if (!map)
	{
		printf("Error: Failed to load map from 'assets/map/map'\n");
		return (1);
	}
	
	printf("Map loaded successfully!\n");
	printf("Width: %d\n", map->width);
	printf("Height: %d\n", map->height);
	printf("\nMap grid:\n");
	printf("---------\n");
	
	i = 0;
	while (i < map->height)
	{
		printf("Row %d: %s\n", i, map->grid[i]);
		i++;
	}
	
	printf("===============================================\n");
	printf("Map test completed successfully.\n");
	
	free_map(map);
	return (0);
}
