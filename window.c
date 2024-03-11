/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:53:47 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/11 15:10:09 by caqueiro         ###   ########.fr       */
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
