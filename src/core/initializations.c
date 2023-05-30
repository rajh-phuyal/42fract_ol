/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:31:59 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/30 15:38:36 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

t_cnum	*get_cnum()
{
	t_cnum	*cnum;

	cnum = malloc(sizeof(t_cnum));
	if (!cnum)
		return (NULL);
	cnum->a = 0;
	cnum->b = 0;
	return (cnum);
}

t_plane	*get_complex_plane(void)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->x_pos = 2.0f;
	plane->x_neg = -2.0f;
	plane->i_pos = 2.0f;
	plane->i_neg = -2.0f;
	plane->x0 = WIDTH / 2;
	plane->i0 = HEIGHT / 2;
	return (plane);
}

t_window	*get_window(char *name)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, name);
	window->img.img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	window->img.addr = mlx_get_data_addr(window->img.img, &window->img.bits_per_pixel, &window->img.line_length,
								&window->img.endian);
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
	fractal->win = get_window(ft_strjoin("Fractal : ", fractal->name));
	fractal->plane = get_complex_plane();
	fractal->cnum = get_cnum();
	fractal->iter = 80;
	if (!fractal->win || !fractal->plane || !fractal->cnum)
		return (false);
	return (true);
}
