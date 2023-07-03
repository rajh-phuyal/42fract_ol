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

// void    change_center(t_fractal *fractal, int x, int y)
// {
//     printf("WHAT IS X: %f\n", map_range(x, fractal, 'x'));
//     printf("WHAT IS Y: %f\n", map_range(y, fractal, 'y'));
//     fractal->plane->x0 = map_range(x, fractal, 'x');
// 	fractal->plane->i0 = map_range(y, fractal, 'y');
//     fractal->plane->x_pos = fractal->plane->x0;
//     fractal->plane->x_neg = fractal->plane->x0 - 2.0f;
//     fractal->plane->i_pos = fractal->plane->i0;
//     fractal->plane->i_neg = fractal->plane->i0 - 2.0f;
//     mlx_destroy_image (fractal->win->mlx, fractal->win->img.img);
//     fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
//     fractal->show(fractal, false);
// }

void    zoom_in(t_fractal *fractal, double x, double y)
{
    fractal->plane->x_pos -= 0.4f;
    fractal->plane->x_neg += 0.4f;
	fractal->plane->i_pos -= 0.4f;
	fractal->plane->i_neg += 0.4f;
    mlx_destroy_image(fractal->win->mlx, fractal->win->img.img);
    fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
    fractal->show(fractal, false);
}

void    zoom_out(t_fractal *fractal, double x, double y)
{
    fractal->plane->x_pos += 0.4f;
	fractal->plane->x_neg -= 0.4f;
	fractal->plane->i_pos += 0.4f;
	fractal->plane->i_neg -= 0.4f;
    // mlx_clear_window(fractal->win->mlx, fractal->win);
    // fractal->show(fractal, false);
    // mlx_put_image_to_window(fractal->win->mlx, fractal->win, fractal->win->img.img, 0, 0);
    mlx_destroy_image(fractal->win->mlx, fractal->win->img.img);
    fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
    fractal->show(fractal, false);
}