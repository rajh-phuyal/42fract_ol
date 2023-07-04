/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:03:59 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/04 01:59:02 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->win->mlx, fractal->win->img.img);
	mlx_destroy_window(fractal->win->mlx, fractal->win->win);
	free(fractal->win->mlx);
	free(fractal->plane);
	free(fractal->win);
	exit(EXIT_SUCCESS);
}

void	check_view_keys(t_fractal *fractal, int key)
{
	double	diff;

	diff = 0.0f;
	if (key == UP || key == DOWN)
		diff = (fractal->plane->i_pos - fractal->plane->i_neg) * 0.3f;
	else if (key == LEFT || key == RIGHT)
		diff = (fractal->plane->x_pos - fractal->plane->x_neg) * 0.3f;
	if (change_center(fractal, diff, key))
		render_again(fractal, false);
}

int	key_hooks(int key_pressed, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (key_pressed == ESC || !fractal)
		exit_fractal(fractal);
	else if (key_pressed == RESET)
		render_again(fractal, true);
	else if (key_pressed == JULIA_INC)
	{
		fractal->jconst.a -= 0.001f;
		fractal->jconst.b += 0.008f;
		render_again(fractal, false);
	}
	else if (key_pressed == JULIA_DEC)
	{
		fractal->jconst.a += 0.001f;
		fractal->jconst.b -= 0.008f;
		render_again(fractal, false);
	}
	else
		check_view_keys(fractal, key_pressed);
	return (0);
}

int	mouse_hooks(int button, int mouse_x, int mouse_y, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (button == ZOOM_IN)
		zoom_in(fractal, (double)mouse_x, (double)mouse_y);
	else if (button == ZOOM_OUT)
		zoom_out(fractal, (double)mouse_x, (double)mouse_y);
	return (0);
}
