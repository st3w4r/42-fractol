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

void	ftl_fractal_init(t_env *e)
{
	if (!(e->ftl_arr = (t_fractal*)malloc(sizeof(t_fractal) * 3)))
		ft_malloc_error();
	e->ftl_ptr = NULL;
	//Params init Mandelbrot
	e->ftl_arr[0] = (t_fractal){{0, 0}, {0, 0}, -2.1, 0.6, -1.2, 1.2,
				e->win_size_w / (0.6 + 2.1),
				e->win_size_h / (1.2 + 1.2), 0, 0, 50, ftl_fractal_mandelbrot};
	//Params init Julia
	e->ftl_arr[1] = (t_fractal){{0.285, 0.01}, {0, 0},
					-1.5, 1.5, -1.2, 1.2,
				e->win_size_w / (1.5 + 1.5),
				e->win_size_h / (1.2 + 1.2), 0, 0, 10, ftl_fractal_julia};


	e->ftl_arr[2] = (t_fractal){{0, 0}, {0, 0}, -2.1, 0.6, -1.2, 1.2,
				e->win_size_w / (0.6 - (-2.1)),
				e->win_size_h / (1.2 - (-1.2)), 0, 0, 50, ftl_fractal_julia};
	//Init default fractal
	e->ftl_ptr = &(e->ftl_arr[0]);
}

int		ftl_fractal_mandelbrot(t_env *e, t_fractal ftl, t_point *point)
{
	ftl.c.r = point->x / ftl.zoom_x + ftl.x1;
	ftl.c.i = point->y / ftl.zoom_y + ftl.y1;
	while ((ftl.z.r * ftl.z.r + ftl.z.i * ftl.z.i) < 4 &&
			(ftl.iter < ftl.iter_max))
	{
		ftl.tmp = ftl.z.r;
		ftl.z.r = ftl.z.r * ftl.z.r - ftl.z.i * ftl.z.i + ftl.c.r;
		ftl.z.i = 2 * ftl.z.i * ftl.tmp + ftl.c.i;
		ftl.iter += 1;
	}
	if (ftl.iter == ftl.iter_max)
		return (ftl_get_color(100, *(e->p_color_ptr)));
	return (ftl_get_color((ftl.iter * ftl.iter) * 0.1, *(e->p_color_ptr)));
	// return (ftl_rgb_to_hexa(0, 0, ftl.iter * 255 / ftl.iter_max));
}

int		ftl_fractal_julia(t_env *e, t_fractal ftl, t_point *point)
{
	ftl.z.r = point->x / ftl.zoom_x + ftl.x1;
	ftl.z.i = point->y / ftl.zoom_y + ftl.y1;
	while ((ftl.z.r * ftl.z.r + ftl.z.i * ftl.z.i) < 4 &&
			(ftl.iter < ftl.iter_max))
	{
		ftl.tmp = ftl.z.r;
		ftl.z.r = ftl.z.r * ftl.z.r - ftl.z.i * ftl.z.i + ftl.c.r;
		ftl.z.i = 2 * ftl.z.i * ftl.tmp + ftl.c.i;
		ftl.iter += 1;
	}
	if (ftl.iter == ftl.iter_max)
		return (ftl_get_color(100, *(e->p_color_ptr)));
	return (ftl_get_color((ftl.iter * ftl.iter) * 0.1, *(e->p_color_ptr)));
	// return (ftl_rgb_to_hexa(0, 0, ftl.iter * 255 / ftl.iter_max));
}

// Julia
// {1, -1.5, 1.5, -1.2, 1.2, -0.7, 0.27015, -0.7, 0.27015, 15, julia}};

// ftl.iter * 255 / ftl.iter_max

//définir zoom_x = image_x/(x2 - x1)
//définir zoom_y = image_y/(y2 - y1)


// Julia
/*
définir x1 = -1
définir x2 = 1
définir y1 = -1.2
définir y2 = 1.2
définir zoom = 100
définir iteration_max = 150

définir image_x = (x2 - x1) * zoom
définir image_y = (y2 - y1) * zoom

Pour x = 0 tant que x < image_x par pas de 1
    Pour y = 0 tant que y < image_y par pas de 1
        définir c_r = 0.285
        définir c_i = 0.01
        définir z_r = x / zoom + x1
        définir z_i = y / zoom + y1
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
