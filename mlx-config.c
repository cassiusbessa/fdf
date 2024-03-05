/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:09:30 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/05 16:58:38 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mlx_config(void)
{
	t_mlx_data	mlx_data;
	t_size		window;
	t_point		a;
	t_point		b;
	t_map		*map;

	mlx_data.mlx = mlx_init();
	if (mlx_data.mlx == NULL)
		return (1);
	window = get_full_screen(mlx_data.mlx);
	mlx_data.win = mlx_new_window(mlx_data.mlx, window.width,
			window.height, "fdf");
	if (mlx_data.win == NULL)
		return (1);
	mlx_loop_hook(mlx_data.mlx, &handle_no_event, &mlx_data);
	mlx_hook(mlx_data.win, KeyPress, KeyPressMask,
		&handle_key_press, &mlx_data);
	mlx_hook(mlx_data.win, KeyRelease, KeyReleaseMask,
		&handle_key_release, &mlx_data);
	map = (t_map *)ft_calloc(sizeof (t_map), 1);
	map3d_generator("42.fdf", map);
	connect_dots(*map, mlx_data, 30);
	destroy_matrix(map->coordinates);
	free(map);
	mlx_loop(mlx_data.mlx);
	mlx_destroy_display(mlx_data.mlx);
	free(mlx_data.mlx);
}
