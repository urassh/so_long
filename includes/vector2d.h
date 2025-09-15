/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/15 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2D_H
# define VECTOR2D_H

typedef struct s_vector2d
{
	int	x;
	int	y;
}		t_vector2d;

t_vector2d	vector2d_create(int x, int y);
t_vector2d	vector2d_add(t_vector2d a, t_vector2d b);
t_vector2d	vector2d_subtract(t_vector2d a, t_vector2d b);
int			vector2d_equals(t_vector2d a, t_vector2d b);

#endif
