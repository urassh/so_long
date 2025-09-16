/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/17 00:14:10 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"
#include <stdlib.h>

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
	game->state_changed = true;
	gettimeofday(&game->last_frame_time, NULL);
	game->delta_time = 0.0f;
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
		free_collectible_model(game->collectibles);
	if (game->renderer)
		free_renderer(game->renderer);
	free(game);
}

void	reset_game_state(t_game_state *game)
{
	if (!game)
		return ;
	game->move_count = 0;
	game->status = GAME_RUNNING;
	if (game->player)
		set_player_state(game->player, PLAYER_IDLE);
	mark_state_changed(game);
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
