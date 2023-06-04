/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:12:02 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/04 20:32:44 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void show_julia(t_fractal *fractal)
{
	int 	x;
	int 	y;
	int		iter_left;
	t_cnum	inum;
    t_cnum  cnum;

	x = 0;
	while (x < fractal->win->width)
	{
		y = 0;
		while (y < fractal->win->height)
		{
			inum.a = map_range(x, 0, fractal->win->width,
						fractal->plane->x_neg, fractal->plane->x_pos + 1.0f);
			inum.b = map_range(y, 0, fractal->win->height,
						fractal->plane->i_pos, fractal->plane->i_neg);
            cnum.a = 0.285f;
            cnum.b = 0.01f;
			iter_left = is_julia_stable(&inum, &cnum, fractal->iter);
			if (!iter_left)
			{
				my_mlx_pixel_put(&fractal->win->img, x, y, 
						gen_trgb(255, 255, 255, 255));
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->win->mlx, fractal->win->win, fractal->win->img.img, 0, 0);
}

// void create_mandelbrot(t_fractal *fractal)
// {
// 	int x;
// 	int y;
// 	int red;
// 	int st;
// 	t_cnum inum;

// 	x = 0;
// 	st = 0;
// 	while (x < fractal->win->width)
// 	{
// 		y = 0;
// 		while (y < fractal->win->height)
// 		{
// 			inum.a = map_range(x, 0, fractal->win->width, -3, 2);
// 			inum.b = map_range(y, 0, fractal->win->height, 2, -2);
// 			st = is_stable(&inum, fractal->iter);
// 			if (st == 0)
// 			{
// 				my_mlx_pixel_put(&fractal->win->img, x, y, 
// 						gen_trgb((int)map_range(st, 0, fractal->iter, 255, 0), 255, 255, 255));
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_put_image_to_window(fractal->win->mlx, fractal->win->win, fractal->win->img.img, 0, 0);
// }