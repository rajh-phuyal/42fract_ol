/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:31:59 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/23 21:36:12 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_cnum	*get_cnum(void)
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
	plane->x = 3;
	plane->i = 3;
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
	fractal->num = get_cnum();
	fractal->iters = 100;
	if (!fractal->win || !fractal->plane || !fractal->num)
		return (false);
	return (true);
}
