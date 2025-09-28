/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_clearable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:52:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/11 20:52:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

static void	find_player_position(t_map *map, int *player_x, int *player_y);
static void	flood_fill(t_map *map, int x, int y);
static int	check_collectibles_and_exit(t_map *original_map, t_map *filled_map);
static int	error_clearable(void);

int	validate_map_clearable(t_map *map)
{
	t_map	*duplicate;
	int		player_x;
	int		player_y;
	int		result;

	duplicate = duplicate_map(map);
	if (!duplicate)
		return (error_clearable());
	find_player_position(map, &player_x, &player_y);
	if (player_x == -1 || player_y == -1)
	{
		free_map(duplicate);
		return (error_clearable());
	}
	flood_fill(duplicate, player_x, player_y);
	result = check_collectibles_and_exit(map, duplicate);
	if (result == ERROR)
		return (error_clearable());
	free_map(duplicate);
	return (result);
}

static void	find_player_position(t_map *map, int *player_x, int *player_y)
{
	int	x;
	int	y;

	*player_x = -1;
	*player_y = -1;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == PLAYER)
			{
				*player_x = x;
				*player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (map->grid[y][x] == WALL || map->grid[y][x] == 'F')
		return ;
	map->grid[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static int	check_collectibles_and_exit(t_map *original_map, t_map *filled_map)
{
	int	x;
	int	y;

	y = 0;
	while (y < original_map->height)
	{
		x = 0;
		while (x < original_map->width)
		{
			if (original_map->grid[y][x] == COLLECT
				|| original_map->grid[y][x] == EXIT)
				if (filled_map->grid[y][x] != 'F')
					return (ERROR);
			x++;
		}
		y++;
	}
	return (OK);
}

static int	error_clearable(void)
{
	ft_putstr("ERROR: map data should be clearable game\n");
	return (ERROR);
}
