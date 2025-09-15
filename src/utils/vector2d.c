/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/15 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2d.h"

t_vector2d	vector2d_create(int x, int y)
{
	t_vector2d	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector2d	vector2d_add(t_vector2d a, t_vector2d b)
{
	t_vector2d	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

t_vector2d	vector2d_subtract(t_vector2d a, t_vector2d b)
{
	t_vector2d	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return (result);
}

int	vector2d_equals(t_vector2d a, t_vector2d b)
{
	return (a.x == b.x && a.y == b.y);
}
