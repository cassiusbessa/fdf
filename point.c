/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:02:12 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/06 18:31:36 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void    view(float angle, t_point *p)
// {
//     float   rad;

//     rad = angle * M_PI / 180.0;
//     p->x = (p->x - p->y) * cos(angle);
//     p->y = (p->x + p->y) * sin(angle) - p->z;
// }

t_point		new_point(float x, float y, float z, t_map map)
{
	t_point	p;
	p.x = (x * map.config.zoom) + map.config.trans_x;
	p.y = (y * map.config.zoom) + map.config.trans_y;
	p.z = z;
	p.x = (p.x - p.y) * cos(map.config.angle);
	p.y = (p.x + p.y) * sin(map.config.angle) - p.z;
	return (p);
}