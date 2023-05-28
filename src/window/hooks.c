/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:03:59 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/25 19:56:57 by rphuyal          ###   ########.fr       */
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
	ft_printf("Key %d pressed\n", key_pressed);
	if (key_pressed == ESC || !fractal)
	{
		ft_printf("Byeeeee...\n");
		exit_fractal(fractal);
	}
	else
		return (-1);
	return (0);
}

int	mouse_hooks(int button, int mouse_x, int mouse_y, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	ft_printf("Mouse button %d pressed at (%d, %d)\n", button, mouse_x, mouse_y);
	(void)button;
	return (0);
}
