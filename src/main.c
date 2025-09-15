/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:34:00 by surayama          #+#    #+#             */
/*   Updated: 2025/09/15 15:21:37 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "so_long.h"

typedef struct s_data
{
    void *mlx;
    void *mlx_win;
} t_data;

int key_handler(int key, t_data *data)
{
    printf("Key pressed: %d\n", key);
    if (key == KEY_ESC)
    {
        mlx_destroy_window(data->mlx, data->mlx_win);
        exit(0);
    }
    return (0);
}

int close_handler(t_data *data)
{
    mlx_destroy_window(data->mlx, data->mlx_win);
    exit(0);
    return (0);
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, 300, 300, "Hello World - Press ESC to exit");
    
    mlx_key_hook(data.mlx_win, key_handler, &data);
    mlx_hook(data.mlx_win, ON_DESTROY, 0, close_handler, &data);
    
    mlx_loop(data.mlx);
    return (0);
}
