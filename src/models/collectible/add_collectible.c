/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_collectible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:38:31 by urassh            #+#    #+#             */
/*   Updated: 2025/09/24 22:39:02 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collectible_state.h"
#include <stdlib.h>

int	add_collectible(t_collectible_state *model, t_vector2d pos)
{
	t_collectible	*new_items;
	int				i;

	if (!model)
		return (1);
	model->count += 1;
	new_items = malloc(sizeof(t_collectible) * model->count);
	if (!new_items)
		return (1);
	if (model->items && model->count > 0)
	{
		i = 0;
		while (i < model->count)
		{
			new_items[i] = model->items[i];
			i++;
		}
		free(model->items);
	}
	new_items[model->count].position = pos;
	new_items[model->count].is_active = true;
	model->items = new_items;
	model->state_changed = true;
	return (0);
}
