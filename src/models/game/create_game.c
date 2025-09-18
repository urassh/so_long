/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:07:03 by urassh            #+#    #+#             */
/*   Updated: 2025/09/18 23:13:18 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_state.h"
#include "utils.h"
#include "mlx.h"

static void		*failure_game(t_game_state *game);
static int		create_mlx(t_game_state *game);
static int		create_window(t_game_state *game);
static int		create_renderer(t_game_state *game);

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
	if (create_renderer(game) == ERROR)
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

static int	create_renderer(t_game_state *game)
{
	int	start_x;
	int	start_y;

	start_x = 0;
	start_y = 0;
	game->renderer = init_renderer(game->mlx);
	if (!game->renderer)
		return (ERROR);
	if (load_textures(game->renderer) == ERROR)
		return (ERROR);
	if (find_player(game->map, &start_x, &start_y) == ERROR)
		return (ERROR);
	game->player = create_player(start_x, start_y);
	if (!game->player)
		return (ERROR);
	return (OK);
}
