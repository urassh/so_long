/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:23:22 by urassh            #+#    #+#             */
/*   Updated: 2025/09/11 17:57:41 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <sys/types.h>

# define BUFFER_SIZE 1024

int		ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *string, int searched_char);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_get_next_line(int fd);

#endif
