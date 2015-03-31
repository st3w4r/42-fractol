/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 10:55:59 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/31 10:56:00 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

int		ftl_fractal_mandelbrot(t_env *e, t_point *point)
{
	double x1;
	double x2;
	double y1;
	double y2;
	double zoom_x;
	double zoom_y;

	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;

	zoom_x = e->win_size_w/(x2 - x1);
	zoom_y = e->win_size_h/(y2 - y1);


	t_complexe c;
	t_complexe z;
	double tmp;
	double i;

	c.r = point->x / zoom_x + x1;
	c.i = point->y / zoom_y + y1;
	z.r = 0;
	z.i = 0;
	i = 0;

	while ((z.r * z.r + z.i * z.i) < 4 && (i < e->iter_max))
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i += 1;
	}

	if (i == e->iter_max)
		return (255);
	return (0);
}

/*
// on définit la zone que l'on dessine. Ici, la fractale en entière
définir x1 = -2.1
définir x2 = 0.6
définir y1 = -1.2
définir y2 = 1.2
définir image_x = 270
définir image_y = 240
définir iteration_max = 50

// on calcule la taille de l'image :
définir zoom_x = image_x/(x2 - x1)
définir zoom_y = image_y/(y2 - y1)

Pour x = 0 tant que x < image_x par pas de 1
    Pour y = 0 tant que y < image_y par pas de 1
        définir c_r = x / zoom_x + x1
        définir c_i = y / zoom_y + y1
        définir z_r = 0
        définir z_i = 0
        définir i = 0

        Faire
            définir tmp = z_r
            z_r = z_r*z_r - z_i*z_i + c_r
            z_i = 2*z_i*tmp + c_i
            i = i+1
        Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

        si i = iteration_max
            dessiner le pixel de coordonné (x; y)
        finSi
    finPour
finPour
*/
