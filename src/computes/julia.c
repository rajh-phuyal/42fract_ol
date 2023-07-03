/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:12:02 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/03 13:37:43 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	init_julia_plane(t_fractal *fractal)
{
	fractal->plane->x_pos = 2.0f;
	fractal->plane->x_neg = -2.0f;
	fractal->plane->i_pos = 2.0f;
	fractal->plane->i_neg = -2.0f;
	fractal->plane->x0 = map_range(WIDTH / 2, fractal, 'x');
	fractal->plane->i0 = map_range(HEIGHT / 2, fractal, 'y');
}

void	put_julia_color(t_fractal *fractal, int diff, int x, int y)
{
	int	color;

	if (diff == 0)
		color = 0x000000;
	else if (diff <= 15)
		color = get_color(255, 0, (255 * diff) / fractal->iter, 0);
	else if (diff <= 25)
		color = get_color(255, (255 * diff) / fractal->iter, 0, 0);
	else if (diff <= 50)
		color = 0xFFFFFF;
	my_mlx_pixel_put(&fractal->win->img, x, y, color);
}

void	show_julia(t_fractal *fractal, bool first)
{
	int		x;
	int		y;
	int		iter_left;

	if (first)
		init_julia_plane(fractal);
	x = 0;
	while (x < fractal->win->width)
	{
		y = 0;
		while (y < fractal->win->height)
		{
			iter_left = is_julia_stable(get_cnum(x, y, fractal),
					fractal->jconst, fractal->iter);
			put_julia_color(fractal, iter_left, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->win->mlx, fractal->win->win,
		fractal->win->img.img, 0, 0);
}
