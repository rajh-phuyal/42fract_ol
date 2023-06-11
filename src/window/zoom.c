/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:33:26 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/11 17:20:12 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void    zoom_in(t_fractal *fractal)
{
    fractal->win->width = 1600;
    fractal->win->height = 1400;
    
    show_mandelbrot(fractal);
    
}

void    zoom_out(t_fractal *fractal)
{
    fractal->win->width = 600;
    fractal->win->height = 400;
    
    show_mandelbrot(fractal);
    
}