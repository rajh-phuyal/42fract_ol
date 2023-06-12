/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:33:26 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/12 20:49:01 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void    zoom_in(t_fractal *fractal, int x, int y)
{
    fractal->plane->x_pos -= map_range(x, fractal, 'x');
	fractal->plane->x_neg += map_range(x, fractal, 'x');
	fractal->plane->i_pos -= map_range(y, fractal, 'y');
	fractal->plane->i_neg += map_range(y, fractal, 'y');
    show_mandelbrot(fractal);
    
}

void    zoom_out(t_fractal *fractal, int x, int y)
{
    fractal->win->width = 600;
    fractal->win->height = 400;
    
    show_mandelbrot(fractal);
}