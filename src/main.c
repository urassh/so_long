/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:34:00 by surayama          #+#    #+#             */
/*   Updated: 2025/09/16 23:59:55 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"
#include "controller.h"
#include "mlx.h"
#include "so_long.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_game_state	*game;
	int				start_x = 0, start_y;

	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	// ゲーム状態の初期化
	game = init_game_state();
	if (!game)
	{
		printf("Error: Failed to initialize game state\n");
		return (1);
	}
	// マップの読み込みと検証
	if (load_game_assets(game, argv[1]) != 0)
	{
		printf("Error: Failed to load or validate map from %s\n", argv[1]);
		free_game_state(game);
		return (1);
	}
	// MLXコンテキストの初期化
	game->mlx = malloc(sizeof(t_mlx_context));
	if (!game->mlx)
	{
		free_game_state(game);
		return (1);
	}
	game->mlx->mlx_ptr = mlx_init();
	if (!game->mlx->mlx_ptr)
	{
		free(game->mlx);
		game->mlx = NULL;
		free_game_state(game);
		return (1);
	}
	// ウィンドウサイズの検証と計算
	if (!is_valid_window_size(game->map))
	{
		printf("Error: Invalid window size for map dimensions\n");
		free(game->mlx);
		game->mlx = NULL;
		free_game_state(game);
		return (1);
	}
	if (get_window_dimensions(game->map, &game->mlx->win_width, 
		&game->mlx->win_height) != 0)
	{
		printf("Error: Failed to calculate window dimensions\n");
		free(game->mlx);
		game->mlx = NULL;
		free_game_state(game);
		return (1);
	}
	game->mlx->win_ptr = mlx_new_window(game->mlx->mlx_ptr,
			game->mlx->win_width, game->mlx->win_height, "so_long");
	if (!game->mlx->win_ptr)
	{
		free_game_state(game);
		return (1);
	}
	// レンダラーの初期化
	game->renderer = init_renderer(game->mlx);
	if (!game->renderer)
	{
		printf("Error: Failed to initialize renderer\n");
		free_game_state(game);
		return (1);
	}
	// テクスチャの読み込み
	if (load_textures(game->renderer) != OK)
	{
		printf("Error: Failed to load textures\n");
		free_game_state(game);
		return (1);
	}
	// プレイヤーモデルの初期化（マップから開始位置を取得）
	if (find_player(game->map, &start_x, &start_y) != 1)
	{
		printf("Error: Player not found in map\n");
		free_game_state(game);
		return (1);
	}
	game->player = create_player(start_x, start_y);
	if (!game->player)
	{
		printf("Error: Failed to create player model\n");
		free_game_state(game);
		return (1);
	}	
	// ゲームループの初期化
	if (init_game_loop(game) != 0)
	{
		printf("Error: Failed to initialize game loop\n");
		free_game_state(game);
		return (1);
	}
	mlx_loop_hook(game->mlx->mlx_ptr, (int (*)(void *))game_loop, game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}
