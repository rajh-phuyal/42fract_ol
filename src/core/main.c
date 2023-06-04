/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:53:11 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/04 20:54:10 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	*ft_valid_args(char *frac)
{
	if (!ft_strncmp(frac, "mandelbrot", ft_strlen(frac)))
		return (show_mandelbrot);
	else if (!ft_strncmp(frac, "julia", ft_strlen(frac)))
		return (show_julia);
	else if (!ft_strncmp(frac, "tree", ft_strlen(frac)))
		return (show_tree);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	void		(*func)(t_fractal *);
	int			valid;
	
	if (argc == 2)
	{
		func = ft_valid_args(argv[1]);
		if (!func)
			return ft_printf("Available: [mandelbrot | julia | tree]\n");
		fractal.name = argv[1];
		valid = initialization(&fractal);
		if (!valid)
			return (ft_printf("Error: Failed to initialize program!\n"));
		mlx_hook(fractal.win->win, 17, 0, exit_fractal, &fractal);
		mlx_key_hook (fractal.win->win, key_hooks, &fractal);
		mlx_mouse_hook(fractal.win->win, mouse_hooks, &fractal);
		func(&fractal);
		mlx_loop(fractal.win->mlx);
	}
	else
		ft_printf("Invalid arguments!! Use: ./fractol [mandelbrot | julia | tree]\n");
	return (0);
}
