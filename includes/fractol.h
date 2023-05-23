/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:15:20 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/23 17:43:25 by rphuyal          ###   ########.fr       */
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

// defines
# define WIDTH 800
# define HEIGHT 600

// helper lists
typedef struct s_window
{
    void	*mlx;
    void	*win;
    int		width;
    int		height;
}	t_window;

typedef struct s_cnum
{
    double	a;
    double	b;
}	t_cnum;

typedef struct s_complex
{
    double	x;
	double	i;
}	t_complex;

typedef struct s_fractal
{
	t_window	*win;
	t_complex	*plain;
	t_cnum		*num;
}	t_fractal;

// input validation
int	ft_valid_args(char **argv);
void initialization(char *str);
int	ft_error(char *heading, char *message);

#endif