/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_model.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/15 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTIBLE_MODEL_H
# define COLLECTIBLE_MODEL_H

# include "vector2d.h"
# include <stdbool.h>

typedef struct s_collectible
{
	t_vector2d	position;
	bool		is_active;
}				t_collectible;

typedef struct s_collectible_model
{
	t_collectible	*items;
	int				count;
	int				obtained_count;
	bool			state_changed;
}					t_collectible_model;

t_collectible_model	*init_collectible_model(void);
void				free_collectible_model(t_collectible_model *model);
int					add_collectible(t_collectible_model *model, t_vector2d pos);
int					collect_item_at(t_collectible_model *model, t_vector2d pos);
bool				all_collectibles_obtained(t_collectible_model *model);

#endif
