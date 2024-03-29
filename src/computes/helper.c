/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:26:44 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/04 13:23:48 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

double	map_range(int num, t_fractal *fractal, char dimension)
{
	double	bound;

	if (dimension == 'x')
	{
		bound = (fractal->plane->x_pos - fractal->plane->x_neg)
			/ (double)fractal->win->width;
		bound *= num;
		bound += fractal->plane->x_neg;
		return (bound);
	}
	else
	{
		bound = (fractal->plane->i_neg - fractal->plane->i_pos)
			/ (double)fractal->win->height;
		bound *= num;
		bound += fractal->plane->i_pos;
		return (bound);
	}
}

int	julia_iteration(t_cnum inum, t_cnum const_c, int iter)
{
	int		i;
	double	aa;
	double	bb;

	i = 0;
	while (i++ < iter)
	{
		aa = inum.a;
		bb = inum.b;
		inum.a = aa * aa - bb * bb + const_c.a;
		inum.b = 2 * aa * bb + const_c.b;
		if (fabs(inum.a + inum.b) > 4)
			return (i);
	}
	return (0);
}

int	mandelbrot_iteration(t_cnum inum, int iter)
{
	int		i;
	double	aa;
	double	bb;
	t_cnum	temp;

	i = 0;
	temp = inum;
	while (i++ < iter)
	{
		aa = temp.a;
		bb = temp.b;
		temp.a = (aa * aa) - (bb * bb);
		temp.b = 2 * aa * bb;
		temp.a += inum.a;
		temp.b += inum.b;
		if (fabs(temp.a + temp.b) > 4)
			return (i);
	}
	return (0);
}

int	burningship_iteration(t_cnum inum, t_cnum const_c, int iter)
{
	int		i;
	double	aa;
	double	bb;
	t_cnum	temp;

	i = 0;
	temp = inum;
	while (i++ < iter)
	{
		temp.a = fabs(temp.a);
		temp.b = fabs(temp.b);
		aa = temp.a;
		bb = temp.b;
		temp.a = (aa * aa) - (bb * bb);
		temp.b = 2 * aa * bb;
		temp.a += const_c.a;
		temp.b += const_c.b;
		if (fabs(temp.a + temp.b) > 2)
			return (i);
	}
	return (0);
}
