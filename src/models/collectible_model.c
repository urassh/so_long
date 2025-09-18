/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_model.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/18 23:32:33 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collectible_model.h"
#include <stdlib.h>

t_collectible_model	*init_collectible_model(void)
{
	t_collectible_model	*model;

	model = malloc(sizeof(t_collectible_model));
	if (!model)
		return (NULL);
	model->items = NULL;
	model->count = 0;
	model->obtained_count = 0;
	model->state_changed = false;
	return (model);
}

void	free_collectible_model(t_collectible_model *model)
{
	if (!model)
		return ;
	if (model->items)
		free(model->items);
	free(model);
}

int	add_collectible(t_collectible_model *model, t_vector2d pos)
{
	t_collectible	*new_items;
	int				new_count;
	int				i;

	if (!model)
		return (1);
	new_count = model->count + 1;
	new_items = malloc(sizeof(t_collectible) * new_count);
	if (!new_items)
		return (1);
	if (model->items && model->count > 0)
	{
		i = 0;
		while (i < model->count)
			new_items[i++] = model->items[i];
		free(model->items);
	}
	new_items[model->count].position = pos;
	new_items[model->count].is_active = true;
	model->items = new_items;
	model->count = new_count;
	model->state_changed = true;
	return (0);
}

int	collect_item_at(t_collectible_model *model, t_vector2d pos)
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

bool	all_collectibles_obtained(t_collectible_model *model)
{
	if (!model)
		return (false);
	return (model->obtained_count >= model->count);
}
