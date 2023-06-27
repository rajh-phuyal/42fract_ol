/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:33:26 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/25 18:10:13 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void    change_center(t_fractal *fractal, int x, int y)
{
    printf("WHAT IS X: %f\n", map_range(x, fractal, 'x'));
    printf("WHAT IS Y: %f\n", map_range(y, fractal, 'y'));
    fractal->plane->x_pos = map_range(x, fractal, 'x') + 0.5f;
    fractal->plane->x_neg = map_range(x, fractal, 'x') - 1.0f;
    fractal->plane->i_pos = map_range(y, fractal, 'y') + 0.5f;
    fractal->plane->i_neg = map_range(y, fractal, 'y') - 0.5f;
    mlx_destroy_image (fractal->win->mlx, fractal->win->img.img);
    fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
    fractal->show(fractal, false);
}

void    zoom_in(t_fractal *fractal, int x, int y)
{
    change_center(fractal, x, y);
    fractal->plane->x_pos -= 0.1f;
    fractal->plane->x_neg += 0.1f;
	fractal->plane->i_pos -= 0.1f;
	fractal->plane->i_neg += 0.1f;
    mlx_destroy_image(fractal->win->mlx, fractal->win->img.img);
    fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
    fractal->show(fractal, false);
}

void    zoom_out(t_fractal *fractal, int x, int y)
{
    change_center(fractal, x, y);
    fractal->plane->x_pos += 0.1f;
	fractal->plane->x_neg -= 0.1f;
	fractal->plane->i_pos += 0.1f;
	fractal->plane->i_neg -= 0.1f;
    mlx_destroy_image(fractal->win->mlx, fractal->win->img.img);
    fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
    fractal->show(fractal, false);
}