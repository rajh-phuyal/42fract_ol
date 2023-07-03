/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:48:14 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/04 00:24:14 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	init_tree_plane(t_fractal *fractal)
{
	fractal->plane->x_pos = 2.0f;
	fractal->plane->x_neg = -2.0f;
	fractal->plane->i_pos = 3.0f;
	fractal->plane->i_neg = -2.0f;
	fractal->iter = 100;
}

void	put_tree_color(t_fractal *fractal, int diff, int x, int y)
{
	int	color;

	if (diff == 0)
		color = 0x000000;
	else 
		color = get_color(255, 0, (255 * diff) / fractal->iter, 0);
	my_mlx_pixel_put(&fractal->win->img, x, y, color);
}

void	show_tree(t_fractal *fractal, bool first)
{
	int		x;
	int		y;
	int		iter_left;

	if (first)
		init_tree_plane(fractal);
	x = 0;
	while (x < fractal->win->width)
	{
		y = 0;
		while (y < fractal->win->height)
		{
			iter_left = is_bs_stable(get_cnum(x, y, fractal),
					get_cnum(x, y, fractal), fractal->iter);
			put_tree_color(fractal, iter_left, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->win->mlx, fractal->win->win,
		fractal->win->img.img, 0, 0);
}
