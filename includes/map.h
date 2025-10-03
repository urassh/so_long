/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:35:52 by surayama          #+#    #+#             */
/*   Updated: 2025/10/03 12:00:01 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "constants.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}			t_map;

t_map		*init_map(void);
t_map		*load_map(const char *path);
t_map		*duplicate_map(t_map *map);
int			validate_map(t_map *map, const char *path);
void		free_map(t_map *map);

# define MAX_WIDTH 100
# define MAX_HEIGHT 100

#endif
