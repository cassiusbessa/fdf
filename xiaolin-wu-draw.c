/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin-wu-draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:13:43 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/05 15:57:12 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void static	draw_with_step(t_mlx_data m, t_point p0, t_point p1, t_delta d)
{
	int		xpxl1;
	int		xpxl2;
	float	intersect_y;

	xpxl1 = p0.x;
	xpxl2 = p1.x;
	intersect_y = p0.y;
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

void static	draw_without_step(t_mlx_data m, t_point p0, t_point p1, t_delta d)
{
	int		xpxl1;
	int		xpxl2;
	float	intersect_y;

	xpxl1 = p0.x;
	xpxl2 = p1.x;
	intersect_y = p0.y;
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
		draw_with_step(m, *p0, *p1, d);
	else
		draw_without_step(m, *p0, *p1, d);
}

void    draw_line2(t_mlx_data m, t_point a, t_point b, int color)
{
    double	delta_x;
    double	delta_y;
    int		pixels;

	// printf("x: %f, y: %f\n", a.x, a.y);
	// printf("x: %f, y: %f\n", b.x, b.y);
    delta_x = b.x - a.x;
    delta_y = b.y - a.y;
    pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
    delta_x /= pixels;
    delta_y /= pixels;
    double pixel_x = a.x;
    double pixel_y = a.y;
    while (pixels)
    {
        mlx_pixel_put(m.mlx, m.win, pixel_x, pixel_y, color);
        pixel_x += delta_x;
        pixel_y += delta_y;
        --pixels;
    }
}
