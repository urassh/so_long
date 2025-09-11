/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:34:54 by urassh            #+#    #+#             */
/*   Updated: 2025/09/11 17:46:35 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_strings(char *dest, const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		length;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	length = ft_strlen(s1) + ft_strlen(s2);
	joined = ft_calloc(length + 1, sizeof(char));
	if (!joined)
		return (NULL);
	return (copy_strings(joined, s1, s2));
}
