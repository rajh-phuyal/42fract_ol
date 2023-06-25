/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:33:26 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/25 15:53:05 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void    change_center(t_fractal *fractal, int x, int y);

void    zoom_in(t_fractal *fractal, int x, int y)
{
    fractal->plane->x_pos -= 0.1f;
	fractal->plane->x_neg += 0.1f;
	fractal->plane->i_pos -= 0.1f;
	fractal->plane->i_neg += 0.1f;
    mlx_destroy_image (fractal->win->mlx, fractal->win->img.img);
    fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
    fractal->show(fractal);
}

void    zoom_out(t_fractal *fractal, int x, int y)
{
    // fractal->win->height = (fractal->plane->x_pos - fractal->plane->x_neg);
    // fractal->win->width = (fractal->plane->i_pos - fractal->plane->i_neg);
    fractal->plane->x_pos += 0.1f;
	fractal->plane->x_neg -= 0.1f;
	fractal->plane->i_pos += 0.1f;
	fractal->plane->i_neg -= 0.1f;
    fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
    mlx_destroy_image (fractal->win->mlx, fractal->win->img.img);
    fractal->show(fractal);
}