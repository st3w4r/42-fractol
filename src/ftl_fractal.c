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
	if (!(e->ftl_arr = (t_fractal*)malloc(sizeof(t_fractal) * 4)))
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
	//Params init Carpet
	e->ftl_arr[2] = (t_fractal){{0, 0}, {0, 0}, -2.1, 0.6, -1.2, 1.2,
				e->win_size_w / (0.6 - (-2.1)),
				e->win_size_h / (1.2 - (-1.2)), 0, 0, 50, ftl_fractal_carpet};
	//Params init Burnning Ship
	e->ftl_arr[3] = (t_fractal){{0, 0}, {0, 0}, -2.1, 0.6, -1.2, 1.2,
				e->win_size_w / (0.6 + 2.1),
				e->win_size_h / (1.2 + 1.2), 0, 0, 50, ftl_fractal_b_ship};
	//Init default fractal
	e->ftl_ptr = &(e->ftl_arr[0]);
}
/*
double x2 = z.x * z.x;
double y2 = z.y * z.y;
double z2 = z.z * z.z;
double temp = 1.0 - z2 / (x2 + y2);
double newx = (x2 - y2) * temp;
double newy = 2.0 * z.x * z.y * temp;
double newz = -2.0 * z.z * sqrt(x2 + y2);
z.x = newx + constant.x;
z.y = newy + constant.y;
z.z = newz + constant.z;
r = z.Length();
*/

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
	// return (ftl_create_rgb(0, 0, ftl.iter * 255 / ftl.iter_max));
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
	// return (ftl_get_color(ftl.iter, *(e->p_color_ptr)));
	// return (ftl_get_color((ftl.iter * 255 / ftl.iter_max) * 0.1, *(e->p_color_ptr)));
}

int		ftl_fractal_carpet(t_env *e, t_fractal ftl, t_point *point)
{
	int x;
	int y;

	x = point->x;
	y = point->y;
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 ==1)
			return (ftl_get_color(0, *(e->p_color_ptr)));
		y /= 3;
		x /= 3;
	}
	return (ftl_get_color(100, *(e->p_color_ptr)));
}

int		ftl_fractal_b_ship(t_env *e, t_fractal ftl, t_point *point)
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
}

/*
if
	(
		//Not both the first (rightmost) digits are '1' in base 3
		!(
				(x / 1) % 3 == 1
			&& (y / 1) % 3 == 1
		)

		&&

		//Not both the second digits are '1' in base 3
		!(
				(x / 3) % 3 == 1
			&& (y / 3) % 3 == 1
		)

		&&

		//Not both the third digits are '1' in base 3
		!(
				(x / 9) % 3 == 1
			&& (y / 9) % 3 == 1
		)

		&&

		//Not both the fourth digits are '1' in base 3
		!(
				(x / 27) % 3 == 1
			&& (y / 27) % 3 == 1
		)

		&&

		//Not both the fifth digits are '1' in base 3
		!(
				(x / 81) % 3 == 1
			&& (y / 81) % 3 == 1
		)
		&&

		//Not both the fifth digits are '1' in base 3
		!(
				(x / 243) % 3 == 1
			&& (y / 243) % 3 == 1
		)
		&&

		//Not both the fifth digits are '1' in base 3
		!(
				(x / 729) % 3 == 1
			&& (y / 729) % 3 == 1
		)
		&&

		//Not both the fifth digits are '1' in base 3
		!(
				(x / 2187) % 3 == 1
			&& (y / 2187) % 3 == 1
		)
	)
		return (ftl_create_rgb(255, 255, 255));

	return (ftl_create_rgb(0, 0, 0));

}

*/
/*
drawRect(int((2 * x1 + x2) / 3.0), int((2 * y1 + y2) / 3.0), int((x1 + 2 * x2) / 3.0) - 1, int((y1 + 2 * y2) / 3.0) - 1, RGB_Black);

//call itself 8 times again, now for the 8 new rectangles around the one that was just drawn
if(n < maxRecursions)
{
	drawCarpet(n + 1, x1                 , y1                 , (2 * x1 + x2) / 3.0, (2 * y1 + y2) / 3.0);
	drawCarpet(n + 1, (2 * x1 + x2) / 3.0, y1                 , (x1 + 2 * x2) / 3.0, (2 * y1 + y2) / 3.0);
	drawCarpet(n + 1, (x1 + 2 * x2) / 3.0, y1                 , x2                 , (2 * y1 + y2) / 3.0);
	drawCarpet(n + 1,  x1                , (2 * y1 + y2) / 3.0, (2 * x1 + x2) / 3.0, (y1 + 2 * y2) / 3.0);
	drawCarpet(n + 1, (x1 + 2 * x2) / 3.0, (2 * y1 + y2) / 3.0, x2                 , (y1 + 2 * y2) / 3.0);
	drawCarpet(n + 1, x1                 , (y1 + 2 * y2) / 3.0, (2 * x1 + x2) / 3.0,  y2                );
	drawCarpet(n + 1, (2 * x1 + x2) / 3.0, (y1 + 2 * y2) / 3.0, (x1 + 2 * x2) / 3.0,  y2                );
	drawCarpet(n + 1, (x1 + 2 * x2) / 3.0, (y1 + 2 * y2) / 3.0, x2                 ,  y2                );
}
}
*/

/*

if
	(
		//Not both the first (rightmost) digits are '1' in base 3
		!(
				(x / 1) % 3 == 1
			&& (y / 1) % 3 == 1
		)

		&&

		//Not both the second digits are '1' in base 3
		!(
				(x / 3) % 3 == 1
			&& (y / 3) % 3 == 1
		)

		&&

		//Not both the third digits are '1' in base 3
		!(
				(x / 9) % 3 == 1
			&& (y / 9) % 3 == 1
		)

		&&

		//Not both the fourth digits are '1' in base 3
		!(
				(x / 27) % 3 == 1
			&& (y / 27) % 3 == 1
		)

		&&

		//Not both the fifth digits are '1' in base 3
		!(
				(x / 81) % 3 == 1
			&& (y / 81) % 3 == 1
		)
	)
*/
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
