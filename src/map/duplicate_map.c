/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:51:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/13 11:19:30 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	insert_grid(t_map *to_map, t_map *from_map);

t_map	*duplicate_map(t_map *map)
{
	t_map	*new_map;

	if (!map)
		return (NULL);
	new_map = init_map();
	if (!new_map)
		return (NULL);
	new_map->width = map->width;
	new_map->height = map->height;
	new_map->grid = (char **)malloc(sizeof(char *) * (new_map->height + 1));
	if (!new_map->grid)
	{
		free(new_map);
		return (NULL);
	}
	insert_grid(new_map, map);
	return (new_map);
}

static void	insert_grid(t_map *to_map, t_map *from_map)
{
	int	i;

	i = 0;
	while (i < to_map->height)
	{
		to_map->grid[i] = ft_strdup(from_map->grid[i]);
		if (!to_map->grid[i])
		{
			free_map(to_map);
			return ;
		}
		i++;
	}
	to_map->grid[i] = NULL;
}
