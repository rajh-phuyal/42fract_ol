/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 01:20:12 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/04 01:56:40 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	init_burningship(t_fractal *fractal)
{
	fractal->plane->x_pos = 2.0f;
	fractal->plane->x_neg = -2.0f;
	fractal->plane->i_pos = 3.0f;
	fractal->plane->i_neg = -2.0f;
	fractal->iter = 100;
}

void	put_burning_color(t_fractal *fractal, int diff, int x, int y)
{
	int	color;

	if (diff == 0)
		color = 0x000000;
	else
		color = get_color(255, 100, (255 * diff) / fractal->iter, 100);
	my_mlx_pixel_put(&fractal->win->img, x, y, color);
}

void	show_tree(t_fractal *fractal, bool first)
{
	int		x;
	int		y;
	int		diff;
	t_cnum	complex;

	if (first)
		init_burningship(fractal);
	x = 0;
	while (x < fractal->win->width)
	{
		y = 0;
		while (y < fractal->win->height)
		{
			complex = get_cnum(x, y, fractal);
			diff = burningship_iteration(complex, complex, fractal->iter);
			put_burning_color(fractal, diff, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->win->mlx, fractal->win->win,
		fractal->win->img.img, 0, 0);
}
