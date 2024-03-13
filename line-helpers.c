/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line-helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:20:53 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/12 19:13:19 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

void	draw_pixel(t_mlx_data mlx, int x, int y,
			float brightness)
{
	int	c;

	c = brightness * 255;
	mlx_pixel_put(mlx.mlx, mlx.win, x, y, c);
}

void	set_point_values(int x, int y, t_point *p)
{
	p->x = x;
	p->y = y;
}
