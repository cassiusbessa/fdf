/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:32:45 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/13 23:15:24 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_mouse_scroll(int key, int x, int y, t_mlx_map *map)
{
	if (key == Button4)
	{
		if (map->map->config.xzoom > 35)
			return (0);
		map->map->config.xzoom++;
		map->map->zoom(map->map, 1.1);
		mlx_destroy_image(map->data.mlx, map->img.mlx_img);
		map->img = new_image(*map);
		map->map->render(*map->map, map->data, &map->img);
		write_commands(map->data);
	}
	else if (key == Button5)
	{
		map->map->config.xzoom--;
		map->map->zoom(map->map, 0.9);
		mlx_destroy_image(map->data.mlx, map->img.mlx_img);
		map->img = new_image(*map);
		map->map->render(*map->map, map->data, &map->img);
		write_commands(map->data);
	}
	return (0);
}
