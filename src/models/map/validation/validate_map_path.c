/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:29:49 by urassh            #+#    #+#             */
/*   Updated: 2025/10/03 14:30:07 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

int	validate_map_path(const char *path)
{
	int		path_len;
	char	*extension;

	if (!path)
	{
		ft_putstr("Error: map path is null\n");
		return (ERROR);
	}
	path_len = ft_strlen(path);
	if (path_len < 4)
	{
		ft_putstr("Error: map path is too short\n");
		return (ERROR);
	}
	extension = (char *)path + path_len - 4;
	if (ft_strcmp(extension, ".ber") != 0)
	{
		ft_putstr("Error: map file must have .ber extension\n");
		return (ERROR);
	}
	return (OK);
}
