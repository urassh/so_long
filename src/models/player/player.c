/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/16 23:35:24 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include <stdlib.h>

t_player	*create_player(int start_x, int start_y)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	reset_player(player, start_x, start_y);
	return (player);
}

void	destroy_player(t_player *player)
{
	if (player)
		free(player);
}

void	reset_player(t_player *player, int start_x, int start_y)
{
	if (!player)
		return ;
	player->position.x = start_x;
	player->position.y = start_y;
	player->previous_position.x = start_x;
	player->previous_position.y = start_y;
	player->state = PLAYER_IDLE;
	player->collect_count = 0;
	player->position_changed = false;
}

void	clear_player_position_changed_flag(t_player *player)
{
	if (!player)
		return ;
	player->position_changed = false;
}
