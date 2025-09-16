/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 23:52:15 by urassh            #+#    #+#             */
/*   Updated: 2025/09/16 23:52:21 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	set_player_state(t_player *player, t_player_state state)
{
	if (!player)
		return ;
	player->state = state;
}

t_player_state	get_player_state(const t_player *player)
{
	if (!player)
		return (PLAYER_DEAD);
	return (player->state);
}
