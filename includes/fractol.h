/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:15:20 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/14 13:19:42 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 600

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 69
# define MINUS 78
# define SPACE 49
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define FIVE 23
# define SIX 22
# define SEVEN 26
# define EIGHT 28
# define NINE 25
# define ZERO 29
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define MAX_ITER 100

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

#endif