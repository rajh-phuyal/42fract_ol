/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:59:46 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/04 20:18:13 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int put_background(t_fractal *fractal)
{
    int x;
    int y;

    x = 0;
    while (x < fractal->win->width)
    {
        y = 0;
        while (y < fractal->win->height)
        {
            my_mlx_pixel_put(&fractal->win->img, x, y, gen_trgb(255, 0, 0, 0));
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fractal->win->mlx, fractal->win->win, fractal->win->img.img, 0, 0);
    return (0);
}