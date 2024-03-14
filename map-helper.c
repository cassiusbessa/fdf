/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:15:43 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/13 22:38:35 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_map(t_map *map)
{
	map->config.trans_x = (map->window_size.width - map->size.width) / 2;
	map->config.trans_y = (map->window_size.height) / 4;
}
