/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:53:11 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/04 01:06:00 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	print_menu(void)
{
	ft_printf("\n");
	ft_printf("Move Image   : [UP | DOWN | LEFT | RIGHT]\n");
	ft_printf("Zoom         : [SCROLL UP | SCROLL DOWN]\n");
	ft_printf("Inc Julia    : [J]\n");
	ft_printf("Dec Julia    : [B]\n");
	ft_printf("Reset        : [SPACE]\n");
	ft_printf("Exit         : [ESC]\n");
}

int	print_options(int ac_error)
{
	if (ac_error == 1)
	{
		ft_printf("Invalid number of arguments!!\n");
		ft_printf("Uses: ./fractol [mandelbrot | julia | tree]\n");
		print_menu();
	}
	else if (ac_error == 2)
		ft_printf("Available fractals: [mandelbrot | julia | tree]\n");
	return (ac_error);
}

void	*valid_fractal(char *name)
{
	if (!ft_strncmp(name, "mandelbrot", 11))
		return (show_mandelbrot);
	else if (!ft_strncmp(name, "julia", 11))
		return (show_julia);
	else if (!ft_strncmp(name, "tree", 11))
		return (show_tree);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	void		(*show)(t_fractal *, bool);

	if (argc == 2)
	{
		show = valid_fractal(argv[1]);
		if (!show)
			return (print_options(argc) - 2);
		fractal.name = argv[1];
		fractal.show = show;
		if (!initialization(&fractal))
			return (ft_printf("ERROR: Failed to initialize program!\n"));
		mlx_hook(fractal.win->win, CROSS, 0, exit_fractal, &fractal);
		mlx_key_hook(fractal.win->win, key_hooks, &fractal);
		mlx_mouse_hook(fractal.win->win, mouse_hooks, &fractal);
		fractal.show(&fractal, true);
		mlx_loop(fractal.win->mlx);
	}
	else
		print_options(argc);
	return (0);
}
