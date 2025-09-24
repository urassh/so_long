/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:50:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/24 22:50:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"
#include "player.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	on_clear(t_game_state *game)
{
	if (!game)
		return ;
	printf("===========================================\n");
	printf("           GAME CLEAR!                    \n");
	printf("===========================================\n");
	printf("Congratulations! You have completed the game!\n");
	printf("Total moves: %d\n", get_move_count(game));
	printf("Items collected: %d\n", get_collect_count(game->player));
	printf("===========================================\n");
	set_game_status(game, GAME_QUIT);
	if (game->mlx && game->mlx->win_ptr)
	{
		mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
		game->mlx->win_ptr = NULL;
	}
	free_game_state(game);
	exit(0);
}
