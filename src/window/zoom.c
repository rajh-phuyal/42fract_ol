/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:00:03 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/04 01:56:20 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	change_center(t_fractal *fractal, double val, int key)
{
	if (key == UP)
	{
		fractal->plane->i_pos += val;
		fractal->plane->i_neg += val;
		return (1);
	}
	else if (key == DOWN)
	{
		fractal->plane->i_pos -= val;
		fractal->plane->i_neg -= val;
		return (1);
	}
	else if (key == LEFT)
	{
		fractal->plane->x_pos -= val;
		fractal->plane->x_neg -= val;
		return (1);
	}
	else if (key == RIGHT)
	{
		fractal->plane->x_pos += val;
		fractal->plane->x_neg += val;
		return (1);
	}
	return (0);
}

void	zoom_in(t_fractal *fractal, double x, double y)
{
	double	at_x;
	double	at_y;

	at_x = map_range(x, fractal, 'x');
	at_y = map_range(y, fractal, 'y');
	fractal->plane->x_pos = (fractal->plane->x_pos - at_x) / 1.5f + at_x;
	fractal->plane->x_neg = (fractal->plane->x_neg - at_x) / 1.5f + at_x;
	fractal->plane->i_pos = (fractal->plane->i_pos - at_y) / 1.5f + at_y;
	fractal->plane->i_neg = (fractal->plane->i_neg - at_y) / 1.5f + at_y;
	render_again(fractal, false);
}

void	zoom_out(t_fractal *fractal, double x, double y)
{
	double	at_x;
	double	at_y;

	at_x = map_range(x, fractal, 'x');
	at_y = map_range(y, fractal, 'y');
	fractal->plane->x_pos = (fractal->plane->x_pos - at_x) * 1.5f + at_x;
	fractal->plane->x_neg = (fractal->plane->x_neg - at_x) * 1.5f + at_x;
	fractal->plane->i_pos = (fractal->plane->i_pos - at_y) * 1.5f + at_y;
	fractal->plane->i_neg = (fractal->plane->i_neg - at_y) * 1.5f + at_y;
	render_again(fractal, false);
}
