/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin-wu-helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:55:25 by caqueiro          #+#    #+#             */
/*   Updated: 2024/02/28 18:05:18 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

void	draw_pixel(t_mlx_data mlx, int x, int y,
			float brightness)
{
	int	c;

	c = brightness * 255;
	mlx_pixel_put(mlx.mlx, mlx.win, x, y, encode_rgb(c, c, c));
}
