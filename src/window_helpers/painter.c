/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:59:46 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/25 20:26:12 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int put_background(t_fractal *fractal)
{
    int x;
    int y;
    t_img bg;

    x = 0;
    // bg.win = fractal->win;
    // bg.img_ptr = mlx_new_image(fractal->win->mlx, fractal->win->width, fractal->win->height);
    // bg.addr = mlx_get_data_addr(bg.img_ptr, &(bg.bpp), &(bg.line_len), &(bg.endian));
    // bg.w = fractal->win->width;
    // bg.h = fractal->win->height;
    mlx_new_image (fractal->win->mlx, int width, int height );
    while (x < fractal->win->width)
    {
        y = 0;
        while (y < fractal->win->height)
        {
            mlx_pixel_put(fractal->win->mlx, fractal->win->win, x, y, gen_trgb(100, 90, 163, 163));
            y++;
        }
        x++;
    }
    return (0);
}