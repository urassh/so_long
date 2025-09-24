/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:50:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/24 23:31:19 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collectible_state.h"
#include "constants.h"
#include "game_state.h"
#include "map.h"
#include "player.h"
#include "player_controller.h"
#include "vector2d.h"
#include <stdio.h>

int	move_player(t_game_state *game, t_move_direction direction)
{
	t_vector2d	current_pos;
	int			new_x;
	int			new_y;

	if (!game || !game->player)
		return (1);
	current_pos = get_player_position(game->player);
	new_x = current_pos.x;
	new_y = current_pos.y;
	if (direction == MOVE_UP)
		new_y--;
	else if (direction == MOVE_DOWN)
		new_y++;
	else if (direction == MOVE_LEFT)
		new_x--;
	else if (direction == MOVE_RIGHT)
		new_x++;
	return (try_move_player(game, new_x, new_y));
}

int	try_move_player(t_game_state *game, int new_x, int new_y)
{
	if (!is_valid_position(game, new_x, new_y))
		return (1);
	set_player_position(game->player, new_x, new_y);
	increment_move_count(game);
	handle_collectible(game, new_x, new_y);
	handle_exit(game, new_x, new_y);
	set_player_state(game->player, PLAYER_MOVING);
	mark_state_changed(game);
	return (0);
}

int	is_valid_position(t_game_state *game, int x, int y)
{
	if (!game || !game->map || !game->map->grid)
		return (0);
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
		return (0);
	if (game->map->grid[y][x] == WALL)
		return (0);
	return (1);
}

void	handle_collectible(t_game_state *game, int x, int y)
{
	t_vector2d	pos;

	if (!game || !game->collectibles)
		return ;
	pos.x = x;
	pos.y = y;
	if (collect_item_at(game->collectibles, pos) == 0)
	{
		increment_collect(game->player);
		printf("Collected item! Total: %d\n", get_collect_count(game->player));
	}
}

void	handle_exit(t_game_state *game, int x, int y)
{
	if (!game || !game->map || !game->collectibles)
		return ;
	if (game->map->grid[y][x] == EXIT)
	{
		if (all_collectibles_obtained(game->collectibles))
		{
			set_game_status(game, GAME_CLEAR);
			printf("Game Clear! Moves: %d\n", get_move_count(game));
		}
		else
		{
			printf("Collect all items first! Remaining: %d\n",
				game->collectibles->count - game->collectibles->obtained_count);
		}
	}
}
