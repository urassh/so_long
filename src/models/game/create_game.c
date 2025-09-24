/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:07:03 by urassh            #+#    #+#             */
/*   Updated: 2025/09/24 22:32:08 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"
#include "mlx.h"
#include "utils.h"

static void		*failure_game(t_game_state *game);
static int		create_mlx(t_game_state *game);
static int		create_window(t_game_state *game);
static int		create_game_state(t_game_state *game);

t_game_state	*create_game(void)
{
	t_game_state	*game;

	game = init_game_state();
	if (!game)
		return (NULL);
	if (load_game_assets(game, "assets/map/map") == ERROR)
		return (failure_game(game));
	if (create_mlx(game) == ERROR)
		return (failure_game(game));
	if (create_window(game) == ERROR)
		return (failure_game(game));
	if (create_game_state(game) == ERROR)
		return (failure_game(game));
	return (game);
}

static void	*failure_game(t_game_state *game)
{
	free_game_state(game);
	return (NULL);
}

static int	create_mlx(t_game_state *game)
{
	game->mlx = malloc(sizeof(t_mlx_context));
	if (!game->mlx)
		return (ERROR);
	game->mlx->mlx_ptr = mlx_init();
	if (!game->mlx->mlx_ptr)
		return (ERROR);
	return (OK);
}

static int	create_window(t_game_state *game)
{
	if (get_window_dimensions(game->map, &game->mlx->win_width,
			&game->mlx->win_height) == ERROR)
		return (ERROR);
	game->mlx->win_ptr = mlx_new_window(game->mlx->mlx_ptr,
			game->mlx->win_width, game->mlx->win_height, "so_long");
	if (!game->mlx->win_ptr)
		return (ERROR);
	return (OK);
}

static int	create_game_state(t_game_state *game)
{
	t_player			*player;
	t_collectible_state	*collect_state;

	game->renderer = init_renderer(game->mlx);
	if (!game->renderer)
		return (ERROR);
	if (load_textures(game->renderer) == ERROR)
		return (ERROR);
	player = create_player(game->map);
	if (player == NULL)
		return (ERROR);
	collect_state = create_collect_state(game->map);
	if (collect_state == NULL)
		return (ERROR);
	game->player = player;
	game->collectibles = collect_state;
	return (OK);
}
