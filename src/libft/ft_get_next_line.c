/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:24:51 by urassh            #+#    #+#             */
/*   Updated: 2025/09/11 18:10:02 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char *remember);
char	*find_current_line_from(char *remember);
char	*find_next_line_from(char *remember);
char	*append_remember(char *remember, char *buffer);

char	*ft_get_next_line(int fd)
{
	static char	*remember;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	remember = read_file(fd, remember);
	if (!remember)
		return (NULL);
	line = find_current_line_from(remember);
	remember = find_next_line_from(remember);
}

char	*append_remember(char *remember, char *buffer)
{
	char	*new_remember;

	new_remember = ft_strjoin(remember, buffer);
	if (!new_remember)
		return (NULL);
	free(remember);
	return (new_remember);
}

char	*read_file(int fd, char *remember)
{
	char	*buffer;
	int		n_read_byte;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	n_read_byte = 1;
	while (n_read_byte > 0)
	{
		n_read_byte = read(fd, buffer, BUFFER_SIZE);
		if (n_read_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[n_read_byte] = 0;
		remember = append_remember(remember, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
}

char	*find_current_line_from(char *remember)
{
	int		i;
	char	*line;

	i = 0;
	if (!remember[i])
		return (NULL);
	while (remember[i] && remember != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	while (remember[i] && remember != '\n')
	{
		line[i] = remember[i];
		i++;
	}
	if (remember[i] && remember[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*find_next_line_from(char *remember)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (remember[i] && remember[i] != '\n')
		i++;
	if (!remember[i])
	{
		free(remember);
		return (NULL);
	}
	line = ft_calloc(sizeof(char), (ft_strlen(remember) - i + 1));
	i++;
	j = 0;
	while (remember[i])
		line[j++] = remember[i++];
	free(remember);
	return (line);
}
