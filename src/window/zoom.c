/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:33:26 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/13 15:16:47 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void    zoom_in(t_fractal *fractal, int x, int y)
{
    fractal->plane->x_pos -= 0.01f;
	fractal->plane->x_neg += 0.01f;
	fractal->plane->i_pos -= 0.01f;
	fractal->plane->i_neg += 0.01f;
    mlx_destroy_image (fractal->win->mlx, fractal->win->img.img);
    fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
    fractal->show(fractal);
}

void    zoom_out(t_fractal *fractal, int x, int y)
{
    fractal->plane->x_pos += 0.01f;
	fractal->plane->x_neg -= 0.01f;
	fractal->plane->i_pos += 0.01f;
	fractal->plane->i_neg -= 0.01f;
    mlx_destroy_image (fractal->win->mlx, fractal->win->img.img);
    fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
    fractal->show(fractal);
}