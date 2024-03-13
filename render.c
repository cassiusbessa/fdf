/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:57:35 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/12 23:03:43 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	select_color(t_point p)
// {
// 	if (!p.z)
// 		return (48485);
// 	return (0xFFFFFF);
// }

static void	prepare_map(t_mlx_data mlx_data)
{
	mlx_clear_window(mlx_data.mlx, mlx_data.win);
	write_commands(mlx_data);
}

void	render_map(t_map map, t_mlx_data mlx_data, t_img *img)
{
	int		ex;
	int		in;
	t_point	p0;
	t_point	p1;

	prepare_map(mlx_data);
	ex = -1;
	while (++ex < map.size.height)
	{
		in = -1;
		while (++in < map.size.width)
		{
			p0 = new_point(in, ex, map.coordinates[ex][in], map);
			if (in + 1 < map.size.width)
			{
				p1 = new_point((in + 1), ex, map.coordinates[ex][in + 1], map);
				bresenham(mlx_data, p0, p1, img);
			}
			if (ex + 1 < map.size.height)
			{
				p1 = new_point(in, (ex + 1), map.coordinates[ex + 1][in], map);
				bresenham(mlx_data, p0, p1, img);
			}
		}
	}
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, img->mlx_img, 0, 0);
}
