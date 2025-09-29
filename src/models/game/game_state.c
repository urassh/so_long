/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surayama <surayama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/29 15:23:21 by surayama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"
#include "renderer.h"
#include "mlx.h"
#include <stdlib.h>
#include <sys/time.h>

t_game_state	*init_game_state(void)
{
	t_game_state	*game;

	game = malloc(sizeof(t_game_state));
	if (!game)
		return (NULL);
	game->player = NULL;
	game->map = NULL;
	game->collectibles = NULL;
	game->mlx = NULL;
	game->renderer = NULL;
	game->move_count = 0;
	game->status = GAME_RUNNING;
	game->previous_status = GAME_RUNNING;
	game->state_changed = true;
	gettimeofday(&game->last_frame_time, NULL);
	game->delta_time = 0.0f;
	game->on_clear = NULL;
	return (game);
}

void	free_game_state(t_game_state *game)
{
	if (!game)
		return ;
	if (game->player)
		destroy_player(game->player);
	if (game->map)
		free_map(game->map);
	if (game->collectibles)
		free_collectible_state(game->collectibles);
	if (game->renderer)
		free_renderer(game->renderer);
	if (game->mlx)
	{
		if (game->mlx->win_ptr)
			mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
		if (game->mlx->mlx_ptr)
		{
			mlx_destroy_display(game->mlx->mlx_ptr);
			free(game->mlx->mlx_ptr);
		}
		free(game->mlx);
	}
	free(game);
}

void	update_game_state(t_game_state *game)
{
	if (!game || !is_game_running(game))
		return ;
	if (is_game_clear(game))
		push_game_clear_event(game);
}

void	mark_state_changed(t_game_state *game)
{
	if (game)
		game->state_changed = true;
}

void	subscribe_game_state(t_game_state *game)
{
	if (!game)
		return ;
	if (game->status != game->previous_status)
	{
		if (game->status == GAME_CLEAR && game->on_clear)
			game->on_clear(game);
		game->previous_status = game->status;
	}
}
