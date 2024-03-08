#ifndef FDF_H
# define FDF_H

# define M_PI 3.14159265358979323846
# include "./minilibx-linux/mlx.h"
# include "utils/libft/libft.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_mlx
{
	void    *mlx_ptr;
	void    *win_ptr;
}   t_mlx;

typedef struct s_size
{
	int width;
	int height;
}   t_size;

typedef struct s_mlx_data
{
	void    *mlx;
	void    *win;
}   t_mlx_data;

typedef struct s_point
{
	float x;
	float y;
	float z;
}   t_point;

typedef struct t_mapconfig
{
	int		trans_x;
	int		trans_y;
	float	zoom;
	t_point	angle;
}	t_mapconfig;

typedef struct s_map
{
	t_size  	size;
	int     	**coordinates;
	t_mapconfig	config;
	void		(*transform)(struct s_map *map, int x, int y);
	void		(*zoom)(struct s_map *map, float zoom);
	void		(*set_angle)(struct s_map *map, float x, float y);
	void		(*destroy)(struct s_map *map);
	void		(*render)(struct s_map, t_mlx_data data);
}   t_map;

typedef struct s_mlx_map
{
	t_map		*map;
	t_mlx_data	data;
}	t_mlx_map;

typedef void (*t_point_transform)(float angle, t_point *p);
t_point		new_point(float x, float y, float z, t_map map);

t_map		*new_map(char *file);

t_size		get_full_screen(void *mlx_ptr);
int         handle_no_event(void *data);
int         handle_key_press(int key, t_mlx_map *map);
int         handle_key_release(int key, t_mlx_map *map);
int         mlx_config(void);
int			handle_mouse_scroll(int key,int x, int y, t_mlx_map *map);


int         coordinate_map(char *file_name, t_map *map);
void	    draw_pixel(t_mlx_data mlx, int x, int y,
			float brightness);

void    draw_line2(t_mlx_data m, t_point a, t_point b, int color);
void    bresenham(t_mlx_data m ,t_point a, t_point b, int color);
void    render_map(t_map map, t_mlx_data	mlx_data);
void	destroy_matrix(void **matrix);

#endif