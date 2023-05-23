/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:53:11 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/23 17:43:49 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	get_complex_plain(void)
{
	t_complex	*complex;

	complex = malloc(sizeof(t_complex));
	t_complex->x = 3;
	t_complex->y = 3;
	return (complex);
}

void	initialization(char *fractal)
{
	t_window	*window;
	t_complex	*complex;
	t_fractal	*fractal;
	
	fractal = malloc(sizeof(t_fractal));
	window = malloc(sizeof(t_window));
	complex = malloc(sizeof(t_complex));
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "Fractol");
	window->height = HEIGHT;
	window->width = WIDTH;
	if (window->mlx == NULL || window->win == NULL)
		return (ft_printf("Error: Failed to create window\n"));
	t_complex = get_complex_plain();
	t_fractal->win = window;
	t_fractal->plain = complex;
	
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_valid_args(argv))
		{
			ft_printf("%i Valid argument\n", argc);
			initialization(argv[1]);
			return (0);
		}
		else
			return (ft_printf("Error: Invalid argument\n"));
	}
	else
		return (ft_error("Invalid arguments", "PASS: ./fractol [name]"));
}
