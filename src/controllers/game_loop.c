/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/18 23:34:41 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "events.h"
#include "game_state.h"
#include "mlx.h"
#include "renderer.h"
#include <stdio.h>
#include <unistd.h>

int	start_game(t_game_state *game)
{
	if (!game)
		return (-1);
	printf("Game loop initialized\n");
	if (game->renderer && game->map)
	{
		render_game(game);
		printf("Initial map rendered\n");
	}
	return (0);
}

int	update_game(t_game_state *game)
{
	if (!game || !game->renderer || !game->map)
		return (0);
	
	// ゲームステートの変更をチェックしてイベントを処理
	subscribe_game_state(game);
	
	if (get_game_status(game) != GAME_RUNNING)
		return (0);
	if (game->state_changed)
		render_game(game);
	game->state_changed = false;
	return (0);
}
