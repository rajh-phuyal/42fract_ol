/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:26:44 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/22 19:40:08 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	iter_equation(int z, int c)
{
	int	start;
	int	iterations;

	start = 0;
	iterations = 100;
	while (start < iterations)
	{
		z = (z * z) + c;
		if (z * z > 4)
			break ;
		start++;
	}
	return (0);
}
