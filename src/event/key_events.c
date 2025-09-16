/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/17 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "so_long.h"
#include "vector2d.h"
#include <stdio.h>
#include <stdlib.h>

int	on_key_down(int key_code, t_game_state *game)
{
	if (!game)
		return (0);
	if (get_game_status(game) != GAME_RUNNING)
		return (0);
	if (key_code == KEY_ESC)
		return (on_destroy(game));
	return (0);
}

