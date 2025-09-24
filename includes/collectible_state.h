/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_state.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/24 22:32:48 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTIBLE_STATE_H
# define COLLECTIBLE_STATE_H

# include "vector2d.h"
# include <stdbool.h>

typedef struct s_collectible
{
	t_vector2d		position;
	bool			is_active;
}					t_collectible;

typedef struct s_collectible_state
{
	t_collectible	*items;
	int				count;
	int				obtained_count;
	bool			state_changed;
}					t_collectible_state;

t_collectible_state	*init_collectible_state(void);
void				free_collectible_state(t_collectible_state *model);
int					add_collectible(t_collectible_state *model, t_vector2d pos);
int					collect_item_at(t_collectible_state *model, t_vector2d pos);
bool				all_collectibles_obtained(t_collectible_state *model);

#endif
