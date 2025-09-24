/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/24 22:38:51 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collectible_state.h"
#include <stdlib.h>

t_collectible_state	*init_collectible_state(void)
{
	t_collectible_state	*model;

	model = malloc(sizeof(t_collectible_state));
	if (!model)
		return (NULL);
	model->items = NULL;
	model->count = 0;
	model->obtained_count = 0;
	model->state_changed = false;
	return (model);
}

void	free_collectible_state(t_collectible_state *model)
{
	if (!model)
		return ;
	if (model->items)
		free(model->items);
	free(model);
}

int	collect_item_at(t_collectible_state *model, t_vector2d pos)
{
	int	i;

	if (!model || !model->items)
		return (1);
	i = 0;
	while (i < model->count)
	{
		if (model->items[i].is_active
			&& vector2d_equals(model->items[i].position, pos))
		{
			model->items[i].is_active = false;
			model->obtained_count++;
			model->state_changed = true;
			return (0);
		}
		i++;
	}
	return (1);
}

bool	all_collectibles_obtained(t_collectible_state *model)
{
	if (!model)
		return (false);
	return (model->obtained_count >= model->count);
}
