/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/10/03 12:02:11 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"

static int	get_map_line_count(const char *path);
static char	**allocate_and_load_grid(const char *path, int line_count);
static char	**load_grid(int fd, char **grid, int line_count);
static int	map_line_error(const char *error_message, char *line);

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
		return (map_line_error("Error: map data was not found\n", NULL));
	line_count = 0;
	line = ft_get_next_line(fd);
	while (line != NULL && ft_strlen(line) <= MAX_WIDTH)
	{
		if (ft_strcmp(line, "\n") != 0)
			line_count++;
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	ft_get_next_line(-1);
	if (ft_strlen(line) > MAX_WIDTH)
		return (map_line_error("Error: map width was too long!\n", line));
	if (line_count > MAX_HEIGHT)
		return (map_line_error("Error: map height was too long!\n", line));
	if (line_count <= 0)
		return (map_line_error("Error: map data was empty\n", NULL));
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

static int	map_line_error(const char *error_message, char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	ft_putstr(error_message);
	return (-1);
}
