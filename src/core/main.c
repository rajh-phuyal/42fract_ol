/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:53:11 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/28 20:32:09 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	ft_valid_args(char **argv)
{
	if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])))
		return (1);
	else if (!ft_strncmp(argv[1], "julia", ft_strlen(argv[1])))
		return (1);
	else if (!ft_strncmp(argv[1], "tree", ft_strlen(argv[1])))
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	bool		valid;

	if (argc == 2 && ft_valid_args(argv))
	{
		fractal.name = argv[1];
		valid = initialization(&fractal);
		if (!valid)
			return (ft_printf("Error: Failed to initialize\n"));
		mlx_hook(fractal.win->win, 17, 0, exit_fractal, &fractal);
		mlx_key_hook (fractal.win->win, key_hooks, &fractal);
		mlx_mouse_hook(fractal.win->win, mouse_hooks, &fractal);
		put_background(&fractal);
		retrive_cache(&fractal);
		create_mandelbrot(&fractal);
		mlx_loop(fractal.win->mlx);
	}
	else
		return (ft_printf("Invalid arguments!! Use: ./fractol [name]\n"));
}
