/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_collect_state.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:41:14 by urassh            #+#    #+#             */
/*   Updated: 2025/09/24 22:52:52 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collectible_state.h"
#include "constants.h"
#include "game_state.h"
#include "libft.h"
#include "vector2d.h"

static int				collect_count(t_map *map);
static t_collectible	*set_collect_items(t_map *map);
static void				find_and_set_collectibles(t_map *map,
							t_collectible *items, int count);

t_collectible_state	*create_collect_state(t_map *map)
{
	t_collectible_state	*collect_state;

	collect_state = init_collectible_state();
	if (collect_state == NULL)
		return (NULL);
	collect_state->count = collect_count(map);
	collect_state->items = set_collect_items(map);
	return (collect_state);
}

static int	collect_count(t_map *map)
{
	int	i;
	int	j;
	int	collect_count;

	i = 0;
	collect_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == COLLECT)
				collect_count++;
			j++;
		}
		i++;
	}
	return (collect_count);
}

static t_collectible	*set_collect_items(t_map *map)
{
	t_collectible	*items;
	int				count;

	count = collect_count(map);
	if (count == 0)
		return (NULL);
	items = ft_calloc(count, sizeof(t_collectible));
	if (items == NULL)
		return (NULL);
	find_and_set_collectibles(map, items, count);
	return (items);
}

static void	find_and_set_collectibles(t_map *map, t_collectible *items,
		int count)
{
	int	index;
	int	i;
	int	j;

	index = 0;
	i = 0;
	while (i < map->height && index < count)
	{
		j = 0;
		while (map->grid[i][j] && index < count)
		{
			if (map->grid[i][j] == COLLECT)
			{
				items[index].position = vector2d_create(j, i);
				items[index].is_active = true;
				index++;
			}
			j++;
		}
		i++;
	}
}
