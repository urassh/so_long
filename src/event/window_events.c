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
#include "libft.h"
#include <stdlib.h>

int	on_destroy(t_game_state *game)
{
	if (game)
	{
		set_game_status(game, GAME_QUIT);
		if (game->mlx && game->mlx->win_ptr)
		{
			mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
			game->mlx->win_ptr = NULL;
		}
		free_game_state(game);
	}
	ft_putstr("==========================================\n");
	ft_putstr("           GAME CLOSED\n");
	ft_putstr("        Thank you for playing!\n");
	ft_putstr("==========================================\n");
	exit(0);
}

int	on_expose(t_game_state *game)
{
	if (!game || !game->renderer)
		return (0);
	game->state_changed = true;
	render_game(game);
	return (0);
}
