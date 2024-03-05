/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:02:12 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/04 21:40:27 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		new_point(float x, float y, float z,
			t_point_transform transform_function, int angle)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = z;
	//printf("x: %f, y: %f, z: %f\n", x, y, z);
	if (transform_function != NULL)
		transform_function(angle, &p);
	return (p);
}