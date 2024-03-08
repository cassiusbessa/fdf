/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:09:30 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/07 20:14:06 by caqueiro         ###   ########.fr       */
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
	window = get_full_screen(m.data.mlx);
	m.data.win = mlx_new_window(m.data.mlx, window.width,
			window.height, "fdf");
	if (m.data.win == NULL)
		return (1);
	mlx_loop_hook(m.data.mlx, &handle_no_event, &m.data);
	mlx_hook(m.data.win, KeyPress, KeyPressMask,
		&handle_key_press, &m);
	mlx_hook(m.data.win, KeyRelease, KeyReleaseMask,
		&handle_key_release, &m);
	m.map = new_map("42-a.fdf");
	m.map->render(*m.map, m.data);
	mlx_mouse_hook(m.data.win, &handle_mouse_scroll, &m);
	mlx_loop(m.data.mlx);
	mlx_destroy_display(m.data.mlx);
	free(m.data.mlx);
}
