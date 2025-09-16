/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 23:50:56 by urassh            #+#    #+#             */
/*   Updated: 2025/09/16 23:52:53 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	set_player_position(t_player *player, int x, int y)
{
	if (!player)
		return ;
	player->previous_position = player->position;
	player->position.x = x;
	player->position.y = y;
	player->position_changed = true;
}

t_vector2d	get_player_position(const t_player *player)
{
	t_vector2d	empty_pos;

	empty_pos = vector2d_create(0, 0);
	if (!player)
		return (empty_pos);
	return (player->position);
}
