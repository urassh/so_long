/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_single_player.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:52:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/11 20:52:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_rule.h"

int	validate_map_single_player(t_map *map)
{
	int	i;
	int	player_count;

	i = 0;
	player_count = 0;
	while (i < map->height)
	{
		if (ft_strchr(map->grid[i], 'P') != NULL)
			player_count += 1;
		i++;
	}
	if (player_count == 1)
		return (OK);
	return (ERROR);
}
