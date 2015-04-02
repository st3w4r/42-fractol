/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 17:09:19 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/30 17:09:20 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

static	void	ftl_key_hook_change_fractal(int keycode, t_env *e)
{
	if (keycode == KEY_KP_1)
		ftl_change_fractol("mandelbrot", e);
	else if (keycode == KEY_KP_2)
		ftl_change_fractol("julia", e);
	else if (keycode == KEY_KP_3)
		ftl_change_fractol("autre", e);
}

static	void	ftl_key_hook_scale(int keycode, t_env *e)
{
	if (keycode == KEY_KP_PLUS)
	{
		e->ftl_ptr->zoom_x += 10;
		e->ftl_ptr->zoom_y += 10;
	}
	else if (keycode == KEY_KP_MINUS)
	{
		e->ftl_ptr->zoom_x -= 10;
		e->ftl_ptr->zoom_y -= 10;
	}
}

int				ftl_mouse_hook(int button, int x,int y, t_env *e)
{
	ft_putnbr(button);
	ft_putstr("x: ");
	ft_putnbr(x);
	ft_putstr("y: ");
	ft_putnbr(y);

	if (button == KEY_MOUSE_UP)
	{
		// x1 = x-h,
		// x2 = x+h,
		// y1 = y-h
		// y2 = y+h

		e->ftl_ptr->x1 = x - e->win_size_h;
		e->ftl_ptr->x2 = x + e->win_size_h;
		e->ftl_ptr->y1 = y - e->win_size_h;
		e->ftl_ptr->y2 = y + e->win_size_h;

		// e->ftl_ptr->zoom_x += 10 * x;
		// e->ftl_ptr->zoom_y += 10 * y;
	}
	else if (button == KEY_MOUSE_DOWN)
	{
		/*
		e->ftl_ptr->x1 = x - e->win_size_h;
		e->ftl_ptr->x2 = x + e->win_size_h;
		e->ftl_ptr->y1 = y - e->win_size_h;
		e->ftl_ptr->y2 = y + e->win_size_h;
*/
		e->ftl_ptr->zoom_x -= 10 * x;
		e->ftl_ptr->zoom_y -= 10 * y;
	}
	ftl_draw_reload(e);
	return (0);
}

int				ftl_motion_hook(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= e->win_size_w && y <= e->win_size_h)
	{
		// e->ftl_ptr->c.r = x * 0.2 + y * 0.2;
		e->ftl_ptr->c.r = (double)x / (double)e->win_size_w * 4 - 2;
		e->ftl_ptr->c.i = (double)y / (double)e->win_size_h * 4 - 2;
		// e->ftl_ptr->c.i = 0.01;
		// printf("cr: %f \n", e->ftl_ptr->c.r);
		// printf("ci: %f \n", e->ftl_ptr->c.i);
		//
		// ft_putstr("x:");
		// ft_putnbr(x);
		// ft_putstr(" y:");
		// ft_putnbr(y);
		// ft_putstr("\n");
		ftl_draw_reload(e);
	}

	return (0);
}

int				ftl_key_hook(int keycode, t_env *e)
{
	// ft_putnbr(keycode);
	// ft_putstr(" ");
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	else if (keycode == KEY_PAGE_UP)
		e->ftl_ptr->iter_max += 5;
	else if (keycode == KEY_PAGE_DOWN)
	{
		if ((e->ftl_ptr->iter_max - 5) <= 0)
			e->ftl_ptr->iter_max = 2;
		else
			e->ftl_ptr->iter_max -= 5;
	}
	// ft_putnbr(e->ftl_ptr->iter);
	ftl_key_hook_change_fractal(keycode, e);
	ftl_key_hook_scale(keycode, e);
	ftl_draw_reload(e);
	// key_hook_rotation(keycode, e);
	// key_hook_translation(keycode, e);
	// draw_reload(e);
	return (0);
}
