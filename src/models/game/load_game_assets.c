/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_assets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:01:12 by urassh            #+#    #+#             */
/*   Updated: 2025/09/17 00:01:30 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"

int	load_game_assets(t_game_state *game, const char *map_path)
{
	if (!game || !map_path)
		return (1);
	game->map = load_map(map_path);
	if (!game->map)
		return (1);
	if (validate_map(game->map) == ERROR)
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
