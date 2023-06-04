/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:26:44 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/04 20:09:35 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

float map_range(int num, int lower, int upper, int lower_new, int upper_new)
{
    return ((float)(num - lower) * (upper_new - lower_new) / (float)(upper - lower) + lower_new);
}

int is_julia_stable(t_cnum *inum, t_cnum *c, int iter)
{
    int i;

    i = 0;
    while (i++ < iter) {
        double temp_a = inum->a;
        double temp_b = inum->b;
        inum->a = temp_a * temp_a - temp_b * temp_b + c->a;
        inum->b = 2 * temp_a * temp_b + c->b;

        if (fabs(inum->a + inum->b) > 4)
            return i;
    }
    return 0;
}

int is_stable(t_cnum *inum, int iter)
{
    t_cnum temp;
    int i;

    i = 0;
    temp = *inum;
    while (i++ < iter) {
        double temp_a = temp.a;
        double temp_b = temp.b;
        temp.a = temp_a * temp_a - temp_b * temp_b;
        temp.b = 2 * temp_a * temp_b;

        temp.a += inum->a;
        temp.b += inum->b;

        if (fabs(temp.a + temp.b) > 4)
            return i;
    }
    return 0;
}