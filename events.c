/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:32:45 by caqueiro          #+#    #+#             */
/*   Updated: 2024/02/22 21:46:40 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_key_press(int key, t_mlx_data *mlx_data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	}
	return (0);
}

int	handle_key_release(int key, t_mlx_data *mlx_data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	}
	return (0);
}
