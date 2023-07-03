/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:00:03 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/04 00:14:28 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	render_again(t_fractal *fractal)
{
	mlx_destroy_image(fractal->win->mlx, fractal->win->img.img);
	fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
	fractal->show(fractal, false);
}

int change_center(t_fractal *fractal, double val, int key)
{
    if (key == UP)
	{
        fractal->plane->i_pos += val;
        fractal->plane->i_neg += val;
		return (1);
	}
	else if (key == DOWN)
	{
		fractal->plane->i_pos -= val;
        fractal->plane->i_neg -= val;
		return (1);
	}
	else if (key == LEFT)
	{
		fractal->plane->x_pos -= val;
        fractal->plane->x_neg -= val;
		return (1);
	}
	else if (key == RIGHT)
	{
        fractal->plane->x_pos += val;
        fractal->plane->x_neg += val;
		return (1);
	}
    return (0);
}

void    zoom_in(t_fractal *fractal, double x, double y)
{
    double x_mouse;
    double y_mouse;

    x_mouse = map_range(x, fractal, 'x');
    y_mouse = map_range(y, fractal, 'y');
    fractal->plane->x_pos = (fractal->plane->x_pos - x_mouse) / 1.5f + x_mouse;
    fractal->plane->x_neg = (fractal->plane->x_neg - x_mouse) / 1.5f + x_mouse;
    fractal->plane->i_pos = (fractal->plane->i_pos - y_mouse) / 1.5f + y_mouse;
    fractal->plane->i_neg = (fractal->plane->i_neg - y_mouse) / 1.5f + y_mouse;
    render_again(fractal);
}

void    zoom_out(t_fractal *fractal, double x, double y)
{
    double x_mouse;
    double y_mouse;

    x_mouse = map_range(x, fractal, 'x');
    y_mouse = map_range(y, fractal, 'y');
    fractal->plane->x_pos = (fractal->plane->x_pos - x_mouse) * 1.5f + x_mouse;
    fractal->plane->x_neg = (fractal->plane->x_neg - x_mouse) * 1.5f + x_mouse;
    fractal->plane->i_pos = (fractal->plane->i_pos - y_mouse) * 1.5f + y_mouse;
    fractal->plane->i_neg = (fractal->plane->i_neg - y_mouse) * 1.5f + y_mouse;
    render_again(fractal);
}