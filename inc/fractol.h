/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:15:20 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/04 00:18:22 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./hooks.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"

// libraries
# include <math.h>

// window dimensions
# define WIDTH 900
# define HEIGHT 800

// complex numbers
typedef struct s_cnum
{
	double	a;
	double	b;
}	t_cnum;

// complex plane
typedef struct s_plane
{
	double	x0;
	double	i0;
	double	x_pos;
	double	x_neg;
	double	i_pos;
	double	i_neg;
}	t_plane;

// image data
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

// window data
typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_img	img;
}	t_window;

// big daddy
typedef struct s_fractal t_fractal;

typedef struct s_fractal
{
	t_window	*win;
	t_plane		*plane;
	t_cnum		jconst;
	char		*name;
	int			iter;
	void		(*show)(t_fractal *, bool);
}	t_fractal;


// fractal's validation
void		*ft_valid_args(char *frac);
bool	initialization(t_fractal *fractal);
t_window	*get_window(char *name);
t_img		get_image(t_window *win, int width, int height);
int		ft_error(char *heading, char *message);
int		exit_fractal(t_fractal *fractal);

// window functions
void    zoom_in(t_fractal *fractal, double x, double y);
void    zoom_out(t_fractal *fractal, double x, double y);
int    change_center(t_fractal *fractal, double val, int key);
void	render_again(t_fractal *fractal);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	put_background(t_fractal *fractal);
int		get_b(int trgb);
int		get_color(int op, int r, int g, int b);
int		key_hooks(int key_pressed, void *param);
int		mouse_hooks(int button, int mouse_x, int mouse_y, void *param);
int		exit_fractal(t_fractal *fractal);

// computation functions
t_cnum		get_cnum(int x, int y, t_fractal *fractal);
void		show_tree(t_fractal *fractal, bool first);
void		show_julia(t_fractal *fractal, bool first);
void		show_mandelbrot(t_fractal *fractal, bool first);
int 		is_julia_stable(t_cnum inum, t_cnum c, int iter);
int			is_mandel_stable(t_cnum inum, int iter);
int			is_bs_stable(t_cnum inum, t_cnum const_c, int iter);
double		map_range(int num, t_fractal *fractal, char dimension);

#endif