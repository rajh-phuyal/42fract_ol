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

void	show_julia(t_fractal *fractal)
{
	int		x;
	int		y;
	int		iter_left;

	x = 0;
	// fractal->plane->x_neg += 1;
	while (x < fractal->win->width)
	{
		y = 0;
		while (y < fractal->win->height)
		{
			iter_left = is_julia_stable(get_cnum(x, y, fractal),
					fractal->jconst, fractal->iter);
			if (iter_left == 0)
			{
				my_mlx_pixel_put(&fractal->win->img, x, y,
					gen_trgb(255, 255, 255, 255));
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->win->mlx, fractal->win->win,
		fractal->win->img.img, 0, 0);
}
