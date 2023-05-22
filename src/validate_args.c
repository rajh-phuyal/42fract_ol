/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:25:35 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/22 15:39:46 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


int	ft_valid_args(char **argv)
{
    if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])))
        return (1);
    else if (!ft_strncmp(argv[1], "julia", ft_strlen(argv[1])))
        return (1);
    else if (!ft_strncmp(argv[1], "tree", ft_strlen(argv[1])))
        return (1);
    else
        return (0);
}
