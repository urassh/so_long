/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/17 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "game_state.h"

int	game_loop(t_game_state *game);
int	init_game_loop(t_game_state *game);
void	cleanup_game_loop(t_game_state *game);

#endif
