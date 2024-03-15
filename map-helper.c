/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:15:43 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/14 21:01:52 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_map(t_map *map)
{
	map->config.trans_x = (map->window_size.width - map->size.width) / 2;
	map->config.trans_y = (map->window_size.height) / 4;
}

void	rerender_map(t_mlx_map *map)
{
	mlx_destroy_image(map->data.mlx, map->img.mlx_img);
	map->img = new_image(*map);
	map->map->render(*map->map, map->data, &map->img);
	write_commands(map->data);
}
