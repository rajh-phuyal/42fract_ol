/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:54:05 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/04 14:56:11 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	init_mandelelbrot(t_fractal *fractal)
{
	fractal->plane->x_pos = 1.8f;
	fractal->plane->x_neg = -2.8f;
	fractal->plane->i_pos = 2.0f;
	fractal->plane->i_neg = -2.0f;
	fractal->iter = 80;
}

void	color_mandelelbrot(t_fractal *fractal, int diff, int x, int y)
{
	int	color;

	if (diff == 0)
		color = 0x000000;
	else if (diff <= 10)
		color = get_color(255, 0, 0, (255 * diff) / fractal->iter);
	else if (diff <= 15)
		color = get_color(255, (255 * diff) / fractal->iter, 0, 0);
	else
		color = get_color(255, 0, (255 * diff) / fractal->iter, 0);
	my_mlx_pixel_put(&fractal->win->img, x, y, color);
}

void	show_mandelbrot(t_fractal *fractal, bool first)
{
	int		x;
	int		y;
	int		diff;
	t_cnum	complex;

	if (first)
		init_mandelelbrot(fractal);
	x = 0;
	while (x < fractal->win->width)
	{
		y = 0;
		while (y < fractal->win->height)
		{
			complex = get_cnum(x, y, fractal);
			diff = mandelbrot_iteration(complex, fractal->iter);
			color_mandelelbrot(fractal, diff, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->win->mlx, fractal->win->win,
		fractal->win->img.img, 0, 0);
}
