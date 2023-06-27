/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:31:59 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/25 17:15:14 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

t_cnum	get_cnum(int x, int y, t_fractal *fractal)
{
	t_cnum	cnum;

	cnum.a = map_range(x, fractal, 'x');
	cnum.b = map_range(y, fractal, 'y');
	return (cnum);
}

t_plane	*get_complex_plane(void)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	return (plane);
}

t_img	get_image(t_window *win, int width, int height)
{
	t_img	img;

	img.img = mlx_new_image(win->mlx, width, height);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel,
			&img.line_length,
			&img.endian);
	return (img);
}

t_window	*get_window(char *name)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, name);
	window->img = get_image(window, WIDTH, HEIGHT);
	free(name);
	if (window->mlx == NULL || window->win == NULL)
	{
		free(window);
		return (NULL);
	}
	window->height = HEIGHT;
	window->width = WIDTH;
	return (window);
}

bool	initialization(t_fractal *fractal)
{
	t_cnum	jul;

	fractal->win = get_window(ft_strjoin("Fractal : ", fractal->name));
	fractal->plane = get_complex_plane();
	if (fractal->show)
	fractal->iter = 70;
	jul.a = -0.8f;
	jul.b = 0.156f;
	fractal->jconst = jul;
	if (!fractal->win || !fractal->plane)
		return (false);
	return (true);
}
