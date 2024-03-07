/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:32:45 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/07 18:35:28 by caqueiro         ###   ########.fr       */
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
		map->map->zoom(map->map, 5);
		map->map->render(*map->map, map->data);
	}
    else if (key == Button5)
    {
        mlx_clear_window(map->data.mlx, map->data.win);
		map->map->zoom(map->map, -5);
		map->map->render(*map->map, map->data);
    }
    return (0);
}

