/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event-key-press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:29:38 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/11 16:57:26 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	handle_arrow_press(int key, t_mlx_map *map)
{
	if (key == XK_Up)
	{
		map->map->transform(map->map, 0, 5);
		mlx_clear_window(map->data.mlx, map->data.win);
		map->map->render(*map->map, map->data);
	}
	else if (key == XK_Down)
	{
		map->map->transform(map->map, 0, -5);
		mlx_clear_window(map->data.mlx, map->data.win);
		map->map->render(*map->map, map->data);
	}
	else if (key == XK_Left)
	{
		map->map->transform(map->map, 5, 0);
		mlx_clear_window(map->data.mlx, map->data.win);
		map->map->render(*map->map, map->data);
	}
	else if (key == XK_Right)
	{
		map->map->transform(map->map, -5, 0);
		mlx_clear_window(map->data.mlx, map->data.win);
		map->map->render(*map->map, map->data);
	}
}

static void handle_num_press(int key, t_mlx_map *map)
{
	if (key == XK_KP_0 || key == XK_0)
	{
		map->map->set_angle(map->map, 0.0, 0.0);
		mlx_clear_window(map->data.mlx, map->data.win);
		map->map->render(*map->map, map->data);
	}
	else if (key == XK_KP_1 || key == XK_1)
	{
		map->map->set_angle(map->map, 0.8, 0.8);
		mlx_clear_window(map->data.mlx, map->data.win);
		map->map->render(*map->map, map->data);
	}
	else if (key == XK_KP_2 || key == XK_2)
	{
		map->map->set_angle(map->map, 0.5235, 2.6179);
		mlx_clear_window(map->data.mlx, map->data.win);
		map->map->render(*map->map, map->data);
	}
	else if (key == XK_KP_3 || key == XK_3)
	{
		map->map->set_angle(map->map, 0.73, 0.122173);
		mlx_clear_window(map->data.mlx, map->data.win);
		map->map->render(*map->map, map->data);
	}
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
		handle_arrow_press(key, map);
		handle_num_press(key, map);
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