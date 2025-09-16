/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 23:39:36 by urassh            #+#    #+#             */
/*   Updated: 2025/09/16 23:41:21 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	increment_collect(t_player *player)
{
	if (!player)
		return ;
	player->collect_count++;
}

int	get_collect_count(const t_player *player)
{
	if (!player)
		return (0);
	return (player->collect_count);
}
