/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:15:20 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/28 20:36:32 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

// libraries
# include <math.h>
# include <string.h>
# include <unistd.h>

// window dimensions
# define WIDTH 1600
# define HEIGHT 1300

// hooks
# define ESC 65307
# define ZOOM_IN 69
# define ZOOM_OUT 78
# define KEYPRESS 2
# define KEYRELEASE 3

// complex numbers
typedef struct s_cnum
{
    double	a;
    double	b;
}	t_cnum;

// complex plane
typedef struct s_plane
{
    double	x;
	double	i;
}	t_plane;

// image data
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// window data
typedef struct s_window
{
    void	*mlx;
    void	*win;
	t_data	img;
    int		width;
    int		height;
}	t_window;

// big daddy
typedef struct s_fractal
{
	t_window	*win;
	t_plane		*plane;
	t_cnum		*cnum;
    char		*name;
    int			iter;
	char		*cache;
}	t_fractal;


// fractal's validation
int		ft_valid_args(char **argv);
bool	initialization(t_fractal *fractal);
int		ft_error(char *heading, char *message);
int		exit_fractal(t_fractal *fractal);

// window functions
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		put_background(t_fractal *fractal);
int		get_b(int trgb);
int		gen_trgb(int opacity, int red, int green, int blue);
int		key_hooks(int key_pressed, void *param);
int		mouse_hooks(int button, int mouse_x, int mouse_y, void *param);
int		exit_fractal(t_fractal *fractal);

// cache functions
char    *create_hash_id(int width, int height, char* name);
int		create_cache(t_fractal *fractal);
t_data	*retrive_cache(t_fractal *fractal);

// computation functions
void	create_mandelbrot(t_fractal *fractal);
int		is_unstable(t_cnum inum, t_cnum z_num, int iter);

#endif