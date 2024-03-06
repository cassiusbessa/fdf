/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:57:35 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/05 21:14:57 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    view(int angle, t_point *p)
{
    float   rad;

    rad = angle * M_PI / 180.0;
    p->x = (p->x - p->y) * cos(rad);
    p->y = (p->x + p->y) * sin(rad) - p->z;
}

int select_color(t_point p)
{
    if (!p.z)
        return (48485);
    return (0xFFFFFF);
}

void    connect_dots(t_map map, t_mlx_data	mlx_data, int angle)
{
    int     ex;
    int     in;
    t_point p0;
    t_point p1;
    t_point p2;

    ex = 0;
    ft_printf("largura: %d\n", map.size.width);
    ft_printf("alura: %d\n", map.size.height);
    while (ex < map.size.height - 1)
    {
        in = 0;
        while (in < map.size.width - 1)
        {
            p0 = new_point(in * 20, ex * 20, map.coordinates[ex][in], view, angle);
            p1 = new_point((in + 1) * 20, ex * 20, map.coordinates[ex][in + 1], view, angle);
            p2 = new_point(in * 20, (ex + 1) * 20, map.coordinates[ex + 1][in], view, angle);
            bresenham(mlx_data, p0, p1, select_color(p1));
            bresenham(mlx_data, p0, p2, select_color(p2));
            in++;
        }
        ex++;
    }
}

