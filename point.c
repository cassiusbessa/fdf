/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:02:12 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/12 19:16:45 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	new_point(float x, float y, float z, t_map map)
{
	t_point	p;

	p.x = (x * map.config.zoom);
	p.y = (y * map.config.zoom);
	p.z = z;
	if (map.config.angle.x != 0.0)
	{
		p.x = ((p.x - p.y) * cos(map.config.angle.x));
		p.y = ((p.x + p.y) * sin(map.config.angle.y) - p.z)
			+ map.config.trans_y;
		p.x += map.config.trans_x;
	}
	else
	{
		p.x += map.config.trans_x;
		p.y += map.config.trans_y;
	}
	return (p);
}
