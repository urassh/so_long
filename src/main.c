/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:34:00 by surayama          #+#    #+#             */
/*   Updated: 2025/09/24 23:51:27 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "events.h"
#include "game_state.h"
#include "mlx.h"
#include "so_long.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_game_state	*game;

	game = create_game();
	if (!game || start_game(game) != 0)
	{
		printf("Error: Failed to initialize game loop\n");
		free_game_state(game);
		return (1);
	}
	game->on_clear = on_clear;
	mlx_key_hook(game->mlx->win_ptr, on_key_down, game);
	mlx_loop_hook(game->mlx->mlx_ptr, (int (*)(void *))update_game, game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}
