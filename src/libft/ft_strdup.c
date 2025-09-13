/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:05:27 by urassh            #+#    #+#             */
/*   Updated: 2025/09/13 11:07:55 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		length;
	int		i;

	length = ft_strlen(s);
	new = ft_calloc(length, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < length)
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}
