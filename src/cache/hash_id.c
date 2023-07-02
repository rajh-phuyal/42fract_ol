/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:28:51 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/02 20:52:44 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

unsigned long   create_hash_id(int width, int height, double view)
{
    unsigned long id;

    id = 5381;
    id = ((id << 3) + id) + width;
    id = ((id << 3) + id) + height;
    id = ((id << 3) + id) + view;
    return (id);
}