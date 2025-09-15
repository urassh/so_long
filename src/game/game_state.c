/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/15 00:00:00 by urassh           ###   ########.fr       */
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
		destroy_player_model(game->player);
	if (game->map)
		free_map(game->map);
	if (game->collectibles)
		free_collectible_model(game->collectibles);
	if (game->renderer)
		free_renderer(game->renderer);
	free(game);
}

int	load_game_map(t_game_state *game, const char *map_path)
{
	if (!game || !map_path)
		return (1);
	game->map = load_map(map_path);
	if (!game->map)
		return (1);
	if (validate_map(game->map) != 0)
	{
		free_map(game->map);
		game->map = NULL;
		return (1);
	}
	game->collectibles = init_collectible_model();
	if (!game->collectibles)
		return (1);
	mark_state_changed(game);
	return (0);
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
	calculate_delta_time(game);
	if (game->player)
		update_player_animation(game->player, game->delta_time);
	if (check_win_condition(game))
		handle_game_clear(game);
}

void	calculate_delta_time(t_game_state *game)
{
	struct timeval	current_time;
	float			time_diff;

	if (!game)
		return ;
	gettimeofday(&current_time, NULL);
	time_diff = (current_time.tv_sec - game->last_frame_time.tv_sec)
		+ (current_time.tv_usec - game->last_frame_time.tv_usec) / 1000000.0f;
	game->delta_time = time_diff;
	game->last_frame_time = current_time;
}

void	mark_state_changed(t_game_state *game)
{
	if (game)
		game->state_changed = true;
}
