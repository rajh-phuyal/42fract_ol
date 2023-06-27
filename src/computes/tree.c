/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:48:14 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/05 14:39:23 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	show_tree(t_fractal *fractal, bool first)
{
	int		x;
	int		y;
	int		iter_left;

	if (first)
		x = 0;
	x = 0;
	while (x < fractal->win->width)
	{
		y = 0;
		while (y < fractal->win->height)
		{
			iter_left = is_mandel_stable(get_cnum(x, y, fractal),
					fractal->iter);
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
