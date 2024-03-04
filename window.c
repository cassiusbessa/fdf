/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:53:47 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/04 17:08:53 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_size	get_full_screen(void *mlx_ptr)
{
	t_size	full_screen;

	mlx_get_screen_size(mlx_ptr, &full_screen.width, &full_screen.height);
	return (full_screen);
}
