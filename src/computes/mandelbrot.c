/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:54:05 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/04 20:32:49 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void show_mandelbrot(t_fractal *fractal)
{
	int 	x;
	int 	y;
	int		iter_left;
	t_cnum	inum;

	x = 0;
	while (x < fractal->win->width)
	{
		y = 0;
		while (y < fractal->win->height)
		{
			inum.a = map_range(x, 0, fractal->win->width,
						fractal->plane->x_neg, fractal->plane->x_pos);
			inum.b = map_range(y, 0, fractal->win->height,
						fractal->plane->i_pos, fractal->plane->i_neg);
			iter_left = is_stable(&inum, fractal->iter);
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