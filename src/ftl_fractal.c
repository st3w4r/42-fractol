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
	e->ftl_arr[0] = (t_fractal){{0, 0}, {0, 0}, -2.1, 0.6, -1.2, 1.2,
				e->win_size_w / (0.6 + 2.1),
				e->win_size_h / (1.2 + 1.2), 0, 0, 50, ftl_fractal_mandelbrot};
	e->ftl_arr[1] = (t_fractal){{0.285, 0.01}, {0, 0},
					-1.5, 1.5, -1.2, 1.2,
				e->win_size_w / (1.5 + 1.5),
				e->win_size_h / (1.2 + 1.2), 0, 0, 10, ftl_fractal_julia};
	e->ftl_arr[2] = (t_fractal){{0, 0}, {0, 0}, -2.1, 0.6, -1.2, 1.2,
				e->win_size_w / (0.6 - (-2.1)),
				e->win_size_h / (1.2 - (-1.2)), 0, 0, 50, ftl_fractal_carpet};
	e->ftl_arr[3] = (t_fractal){{0, 0}, {0, 0}, -1.1, 1.6, -1.7, 0.7,
				e->win_size_w / (1.6 + 1.1),
				e->win_size_h / (1.7 + 0.7), 0, 0, 50, ftl_fractal_b_ship};
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
}

int		ftl_fractal_carpet(t_env *e, t_fractal ftl, t_point *point)
{
	int x;
	int y;

	x = point->x;
	y = point->y;
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
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
		ftl.z.r = ftl.z.r * ftl.z.r - ftl.z.i * ftl.z.i - ftl.c.r;
		ftl.z.i = 2 * fabs(ftl.z.i) * fabs(ftl.tmp) + ftl.c.i;
		ftl.iter += 1;
	}
	if (ftl.iter == ftl.iter_max)
		return (ftl_create_rgb(ftl.iter * 255 / ftl.iter_max, 10, 0));
	return (ftl_create_rgb(ftl.iter * 255 / ftl.iter_max,
	ftl.iter * 255 / (ftl.iter_max * 2), 0));
}
