/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/28 10:29:50 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "game_state.h"

int		on_key_down(int key_code, void *param);
int		on_destroy(t_game_state *game);
int		on_expose(t_game_state *game);

int		setup_event_handlers(t_game_state *game);
void	on_clear(t_game_state *game);

#endif
