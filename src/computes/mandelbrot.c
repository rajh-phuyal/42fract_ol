/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:54:05 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/02 20:39:59 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	init_mandel_plane(t_fractal *fractal)
{
	fractal->plane->x_pos = 2.0f;
	fractal->plane->x_neg = -3.0f;
	fractal->plane->i_pos = 2.0f;
	fractal->plane->i_neg = -2.0f;
	fractal->plane->x0 = map_range(WIDTH / 2, fractal, 'x');
	fractal->plane->i0 = map_range(HEIGHT / 2, fractal, 'x');
}

void	put_color(t_fractal *fractal, int diff, int x, int y)
{
	int	color;

	if (diff == 0)
		color = 0x00000a;
	else if (diff <= 30)
		color = 0x2952a3;
	else
		color = gen_trgb(255, (diff * 255) / diff, 0, 0);
	my_mlx_pixel_put(&fractal->win->img, x, y, color);
}

void	show_mandelbrot(t_fractal *fractal, bool first)
{
	int		x;
	int		y;
	int		iter_left;

	if (first)
		init_mandel_plane(fractal);
	x = 0;
	while (x < fractal->win->width)
	{
		y = 0;
		while (y < fractal->win->height)
		{
			iter_left = is_mandel_stable(get_cnum(x, y, fractal),
					fractal->iter);
			put_color(fractal, iter_left, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->win->mlx, fractal->win->win,
		fractal->win->img.img, 0, 0);
}
