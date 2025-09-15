/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/15 00:00:00 by urassh           ###   ########.fr       */
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

void	increment_move_count(t_game_state *game)
{
	if (!game)
		return ;
	game->move_count++;
	mark_state_changed(game);
}

int	get_move_count(const t_game_state *game)
{
	if (!game)
		return (0);
	return (game->move_count);
}

bool	check_win_condition(t_game_state *game)
{
	if (!game || !game->collectibles)
		return (false);
	return (all_collectibles_obtained(game->collectibles));
}

void	handle_game_clear(t_game_state *game)
{
	if (!game)
		return ;
	set_game_status(game, GAME_CLEAR);
	if (game->player)
		set_player_state(game->player, PLAYER_WINNING);
}
