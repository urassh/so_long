/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/15 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

# include "../../../../includes/map.h"
# include "../../../../includes/libft.h"

int	validate_map_rectangular(t_map *map);
int	validate_map_surrounded_by_walls(t_map *map);
int	validate_map_single_player(t_map *map);
int	validate_map_single_exit(t_map *map);
int	validate_map_collectibles_exist(t_map *map);
int	validate_map_clearable(t_map *map);
int	validate_map_valid_characters(t_map *map);

#endif
