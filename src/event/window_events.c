/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/18 22:21:48 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "events.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	on_destroy(t_game_state *game)
{
	if (!game)
		return (0);
	set_game_status(game, GAME_QUIT);
	if (game->mlx && game->mlx->win_ptr)
	{
		mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
		game->mlx->win_ptr = NULL;
	}
	free_game_state(game);
	exit(0);
	return (0);
}
