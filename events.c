/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:32:45 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/14 20:55:49 by caqueiro         ###   ########.fr       */
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
		rerender_map(map);
	}
	else if (key == Button5)
	{
		map->map->config.xzoom--;
		map->map->zoom(map->map, 0.9);
		rerender_map(map);
	}
	return (0);
}
