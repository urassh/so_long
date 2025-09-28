/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:34:00 by surayama          #+#    #+#             */
/*   Updated: 2025/09/28 09:16:30 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "events.h"
#include "game_state.h"
#include "libft.h"
#include "mlx.h"
#include "so_long.h"
#include "utils.h"
#include <stdlib.h>

int	main(int argc, const char **argv)
{
	t_game_state	*game;

	if (argc != 2)
	{
		ft_putstr("ERROR: invalid arguments.\n");
		ft_putstr("example: ./so_long assets/map/map.ber\n");
		exit(1);
	}
	game = create_game(argv[1]);
	if (!game || start_game(game) != 0)
	{
		ft_putstr("ERROR: Failed to initialize game loop\n");
		free_game_state(game);
		exit(1);
	}
	game->on_clear = on_clear;
	mlx_key_hook(game->mlx->win_ptr, on_key_down, game);
	mlx_loop_hook(game->mlx->mlx_ptr, (int (*)(void *))update_game, game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}
