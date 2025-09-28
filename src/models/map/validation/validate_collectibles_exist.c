/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_collectibles_exist.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:52:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/11 20:52:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

int	validate_map_collectibles_exist(t_map *map)
{
	int	i;
	int	collectible_count;

	i = 0;
	collectible_count = 0;
	while (i < map->height)
	{
		if (ft_strchr(map->grid[i], COLLECT) != NULL)
			collectible_count += 1;
		i++;
	}
	if (collectible_count >= 1)
		return (OK);
	ft_putstr("Error: map data should be exists collectibles\n");
	return (ERROR);
}
