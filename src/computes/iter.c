/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:26:44 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/25 19:56:45 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

static int is_unstable_my(t_cnum inum, t_cnum z_num, int iter)
{
	t_cnum temp;
	int i;

	i = 0;
	temp = inum;
	while (i++ < iter)
	{
		double temp_a = temp.a;
		double temp_b = temp.b;
		temp.a = temp_a * temp_a - temp_b * temp_b + z_num.a;
		temp.b = 2 * temp_a * temp_b + z_num.b;
		if (temp.a * temp.a + temp.b * temp.b > 4)
			return i;
	}
	return 0;
}

void create_mandelbrot_my(t_fractal *fractal)
{
	int x;
	int y;
	int red;
	double st;

	x = 0;
	while (x < fractal->win->width)
	{
		y = 0;
		while (y < fractal->win->height)
		{
			t_cnum inum = { fractal->plane->x + x * fractal->plane->i, fractal->plane->x + y * fractal->plane->i };
			st = (double)is_unstable(inum, *fractal->num, fractal->iters);
			if (st > 0)
			{
				red = 255 * (st / fractal->iters);
				put_pixel_img(fractal->win->img, x, y, gen_trgb(0, red, 40, 40));
			}
			y++;
		}
		x++;
	}
}

int	iter_equation(int z, int c)
{
	int	start;
	int	iterations;

	start = 0;
	iterations = 100;
	while (start < iterations)
	{
		z = (z * z) + c;
		if (z * z > 4)
			break ;
		start++;
	}
	return (0);
}
