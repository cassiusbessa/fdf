/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:57:35 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/05 16:46:47 by caqueiro         ###   ########.fr       */
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


void    connect_dots(t_map map, t_mlx_data	mlx_data, int angle)
{
    int     ex;
    int     in;
    t_point p0;
    t_point p1;
    t_point p2;

    ex = 0;
    ft_printf("%d\n", map.size.width);
    while (ex < map.size.height - 1)
    {
        in = 0;
        while (in < map.size.width - 1)
        {
            p0 = new_point(in * 30, ex * 30, map.coordinates[ex][in], NULL, angle);
            p1 = new_point(in * 30, (ex + 1) * 30, map.coordinates[ex][in + 1], NULL, angle);
            p2 = new_point((in + 1) *30 , ex * 30, map.coordinates[ex + 1][in], NULL, angle);
            draw_line2(mlx_data, p0, p1, 48485);
            draw_line2(mlx_data, p0, p2, 48485);
            in++;
        }
        ex++;
    }
}

