/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:24:13 by urassh            #+#    #+#             */
/*   Updated: 2025/09/27 18:25:35 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(const char *str)
{
	int	length;
	int	i;

	length = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		write(1, str[i], 1);
		i++;
	}
}
