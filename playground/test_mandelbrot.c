/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:11:10 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/04 16:45:03 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define WIDTH 900
#define HEIGHT 700
#define MAX_ITER 100

typedef struct s_cnum
{
	double	a;
	double	b;
}	t_cnum;

typedef struct s_plane
{
	int		x0;
	int		i0;
	double	x_pos;
	double	x_neg;
	double	i_pos;
	double	i_neg;
}	t_plane;

typedef struct s_mandelbrot
{
    t_cnum	c;
    t_cnum	z;
    int		iter;
}	t_mandelbrot;

void	init_plane(t_plane *plane)
{
    plane->x0 = WIDTH / 2;
    plane->i0 = HEIGHT / 2;
    plane->x_pos = 2.0f;
    plane->x_neg = -2.0f;
    plane->i_pos = 2.0f;
    plane->i_neg = -2.0f;
}

// https://complex-analysis.com/applets/p5js/mandelbrot/
void create_cordinates(t_plane *plane, t_mandelbrot *mandelbrot)
{
    mandelbrot->c.a = plane->x_pos + (plane->x_neg - plane->x_pos) * plane->x0 / WIDTH;
    mandelbrot->c.b = plane->i_pos + (plane->i_neg - plane->i_pos) * plane->i0 / HEIGHT;
    printf("c.a = %f\n", mandelbrot->c.a);
    printf("c.b = %f\n", mandelbrot->c.b);
}

int main(void)
{
    t_plane plane;
    t_mandelbrot mandelbrot;

    init_plane(&plane);
    printf("x0 = %d\n", plane.x0);
    printf("i0 = %d\n", plane.i0);
    printf("x_pos = %f\n", plane.x_pos);
    printf("x_neg = %f\n", plane.x_neg);
    printf("i_pos = %f\n", plane.i_pos);
    printf("i_neg = %f\n", plane.i_neg);
    create_cordinates(&plane, &mandelbrot);
    return (0);
}