/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:50:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/27 18:45:02 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"
#include "libft.h"
#include "mlx.h"
#include "player.h"
#include "renderer.h"
#include <stdlib.h>
#include <unistd.h>

void	on_clear(t_game_state *game)
{
	if (!game)
		return ;
	ft_putstr("===========================================\n");
	ft_putstr("           GAME CLEAR!                    \n");
	ft_putstr("===========================================\n");
	ft_putstr("Congratulations! You have completed the game!\n");
	ft_putstr("Total moves: ");
	ft_putnbr(get_move_count(game));
	ft_putstr("\n");
	ft_putstr("Items collected: ");
	ft_putnbr(get_collect_count(game->player));
	ft_putstr("\n");
	ft_putstr("===========================================\n");
	set_game_status(game, GAME_QUIT);
	free_game_state(game);
	exit(0);
}
