/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:53:47 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/13 19:29:34 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_full_screen(void *mlx_ptr, t_mlx_map *m)
{
	t_size	full_screen;

	mlx_get_screen_size(mlx_ptr, &full_screen.width, &full_screen.height);
	m->map->window_size.height = full_screen.height;
	m->map->window_size.width = full_screen.width;
}

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

int	close_window(t_mlx_map *data)
{
	mlx_destroy_image(data->data.mlx, data->img.mlx_img);
	mlx_destroy_window(data->data.mlx, data->data.win);
	mlx_destroy_display(data->data.mlx);
	data->map->destroy(data->map);
	free(data->data.mlx);
	exit(0);
	return (0);
}
