/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:28:51 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/28 20:36:22 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

char    *create_hash_id(int width, int height, char* name)
{
    unsigned long id;
    int c;

    id = 5381;
    id = ((id << 3) + id) + width;
    id = ((id << 3) + id) + height;
    while (*name)
        id = ((id << 3) + id) + *name++;
    return ft_itoa(id % INT_MAX);
}