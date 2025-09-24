/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/18 23:33:41 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "player_controller.h"
#include "so_long.h"
#include "vector2d.h"
#include <stdio.h>
#include <stdlib.h>

int	on_key_down(int key_code, void *param)
{
	t_game_state	*game;

	game = (t_game_state *)param;
	if (!game)
		return (0);
	if (get_game_status(game) != GAME_RUNNING)
		return (0);
	if (key_code == KEY_ESC)
		return (on_destroy(game));
	if (key_code == KEY_W || key_code == KEY_UP)
		move_player(game, MOVE_UP);
	else if (key_code == KEY_S || key_code == KEY_DOWN)
		move_player(game, MOVE_DOWN);
	else if (key_code == KEY_A || key_code == KEY_LEFT)
		move_player(game, MOVE_LEFT);
	else if (key_code == KEY_D || key_code == KEY_RIGHT)
		move_player(game, MOVE_RIGHT);
	return (0);
}
