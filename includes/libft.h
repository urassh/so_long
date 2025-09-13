/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:23:22 by urassh            #+#    #+#             */
/*   Updated: 2025/09/13 16:05:35 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# define BUFFER_SIZE 1024

int		ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strcmp(const char *a, const char *b);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *string, int searched_char);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_get_next_line(int fd);

#endif
