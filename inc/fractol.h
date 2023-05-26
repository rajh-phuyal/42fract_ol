/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:15:20 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/26 21:00:24 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

// defines
# define WIDTH 1500
# define HEIGHT 1500

# define KEYPRESS 2
# define KEYRELEASE 3
# define ESC 65307
# define ZOOM_IN 69
# define ZOOM_OUT 78

typedef struct s_cnum
{
    double	a;
    double	b;
}	t_cnum;

typedef struct s_plane
{
    double	x;
	double	i;
}	t_plane;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// helper lists
typedef struct s_window
{
    void	*mlx;
    void	*win;
	t_data	img;
    int		width;
    int		height;
}	t_window;

typedef struct s_fractal
{
	t_window	*win;
	t_plane		*plane;
	t_cnum		*num;
    char		*name;
    int			iters;
}	t_fractal;


// input validation
int		ft_valid_args(char **argv);
bool	initialization(t_fractal *fractal);
int		ft_error(char *heading, char *message);
int		exit_fractal(t_fractal *fractal);

// for window
int     put_background(t_fractal *fractal);
int	    gen_trgb(int opacity, int red, int green, int blue);
int		key_hooks(int key_pressed, void *param);
int		mouse_hooks(int button, int mouse_x, int mouse_y, void *param);
int		exit_fractal(t_fractal *fractal);

#endif