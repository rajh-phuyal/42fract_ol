/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:33:26 0.1f rphuyal           #+#    #+#             */
/*   Updated: 2023/07/02 19:41:47 0.1f rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void    change_center(t_fractal *fractal, double x, double y)
{
    double  x0;
    double  i0;
    static double  xPrev = 0;
    static double  iPrev = 0;

    x0 = map_range(x, fractal, 'x');
    i0 = map_range(y, fractal, 'y');
    fractal->plane->x_pos = x0 + (fractal->plane->x_pos - fractal->plane->x0);
    fractal->plane->x_neg = x0 + (fractal->plane->x_neg - fractal->plane->x0);
    fractal->plane->i_pos = i0 + (fractal->plane->i_pos - fractal->plane->i0);
    fractal->plane->i_neg = i0 + (fractal->plane->i_neg - fractal->plane->i0);
    fractal->plane->x0 = x0;
    fractal->plane->i0 = i0;
}

void    zoom_in(t_fractal *fractal, double x, double y)
{
    static double  xPrev = 0;
    static double  iPrev = 0;
    change_center(fractal, x, y);
    fractal->plane->x_pos -= 0.2f;
    fractal->plane->x_neg += 0.2f;
	fractal->plane->i_pos -= 0.2f;
	fractal->plane->i_neg += 0.2f;
    mlx_destroy_image(fractal->win->mlx, fractal->win->img.img);
    fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
    fractal->show(fractal, false);
}

void    zoom_out(t_fractal *fractal, double x, double y)
{
    change_center(fractal, x, y);
    fractal->plane->x_pos += 0.2f;
	fractal->plane->x_neg -= 0.2f;
	fractal->plane->i_pos += 0.2f;
	fractal->plane->i_neg -= 0.2f;
    mlx_destroy_image(fractal->win->mlx, fractal->win->img.img);
    fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
    fractal->show(fractal, false);
}