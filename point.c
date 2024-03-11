/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:02:12 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/11 17:38:49 by caqueiro         ###   ########.fr       */
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

t_point	new_point(float x, float y, float z, t_map map)
{
	t_point	p;

	p.x = (x * map.config.zoom);
    p.y = (y * map.config.zoom);
    p.z = z;
    if (map.config.angle.x != 0.0)
	{
		p.x = ((p.x - p.y) * cos(map.config.angle.x)) + map.config.trans_x;
		p.y = ((p.x + p.y) * sin(map.config.angle.y) - p.z) + map.config.trans_y;
	}
	return (p);
}
