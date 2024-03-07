/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:32:45 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/07 17:28:10 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_key_press(int key, t_mlx_data *mlx_data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	}
	return (0);
}

int handle_mouse_scroll(int key, int x, int y, t_map *map)
{
    if (key == Button4) // Scroll para cima
		ft_printf("rolada para cima");
    else if (key == Button5) // Scroll para baixo
    {
        // Implemente a lógica para rolar para baixo
    }
    return (0);
}

int	handle_key_release(int key, t_mlx_data *mlx_data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	}
	return (0);
}
