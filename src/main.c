/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:53:11 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/14 13:19:13 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_win new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

int	main(void)
{
	t_win tutorial;
	
	tutorial = new_program(WIDTH, HEIGHT, "New Program");
	if (!tutorial.mlx_ptr || !tutorial.win_ptr)
		return (1);

	t_img	image;

	image = new_img(WIDTH, HEIGHT, tutorial);
	mlx_destroy_image(tutorial.mlx_ptr, image.img_ptr);

	mlx_loop(tutorial.mlx_ptr);
	return (0);
}
