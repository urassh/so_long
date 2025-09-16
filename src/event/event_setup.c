/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/17 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

int	setup_event_handlers(t_game_state *game)
{
	if (!game || !game->mlx || !game->mlx->win_ptr)
	{
		printf("Error: Invalid game state for event setup\n");
		return (ERROR);
	}
	mlx_key_hook(game->mlx->win_ptr, on_key_down, game);
	mlx_hook(game->mlx->win_ptr, ON_DESTROY, 0, on_destroy, game);		
	return (0);
}
