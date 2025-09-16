/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:08:33 by urassh            #+#    #+#             */
/*   Updated: 2025/09/17 00:12:42 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"

void	set_game_status(t_game_state *game, t_game_status status)
{
	if (!game)
		return ;
	if (game->status != status)
	{
		game->status = status;
		mark_state_changed(game);
	}
}

t_game_status	get_game_status(const t_game_state *game)
{
	if (!game)
		return (GAME_QUIT);
	return (game->status);
}

bool	is_game_running(const t_game_state *game)
{
	if (!game)
		return (false);
	return (game->status == GAME_RUNNING);
}

bool	is_game_over(const t_game_state *game)
{
	if (!game)
		return (true);
	return (game->status == GAME_OVER || game->status == GAME_CLEAR
		|| game->status == GAME_QUIT);
}

bool	is_game_clear(const t_game_state *game)
{
	if (!game || !game->collectibles)
		return (false);
	if (!all_collectibles_obtained(game->collectibles))
		return (false);
	return (true);
}
