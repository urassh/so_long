/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:34:00 by surayama          #+#    #+#             */
/*   Updated: 2025/09/10 13:34:23 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = open("assets/map/map", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Could not open file 'assets/map/map'\n");
		return (1);
	}

	printf("Testing ft_get_next_line with assets/map/map:\n");
	printf("==========================================\n");
	
	line_count = 1;
	while ((line = ft_get_next_line(fd)) != NULL)
	{
		if (ft_strcmp(line, "\n") == 0)
			continue;
		printf("Line %d: %s", line_count, line);
		if (line[ft_strlen(line) - 1] != '\n')
			printf("\n");
		free(line);
		line_count++;
	}
	
	printf("==========================================\n");
	printf("Total lines read: %d\n", line_count - 1);
	
	close(fd);
	return (0);
}
