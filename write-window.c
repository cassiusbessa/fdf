/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write-window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:07:46 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/12 16:16:08 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	write_commands(t_mlx_data data)
{
	mlx_string_put(data.mlx, data.win, 15, 15, 0xFFFFFF,
		"Zoom: Mouse Scroll");
	mlx_string_put(data.mlx, data.win, 15, 30, 0xFFFFFF,
		"Cam: Arrows Keys");
	mlx_string_put(data.mlx, data.win, 15, 45, 0xFFFFFF,
		"Rotate: R");
	mlx_string_put(data.mlx, data.win, 15, 60, 0xFFFFFF,
		"Projections: 0/1/2");
}