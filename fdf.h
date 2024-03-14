/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:21:06 by caqueiro          #+#    #+#             */
/*   Updated: 2024/03/14 20:55:02 by caqueiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx-linux/mlx.h"
# include "utils/libft/libft.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_size
{
	int	width;
	int	height;
}	t_size;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	t_size	window_size;
}	t_mlx_data;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct t_mapconfig
{
	int		trans_x;
	int		trans_y;
	float	zoom;
	int		xzoom;
	t_point	angle;
}	t_mapconfig;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	t_size		size;
	t_size		window_size;
	int			**coordinates;
	t_mapconfig	config;
	void		(*transform)(struct s_map *map, int x, int y);
	void		(*zoom)(struct s_map *map, float zoom);
	void		(*set_angle)(struct s_map *map, float x, float y);
	void		(*destroy)(struct s_map *map);
	void		(*render)(struct s_map, t_mlx_data data, t_img *img);
}	t_map;

typedef struct s_mlx_map
{
	t_map		*map;
	t_mlx_data	data;
	t_img		img;
}	t_mlx_map;

t_point		new_point(float x, float y, float z, t_map map);

t_map		*new_map(char *file);
void		center_map(t_map *map);
void		rerender_map(t_mlx_map *map);

void		get_full_screen(void *mlx_ptr, t_mlx_map *m);
int			handle_no_event(void *data);
int			handle_key_press(int key, t_mlx_map *map);
int			handle_key_release(int key, t_mlx_map *map);
int			mlx_config(char *file_name);
int			handle_mouse_scroll(int key, int x, int y, t_mlx_map *map);
void		write_commands(t_mlx_data data);

int			coordinate_map(char *file_name, t_map *map);
void		draw_pixel(t_mlx_data mlx, int x, int y,
				float brightness);
t_img		new_image(t_mlx_map m);
void		img_pix_put(t_img *img, int x, int y, int z);
void		bresenham(t_mlx_data m, t_point a, t_point b, t_img *img);
void		render_map(t_map map, t_mlx_data mlx_data, t_img *img);
void		destroy_matrix(void **matrix);
int			close_window(t_mlx_map *data);

#endif