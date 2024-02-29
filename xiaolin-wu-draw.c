/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin-wu-draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:13:43 by caqueiro          #+#    #+#             */
/*   Updated: 2024/02/29 20:50:04 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point *p0, t_point *p1, t_mlx_data m)
{
	int		steep;
	t_delta	d;
	int		xpxl1;
	int		xpxl2;
	float	intersect_y;

	steep = calculate_steep(p0, p1);
	set_delta_values(*p0, *p1, &d);
	xpxl1 = p0->x;
	xpxl2 = p1->x;
	intersect_y = p0->y;
	if (steep)
	{
		while (xpxl1 <= xpxl2)
		{
			draw_pixel(m, int_part(intersect_y), xpxl1,
				one_less_float_part(intersect_y));
			draw_pixel(m, int_part(intersect_y) - 1, xpxl1,
				float_part(intersect_y));
			intersect_y += d.gradient;
			xpxl1++;
		}
	}
	else
	{
		while (xpxl1 <= xpxl2)
		{
			draw_pixel(m, xpxl1, int_part(intersect_y),
				one_less_float_part(intersect_y));
			draw_pixel(m, xpxl1, int_part(intersect_y) - 1,
				float_part(intersect_y));
			intersect_y += d.gradient;
			xpxl1++;
		}
	}
}

void static	draw_with_step(t_mlx_data m, int xpxl1, int xpxl2, float intersect_y, float gradient)
{
		while (xpxl1 <= xpxl2)
		{
			draw_pixel(m, int_part(intersect_y), xpxl1,
				one_less_float_part(intersect_y));
			draw_pixel(m, int_part(intersect_y) - 1, xpxl1,
				float_part(intersect_y));
			intersect_y += gradient;
			xpxl1++;
		}
}
