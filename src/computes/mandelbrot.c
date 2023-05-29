/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:54:05 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/29 23:59:46 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void create_mandelbrot(t_fractal *fractal)
{
	int x;
	int y;
	int red;
	double st;

	x = 0;
	st = 0;
	while (x < fractal->win->width)
	{
		y = 0;
		while (y < fractal->win->height)
		{
			t_cnum inum = {
				.a = (x - fractal->win->width / 2) * 4.0 / fractal->win->width,
				.b = (y - fractal->win->height / 2) * 4.0 / fractal->win->height
			};
			st = (double)is_stable(inum, *fractal->cnum, fractal->iter);
			if (st > 0)
			{
				red = 255 * (st / fractal->iter);
				my_mlx_pixel_put(&fractal->win->img, x, y, gen_trgb(0, red, 40, 40));
			}
			y++;
		}
		x++;
	}
	// mlx_put_image_to_window(fractal->win->mlx, fractal->win->win, fractal->win->img.img, 0, 0);
}