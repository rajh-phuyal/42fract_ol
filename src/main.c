/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:53:11 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/09 16:18:02 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniLibX/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	win_ptr = mlx_new_window (mlx_ptr, 300, 300, "Hello World");
	if (!win_ptr)
		return (2);
	mlx_loop(mlx_ptr);
	return (0);
}