/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_assets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:01:12 by urassh            #+#    #+#             */
/*   Updated: 2025/09/18 22:32:44 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "game_state.h"

int	load_game_assets(t_game_state *game, const char *map_path)
{
	if (!game || !map_path)
		return (ERROR);
	game->map = load_map(map_path);
	if (!game->map)
		return (ERROR);
	if (validate_map(game->map) == ERROR)
	{
		free_map(game->map);
		game->map = NULL;
		return (ERROR);
	}
	game->collectibles = init_collectible_model();
	if (!game->collectibles)
		return (ERROR);
	mark_state_changed(game);
	return (OK);
}
