/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:57:35 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/07 17:41:29 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int select_color(t_point p)
{
    if (!p.z)
        return (48485);
    return (0xFFFFFF);
}

void    render_map(t_map map, t_mlx_data mlx_data)
{
    int     ex;
    int     in;
    t_point p0;
    t_point p1;
    t_point p2;

    ex = 0;
    while (ex < map.size.height - 1)
    {
        in = 0;
        while (in < map.size.width - 1)
        {
            p0 = new_point(in, ex, map.coordinates[ex][in], map);
            p1 = new_point((in + 1), ex, map.coordinates[ex][in + 1], map);
            p2 = new_point(in, (ex + 1), map.coordinates[ex + 1][in], map);
            bresenham(mlx_data, p0, p1, select_color(p1));
            bresenham(mlx_data, p0, p2, select_color(p2));
            in++;
        }
        ex++;
    }
}

