/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:43:55 by urassh            #+#    #+#             */
/*   Updated: 2025/09/11 17:44:55 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bzero(void *head_ptr, size_t size);

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	allocate_size;
	void	*allocated_area;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	allocate_size = nmemb * size;
	allocated_area = malloc(allocate_size);
	if (allocated_area == NULL)
		return (NULL);
	ft_bzero(allocated_area, allocate_size);
	return (allocated_area);
}

static void	ft_bzero(void *head_ptr, size_t size)
{
	unsigned char	*current_ptr;
	size_t			i;

	current_ptr = (unsigned char *)head_ptr;
	i = 0;
	while (i < size)
	{
		current_ptr[i] = 0;
		i++;
	}
}
