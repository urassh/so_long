/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/27 19:01:53 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"

static int	get_map_line_count(const char *path);
static char	**allocate_and_load_grid(const char *path, int line_count);
static char	**load_grid(int fd, char **grid, int line_count);

t_map	*load_map(const char *path)
{
	t_map	*map;
	char	**grid;
	int		line_count;

	line_count = get_map_line_count(path);
	if (line_count <= 0)
		return (NULL);
	grid = allocate_and_load_grid(path, line_count);
	if (!grid)
		return (NULL);
	map = init_map();
	if (!map)
	{
		free(grid);
		return (NULL);
	}
	map->grid = grid;
	map->height = line_count;
	if (line_count > 0 && grid[0])
		map->width = ft_strlen(grid[0]);
	else
		map->width = 0;
	return (map);
}

static int	get_map_line_count(const char *path)
{
	int		line_count;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line_count = 0;
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strcmp(line, "\n") != 0)
			line_count++;
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	ft_get_next_line(-1);
	return (line_count);
}

static char	**allocate_and_load_grid(const char *path, int line_count)
{
	char	**grid;
	int		fd;

	grid = ft_calloc(line_count, sizeof(char *));
	if (!grid)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(grid);
		ft_putstr("ERROR: map data was not found\n");
		return (NULL);
	}
	grid = load_grid(fd, grid, line_count);
	close(fd);
	ft_get_next_line(-1);
	return (grid);
}

static char	**load_grid(int fd, char **grid, int line_count)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_get_next_line(fd);
	while (line != NULL && i < line_count)
	{
		if (ft_strcmp(line, "\n") != 0)
		{
			if (line[ft_strlen(line) - 1] == '\n')
				line[ft_strlen(line) - 1] = '\0';
			grid[i] = line;
			i++;
		}
		else
			free(line);
		line = ft_get_next_line(fd);
	}
	if (line != NULL)
		free(line);
	return (grid);
}
