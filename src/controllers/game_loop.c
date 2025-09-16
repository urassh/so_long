/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/17 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller.h"
#include "renderer.h"
#include "mlx.h"
#include <stdio.h>
#include <unistd.h>

/**
 * @brief ゲームループの初期化
 * 
 * ゲームループに必要な基本的な設定を行います。
 * 最小限の実装として、MLXライブラリの基本設定のみ行います。
 */
int	init_game_loop(t_game_state *game)
{
	if (!game)
		return (-1);
	
	printf("Game loop initialized\n");
	
	// 初回マップ描画
	if (game->renderer && game->map)
	{
		render_map(game->renderer, game->map);
		printf("Initial map rendered\n");
	}
	
	return (0);
}

int	game_loop(t_game_state *game)
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

void	cleanup_game_loop(t_game_state *game)
{
	if (!game)
		return ;
}
