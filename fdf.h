#ifndef FDF_H
# define FDF_H

# include "./minilibx-linux/mlx.h"
# include "utils/libft/libft.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
typedef struct s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
}   t_mlx;

typedef struct s_window
{
    int width;
    int height;
}   t_window;

typedef struct s_mlx_data
{
    void    *mlx;
    void    *win;
}   t_mlx_data;

typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct s_delta
{
    float   dx;
    float   dy;
    float     gradient;
}   t_delta;


t_window    get_full_screen(void *mlx_ptr);
int         handle_no_event(void *data);
int         handle_key_press(int key, t_mlx_data *mlx_data);
int         handle_key_release(int key, t_mlx_data *mlx_data);
int         mlx_config(void);
int         map3d_generator(char *file_name);
void	    draw_pixel(t_mlx_data mlx, int x, int y,
			float brightness);
void set_delta_values(t_point p0, t_point p1, t_delta *d);


float	absolute(float x);
int     int_part(float x);
float	one_less_float_part(float x);
float	float_part(float x);

int	    calculate_steep(t_point *p0, t_point *p1);
void	draw_line(t_point *p0, t_point *p1, t_mlx_data m);

#endif