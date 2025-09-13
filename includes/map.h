/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:35:52 by surayama          #+#    #+#             */
/*   Updated: 2025/09/13 10:50:51 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>

# define EMPTY '0'
# define WALL '1'
# define COLLECT 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define OK 0
# define ERROR 1

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}			t_map;

t_map		*init_map(void);
t_map		*load_map(const char *path);
t_map		*duplicate_map(t_map *map);
int			validate_map(t_map *map);
void		free_map(t_map *map);

#endif
