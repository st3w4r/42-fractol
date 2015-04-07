/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 21:04:20 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/31 21:04:22 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

int		ftl_create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + ((b & 0xff)));
}

void	ftl_change_fractol(char *name_ftl, t_env *e)
{
	if (ft_strcmp("mandelbrot", name_ftl) == 0)
		e->ftl_ptr = &(e->ftl_arr[0]);
	else if (ft_strcmp("julia", name_ftl) == 0)
		e->ftl_ptr = &(e->ftl_arr[1]);
	else if (ft_strcmp("carpet", name_ftl) == 0)
		e->ftl_ptr = &(e->ftl_arr[2]);
	else if (ft_strcmp("b_ship", name_ftl) == 0)
		e->ftl_ptr = &(e->ftl_arr[3]);
}

void	ftl_key_hook_change_fractal(int keycode, t_env *e)
{
	if (keycode == KEY_KP_1)
		ftl_change_fractol("mandelbrot", e);
	else if (keycode == KEY_KP_2)
		ftl_change_fractol("julia", e);
	else if (keycode == KEY_KP_3)
		ftl_change_fractol("carpet", e);
	else if (keycode == KEY_KP_4)
		ftl_change_fractol("b_ship", e);
}

void	ftl_key_hook_change_color(int keycode, t_env *e)
{
	if (keycode == KEY_1)
		ftl_color_change(0, e);
	else if (keycode == KEY_2)
		ftl_color_change(1, e);
	else if (keycode == KEY_3)
		ftl_color_change(2, e);
	else if (keycode == KEY_4)
		ftl_color_change(3, e);
}
