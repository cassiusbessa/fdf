/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:57:35 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/03 17:59:52 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    connect_dots(int **map_3d)
{
    int ex;
    int in;
    int column;
    int lines;

    column = sizeof (map_3d[0]) / sizeof (map_3d[0][0]);
    lines = sizeof (map_3d) / sizeof (map_3d[0]);
}