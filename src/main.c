/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:53:11 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/22 16:18:07 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void initialization(char *str)
{
	ft_printf("%s\n", str);
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
		return (ft_error("Invalid arguments", "PASS: ./fractol [mandelbrot | julia | tree]"));
}
