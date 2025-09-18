/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/18 22:19:47 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "mlx.h"
#include "renderer.h"
#include <stdio.h>
#include <unistd.h>

/**
 * @brief ゲームループの初期化
 *
 * ゲームループに必要な基本的な設定を行います。
 * 最小限の実装として、MLXライブラリの基本設定のみ行います。
 */
int	start_game(t_game_state *game)
{
	if (!game)
		return (-1);
	printf("Game loop initialized\n");
	if (game->renderer && game->map)
	{
		render_game(game);
		printf("Initial map rendered\n");
	}
	return (0);
}

int	update_game(t_game_state *game)
{
	if (!game || !game->renderer || !game->map)
		return (0);
	if (get_game_status(game) != GAME_RUNNING)
		return (0);
	if (game->state_changed)
		render_game(game);
	game->state_changed = false;
	return (0);
}
