/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/15 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "validation/map_validation.h"

int	validate_map(t_map *map)
{
	if (!map)
		return (ERROR);
	if (validate_map_rectangular(map) != OK)
		return (ERROR);
	if (validate_map_surrounded_by_walls(map) != OK)
		return (ERROR);
	if (validate_map_single_player(map) != OK)
		return (ERROR);
	if (validate_map_single_exit(map) != OK)
		return (ERROR);
	if (validate_map_collectibles_exist(map) != OK)
		return (ERROR);
	if (validate_map_valid_characters(map) != OK)
		return (ERROR);
	if (validate_map_clearable(map) != OK)
		return (ERROR);
	return (OK);
}
