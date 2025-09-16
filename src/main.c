/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:34:00 by surayama          #+#    #+#             */
/*   Updated: 2025/09/16 23:14:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"
#include "mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	key_handler(int key, t_game_state *game)
{
	printf("Key pressed: %d\n", key);
	if (key == KEY_ESC)
	{
		set_game_status(game, GAME_QUIT);
		if (game->mlx && game->mlx->win_ptr)
			mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
		free_game_state(game);
		exit(0);
	}
	return (0);
}

int	close_handler(t_game_state *game)
{
	set_game_status(game, GAME_QUIT);
	if (game->mlx && game->mlx->win_ptr)
		mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
	free_game_state(game);
	exit(0);
	return (0);
}

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
	if (load_game_map(game, argv[1]) != 0)
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
	// ウィンドウサイズを計算
	game->mlx->win_width = game->map->width * TILE_SIZE;
	game->mlx->win_height = game->map->height * TILE_SIZE;
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
	start_x = 0, start_y = 0;
	// マップから開始位置を見つける
	for (int y = 0; y < game->map->height; y++)
	{
		for (int x = 0; x < game->map->width; x++)
		{
			if (game->map->grid[y][x] == PLAYER)
			{
				start_x = x;
				start_y = y;
				break ;
			}
		}
	}
	game->player = create_player_model(start_x, start_y);
	if (!game->player)
	{
		printf("Error: Failed to create player model\n");
		free_game_state(game);
		return (1);
	}
	// 初回描画 - マップのみレンダリング
	render_map(game->renderer, game->map);
	// イベントハンドラーの登録
	mlx_key_hook(game->mlx->win_ptr, key_handler, game);
	mlx_hook(game->mlx->win_ptr, ON_DESTROY, 0, close_handler, game);
	// メインループ
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}
