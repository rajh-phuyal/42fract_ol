/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:12:02 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/13 15:36:30 by rphuyal          ###   ########.fr       */
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
	fractal->plane->i0 = map_range(HEIGHT / 2, fractal, 'x');
}

void	put_color(t_fractal *fractal, int diff, int x, int y);

void	show_julia(t_fractal *fractal, bool first)
{
	int		x;
	int		y;
	int		iter_left;

	if (first)
		init_julia_plane(fractal);
	x = 0;
	// fractal->plane->x_neg += 1;
	while (x < fractal->win->width)
	{
		y = 0;
		while (y < fractal->win->height)
		{
			iter_left = is_julia_stable(get_cnum(x, y, fractal),
					fractal->jconst, fractal->iter);
			put_color(fractal, iter_left, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->win->mlx, fractal->win->win,
		fractal->win->img.img, 0, 0);
}
