/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:09:30 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/13 17:15:22 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mlx_config(char *file_name)
{
	t_mlx_map	m;
	t_img		img;

	m.data.mlx = mlx_init();
	if (m.data.mlx == NULL)
		return (1);
	m.map = new_map(file_name);
	get_full_screen(m.data.mlx, &m);
	img = new_image(m);
	m.data.win = mlx_new_window(m.data.mlx, m.map->window_size.width,
			m.map->window_size.height, "fdf");
	center_map(m.map);
	if (m.data.win == NULL)
		return (1);
	mlx_loop_hook(m.data.mlx, &handle_no_event, &m.data);
	mlx_hook(m.data.win, KeyPress, KeyPressMask,
		&handle_key_press, &m);
	mlx_hook(m.data.win, 17, 0, &close_window, &m);
	mlx_hook(m.data.win, KeyRelease, KeyReleaseMask,
		&handle_key_release, &m);
	m.map->render(*m.map, m.data, &img);
	mlx_mouse_hook(m.data.win, &handle_mouse_scroll, &m);
	mlx_loop(m.data.mlx);
}
