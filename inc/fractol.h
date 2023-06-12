/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:15:20 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/12 20:47:14 by rphuyal          ###   ########.fr       */
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
# define WIDTH 1100
# define HEIGHT 900

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
	int		x0;
	int		i0;
	double	x_pos;
	double	x_neg;
	double	i_pos;
	double	i_neg;
}	t_plane;

// image data
typedef struct s_data {
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
	int		width;
	int		height;
	t_data	img;
}	t_window;

// big daddy
typedef struct s_fractal
{
	t_window	*win;
	t_plane		*plane;
	t_cnum		jconst;
	char		*name;
	int			iter;
	char		*cache;
}	t_fractal;

// fractal's validation
void	*ft_valid_args(char *frac);
bool	initialization(t_fractal *fractal);
int		ft_error(char *heading, char *message);
int		exit_fractal(t_fractal *fractal);

// window functions
void    zoom_in(t_fractal *fractal, int x, int y);
void    zoom_out(t_fractal *fractal, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_background(t_fractal *fractal);
int		get_b(int trgb);
int		gen_trgb(int opacity, int red, int green, int blue);
int		key_hooks(int key_pressed, void *param);
int		mouse_hooks(int button, int mouse_x, int mouse_y, void *param);
int		exit_fractal(t_fractal *fractal);

// cache functions
char	*create_hash_id(int width, int height, char *name);
int		create_cache(t_fractal *fractal);
t_data	*retrive_cache(t_fractal *fractal);

// computation functions
t_cnum		get_cnum(int x, int y, t_fractal *fractal);
void		show_tree(t_fractal *fractal);
void		show_julia(t_fractal *fractal);
void		show_mandelbrot(t_fractal *fractal);
int 		is_julia_stable(t_cnum inum, t_cnum c, int iter);
int			is_mandel_stable(t_cnum inum, int iter);
double		map_range(int num, t_fractal *fractal, char dimension);

#endif