/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:59:46 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/02 20:50:25 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	et_color(int op, int r, int g, int b)
{
	if (op > 255 || r > 255 || g > 255 || b > 255)
		return (0);
	return (op << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	put_background(t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	while (x < fractal->win->width)
	{
		y = 0;
		while (y < fractal->win->height)
		{
			my_mlx_pixel_put(&fractal->win->img, x, y, 0x092f5d);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->win->mlx, fractal->win->win,
		fractal->win->img.img, 0, 0);
}
