/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:50:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/24 22:50:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CONTROLLER_H
# define PLAYER_CONTROLLER_H

# include "game_state.h"
# include "vector2d.h"

typedef enum e_move_direction
{
	MOVE_UP = 0,
	MOVE_DOWN = 1,
	MOVE_LEFT = 2,
	MOVE_RIGHT = 3
}	t_move_direction;

int		move_player(t_game_state *game, t_move_direction direction);
int		try_move_player(t_game_state *game, int new_x, int new_y);
int		is_valid_position(t_game_state *game, int x, int y);
void	handle_collectible(t_game_state *game, int x, int y);
void	handle_exit(t_game_state *game, int x, int y);

#endif
