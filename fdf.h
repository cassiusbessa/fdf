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

t_window    get_full_screen(void *mlx_ptr);
int         handle_no_event(void *data);
int         handle_key_press(int key, t_mlx_data *mlx_data);
int         handle_key_release(int key, t_mlx_data *mlx_data);
int         mlx_config(void);
int         map3d_generator(char *file_name);

#endif