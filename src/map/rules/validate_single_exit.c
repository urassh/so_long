/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_single_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:52:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/11 20:52:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_rule.h"

int	validate_map_single_exit(t_map *map)
{
	int	i;
	int	exit_count;

	i = 0;
	exit_count = 0;
	while (i < map->height)
	{
		if (ft_strchr(map->grid[i], EXIT) != NULL)
			exit_count += 1;
		i++;
	}
	if (exit_count == 1)
		return (OK);
	return (ERROR);
}
