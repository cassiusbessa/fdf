/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line-draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:13:43 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/14 21:01:35 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	max_n(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

static float	mod_n(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	bresenham(t_mlx_data m, t_point a, t_point b, t_img *img)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = max_n(mod_n(x_step), mod_n(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if (m.window_size.height < (int)a.y || m.window_size.width < (int)a.x)
			return ;
		img_pix_put(img, a.x, a.y, a.z);
		a.x += x_step;
		a.y += y_step;
	}
}
