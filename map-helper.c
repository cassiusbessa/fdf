/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:15:43 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/11 21:14:14 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void center_map(t_map *map) {
	float	center_x;
	float	center_y;
	float	map_center_x;
	float	map_center_y;
	
    center_x = map->window_size.width / 2.0;
    center_y = map->window_size.height / 2.0;
	map_center_x = map->size.width / 2.0;
	map_center_y = map->size.height / 2.0;
    float rotated_map_center_x = map_center_x * cos(map->config.angle.x) - map_center_y * sin(map->config.angle.x);
    float rotated_map_center_y = map_center_x * sin(map->config.angle.y) + map_center_y * cos(map->config.angle.y);
    map->config.trans_x = (map->window_size.width - map->size.width) / 2;
    map->config.trans_y = (map->window_size.height) / 5;
}
