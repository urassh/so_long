/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:15:54 by urassh            #+#    #+#             */
/*   Updated: 2025/09/11 17:18:41 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_map(t_map *map)
{
	int	i;

	if (map == NULL)
		return ;
	if (map->grid != NULL)
	{
		i = 0;
		while (i < map->height && map->grid[i] != NULL)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
}
