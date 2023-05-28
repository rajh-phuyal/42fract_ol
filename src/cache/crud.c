/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crud.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:11:56 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/28 20:36:19 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int create_cache(t_fractal *fractal)
{
    // fractal->win->img.img
    return (0);
}

t_data   *retrive_cache(t_fractal *fractal)
{
    int     fd;
    char    *id;
    char    *line;
    char    *path;
    
    id = create_hash_id(fractal->win->width, fractal->win->height, fractal->name);
    path = ft_strjoin("cached/", id);
    fd = open(path, O_RDONLY | O_CREAT, 0644);
    free(id);
    free(path);
    if (fd == -1)
        return (NULL);
    line = get_next_line(fd);
    close(fd);
    if (line == NULL)
        return (NULL);
    ft_printf("line: %s\n", line);
    free(line);
    return (0);
}
