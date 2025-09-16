/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_game_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/17 00:16:10 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"

void	push_game_clear_event(t_game_state *game)
{
	if (!game)
		return ;
	set_game_status(game, GAME_CLEAR);
	if (game->player)
		set_player_state(game->player, PLAYER_WINNING);
}

void	push_game_over_event(t_game_state *game)
{
	if (!game)
		return ;
	set_game_status(game, GAME_OVER);
	if (game->player)
		set_player_state(game->player, PLAYER_DEAD);
}
