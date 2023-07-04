/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:59:46 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/04 01:29:10 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	get_color(int op, int r, int g, int b)
{
	return (op << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_again(t_fractal *fractal, bool first)
{
	mlx_destroy_image(fractal->win->mlx, fractal->win->img.img);
	fractal->win->img = get_image(fractal->win, fractal->win->width,
			fractal->win->height);
	fractal->show(fractal, first);
}
