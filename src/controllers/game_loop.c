/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/27 18:28:06 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "events.h"
#include "game_state.h"
#include "libft.h"
#include "mlx.h"
#include "renderer.h"
#include <unistd.h>

int	start_game(t_game_state *game)
{
	if (!game)
		return (-1);
	ft_putstr("Game loop initialized\n");
	if (game->renderer && game->map)
	{
		render_game(game);
		ft_putstr("Initial map rendered\n");
	}
	return (0);
}

int	update_game(t_game_state *game)
{
	if (!game || !game->renderer || !game->map)
		return (0);
	subscribe_game_state(game);
	if (get_game_status(game) != GAME_RUNNING)
		return (0);
	if (game->state_changed)
		render_game(game);
	game->state_changed = false;
	return (0);
}
