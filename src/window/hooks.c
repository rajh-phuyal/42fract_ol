/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:03:59 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/03 01:44:29 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_window(fractal->win->mlx, fractal->win->win);
	free(fractal->win->mlx);
	exit(EXIT_SUCCESS);
}

int	key_hooks(int key_pressed, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (key_pressed == UP)
		ft_printf("UP\n");
	if (key_pressed == DOWN)
		ft_printf("DOWN\n");
	if (key_pressed == LEFT)
		ft_printf("LEFT\n");
	if (key_pressed == RIGHT)
		ft_printf("RIGHT\n");
	if (key_pressed == ESC || !fractal)
		exit_fractal(fractal);
	else
		return (-1);
	return (0);
}

int	mouse_hooks(int button, int mouse_x, int mouse_y, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	// if (button == 1)
	// 	change_center(fractal, mouse_x, mouse_y);
	if (button == 4)
		zoom_in(fractal, (double)mouse_x, (double)mouse_y);
	else if (button == 5)
		zoom_out(fractal, (double)mouse_x, (double)mouse_y);
	return (0);
}
