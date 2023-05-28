/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:11:10 by rphuyal           #+#    #+#             */
/*   Updated: 2023/05/28 19:12:56 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_ITER 100

void drawMandelbrot() {
    int x, y, i;
    double zx, zy, cx, cy, tmp;

    for (y = 0; y < HEIGHT; ++y) {
        for (x = 0; x < WIDTH; ++x) {
            zx = zy = 0;
            cx = ((double)x - WIDTH / 2) * 4 / WIDTH;
            cy = ((double)y - HEIGHT / 2) * 4 / HEIGHT;
            i = MAX_ITER;

            while (zx * zx + zy * zy < 4 && i > 0) {
                tmp = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = tmp;
                --i;
            }

            if (i > 0)
                putchar(' ');  // Change this character for a different visual representation
            else
                putchar('*');
        }
        putchar('\n');
    }
}

int main() {
    drawMandelbrot();
    return 0;
}