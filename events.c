/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:32:45 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/07 21:31:07 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_key_press(int key, t_mlx_map *map)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(map->data.mlx, map->data.win);
		map->map->destroy(map->map);
	}
	else
	{
		mlx_clear_window(map->data.mlx, map->data.win);
		if (key == XK_Up)
			map->map->transform(map->map, 5, 0);
		else if (key == XK_Down)
			map->map->transform(map->map, -5, 0);
		else if (key == XK_Left)
			map->map->transform(map->map, 0, -5);
		else if (key == XK_Right)
			map->map->transform(map->map, 0, 5);
		else if (key == XK_KP_1 || key == XK_1)
			map->map->set_angle(map->map, 0.8, 0.8);
		else if (key == XK_KP_2 || key == XK_2)
			map->map->set_angle(map->map, 0.5235, 2.6179);
		map->map->render(*map->map, map->data);
	}
	return (0);
}

int	handle_key_release(int key, t_mlx_map *map)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(map->data.mlx, map->data.win);
		map->map->destroy(map->map);
	}
	return (0);
}

int handle_mouse_scroll(int key, int x, int y, t_mlx_map *map)
{
    if (key == Button4)
	{
		mlx_clear_window(map->data.mlx, map->data.win);
		map->map->zoom(map->map, 1.1);
		map->map->render(*map->map, map->data);
	}
    else if (key == Button5)
    {
        mlx_clear_window(map->data.mlx, map->data.win);
		map->map->zoom(map->map, 0.9);
		map->map->render(*map->map, map->data);
    }
    return (0);
}

