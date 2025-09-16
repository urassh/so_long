/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:07:29 by urassh            #+#    #+#             */
/*   Updated: 2025/09/17 00:18:53 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"

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
