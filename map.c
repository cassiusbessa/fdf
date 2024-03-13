/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:20:39 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/13 18:33:30 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	transform_map(t_map *map, int x, int y)
{
	map->config.trans_x += x;
	map->config.trans_y += y;
}

static void	zoom_map(t_map *map, float zoom)
{
	map->config.zoom *= zoom;
}

static void	set_angle(t_map *map, float x, float y)
{
	map->config.angle.x = x;
	map->config.angle.y = y;
	center_map(map);
}

static void	destroy(t_map *map)
{
	destroy_matrix((void **)map->coordinates);
	free(map);
}

t_map	*new_map(char *file)
{
	t_map	*map;

	map = (t_map *)ft_calloc(sizeof (t_map), 1);
	coordinate_map(file, map);
	map->destroy = destroy;
	map->set_angle = set_angle;
	map->transform = transform_map;
	map->zoom = zoom_map;
	map->render = render_map;
	map->config.angle.x = 0.8;
	map->config.angle.y = 0.8;
	map->config.zoom = 40 / ((float)(map->size.width * map->size.height) / 209);
	if (map->config.zoom < 1)
		map->config.zoom++;
	return (map);
}
