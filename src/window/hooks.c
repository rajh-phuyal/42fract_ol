/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:03:59 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/11 17:18:46 by rphuyal          ###   ########.fr       */
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
	ft_printf("At (x: %d, y: %d)\n", mouse_x, mouse_y);
	printf("maped x: %f\n", map_range(mouse_x, fractal, 'x'));
	printf("maped y: %f\n", map_range(mouse_y, fractal, 'y'));
	(void)button;
	if (button == 4)
		zoom_in(fractal);
	return (0);
}
