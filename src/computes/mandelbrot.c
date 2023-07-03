/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:54:05 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/03 01:12:07 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	init_mandel_plane(t_fractal *fractal)
{
	fractal->plane->x_pos = 1.8f;
	fractal->plane->x_neg = -2.8f;
	fractal->plane->i_pos = 2.0f;
	fractal->plane->i_neg = -2.0f;
	fractal->plane->x0 = map_range(WIDTH / 2, fractal, 'x');
	fractal->plane->i0 = map_range(HEIGHT / 2, fractal, 'y');
}

void	put_mandel_color(t_fractal *fractal, int diff, int x, int y)
{
	int	color;

	if (diff == 0)
		color = 0x000000;
	else if (diff <= 10)
		color = 0x008FB3;
	else if (diff <= 15)
		color = 0x006600;
	else if (diff <= 40)
		color = 0xFFFFFF;
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
			put_mandel_color(fractal, iter_left, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->win->mlx, fractal->win->win,
		fractal->win->img.img, 0, 0);
}
