/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:09:30 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/11 21:14:32 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mlx_config(void)
{
	t_size		window;
	t_mlx_map	m;

	m.data.mlx = mlx_init();
	if (m.data.mlx == NULL)
		return (1);
	m.map = new_map("42-a.fdf");
	get_full_screen(m.data.mlx, &m);
	m.data.win = mlx_new_window(m.data.mlx, m.map->window_size.width,
			m.map->window_size.height, "fdf");
	center_map(m.map);
	if (m.data.win == NULL)
		return (1);
	mlx_loop_hook(m.data.mlx, &handle_no_event, &m.data);
	mlx_hook(m.data.win, KeyPress, KeyPressMask,
		&handle_key_press, &m);
	mlx_hook(m.data.win, KeyRelease, KeyReleaseMask,
		&handle_key_release, &m);
	m.map->render(*m.map, m.data);
	mlx_mouse_hook(m.data.win, &handle_mouse_scroll, &m);
	mlx_loop(m.data.mlx);
	mlx_destroy_display(m.data.mlx);
	free(m.data.mlx);
}
