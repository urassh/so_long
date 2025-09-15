/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:00:00 by urassh            #+#    #+#             */
/*   Updated: 2025/09/15 00:00:00 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "mlx.h"

void	clear_screen(t_renderer *renderer)
{
	if (!renderer || !renderer->mlx)
		return ;
	mlx_clear_window(renderer->mlx->mlx_ptr, renderer->mlx->win_ptr);
}

void	present_screen(t_renderer *renderer)
{
	if (!renderer || !renderer->mlx)
		return ;
	mlx_do_sync(renderer->mlx->mlx_ptr);
}
