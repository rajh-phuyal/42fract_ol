/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:53:11 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/12 20:41:54 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	print_options(int ac_error)
{
	if (ac_error == 1)
	{
		ft_printf("Invalid number of arguments!!\n");
		ft_printf("Uses: ./fractol [mandelbrot | julia | tree]\n");
	}
	else if (ac_error == 2)
		ft_printf("Available fractals: [mandelbrot | julia | tree]\n");
	return (ac_error);
}

void	*ft_valid_args(char *name)
{
	if (!ft_strncmp(name, "mandelbrot", 10))
		return (show_mandelbrot);
	else if (!ft_strncmp(name, "julia", 10))
		return (show_julia);
	else if (!ft_strncmp(name, "tree", 10))
		return (show_tree);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	int			valid;
	void		(*show)(t_fractal *);

	if (argc == 2)
	{
		show = ft_valid_args(argv[1]);
		if (!show)
			return (print_options(argc) - 2);
		fractal.name = argv[1];
		valid = initialization(&fractal);
		if (!valid)
			return (ft_printf("Error: Failed to initialize program!\n"));
		mlx_hook(fractal.win->win, 17, 0, exit_fractal, &fractal);
		mlx_key_hook (fractal.win->win, key_hooks, &fractal);
		mlx_mouse_hook(fractal.win->win, mouse_hooks, &fractal);
		show(&fractal);
		mlx_loop(fractal.win->mlx);
	}
	else
		print_options(argc);
	return (0);
}
