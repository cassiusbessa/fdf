/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:26:44 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/14 20:31:38 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	new_image(t_mlx_map m)
{
	t_img	img;

	img.mlx_img = mlx_new_image(m.data.mlx, m.map->window_size.width * 2,
		m.map->window_size.height * 2);
	
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
	return (img);
}

int	select_color(int z)
{
	if (!z)
		return (48485);
	return (0xFFFFFF);
}

void	img_pix_put(t_img *img, int x, int y, int z)
{
    char    *pixel;
    int		i;
	int		color;
    i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	color = select_color(z);
    while (i >= 0)
    {
        if (img->endian != 0 && pixel > img->addr)
            *pixel++ = (color >> i) & 0xFF;
        else if (pixel > img->addr)
            *pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
        i -= 8;
    }
}