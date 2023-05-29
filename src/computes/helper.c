/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:26:44 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/29 21:30:23 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int is_stable(t_cnum inum, t_cnum z_num, int iter)
{
	t_cnum temp;
	int i;

	i = 1;
	temp = inum;
	while (i++ < iter)
	{
		double temp_a = temp.a;
		double temp_b = temp.b;
		temp.a = temp_a * temp_a - temp_b * temp_b + z_num.a;
		temp.b = 2 * temp_a * temp_b + z_num.b;
		if (temp.a * temp.a + temp.b * temp.b > 4)
			return i;
	}
	return 0;
}