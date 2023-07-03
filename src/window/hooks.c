/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:03:59 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/03 15:45:10 by rphuyal          ###   ########.fr       */
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

int	validate_keys(t_fractal *fractal, int key)
{
	if (key == UP)
	{
		fractal->plane->i_pos += 0.2f;
		fractal->plane->i_neg += 0.2f;
		return (1);
	}
	else if (key == DOWN)
	{
		fractal->plane->i_pos -= 0.2f;
		fractal->plane->i_neg -= 0.2f;
		return (1);
	}
	else if (key == LEFT)
	{
		fractal->plane->x_neg -= 0.2f;
		fractal->plane->x_pos -= 0.2f;
		return (1);
	}
	else if (key == RIGHT)
	{
		fractal->plane->x_neg += 0.2f;
		fractal->plane->x_pos += 0.2f;
		return (1);
	}
	else if (key == ESC)
		return (-1);
	else
		return (0);
}

int	key_hooks(int key_pressed, void *param)
{
	int			valid;
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	valid = validate_keys(fractal, key_pressed);
	if (valid == -1 || !fractal)
		exit_fractal(fractal);
	else if (valid)
	{
		mlx_destroy_image(fractal->win->mlx, fractal->win->img.img);
    	fractal->win->img = get_image(fractal->win, fractal->win->width, fractal->win->height);
    	fractal->show(fractal, false);
	}
	return (0);
}

int	mouse_hooks(int button, int mouse_x, int mouse_y, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (button == 1)
		change_center(fractal, (double)mouse_x, (double)mouse_y);
	if (button == ZOOM_IN)
		zoom_in(fractal, (double)mouse_x, (double)mouse_y);
	else if (button == ZOOM_OUT)
		zoom_out(fractal, (double)mouse_x, (double)mouse_y);
	return (0);
}
