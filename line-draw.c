/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line-draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:13:43 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/05 19:41:18 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int max_n(float a, float b)
{
    if (a > b)
        return (a);
    return (b);
}

static float mod_n(float i)
{
    if (i < 0)
        return (-i);
    return (i);
}

void    bresenham(t_mlx_data m ,t_point a, t_point b, int color)
{
    float   x_step;
    float   y_step;
    int     max;
    printf("a:(x: %f, y: %f)\n", a.x, a.y);
    printf("b:(x: %f, y: %f)\n", b.x, b.y);
    x_step = b.x - a.x;
    y_step = b.y - a.y;
    max = max_n(mod_n(x_step), mod_n(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(a.x - b.x) || (int)(a.y - b.y))
    {
        mlx_pixel_put(m.mlx, m.win, a.x, a.y, color);
        a.x += x_step;
        a.y += y_step;
    }
}
