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
		ftl_change_fractol("carpet", e);
	else if (keycode == KEY_KP_4)
		ftl_change_fractol("b_ship", e);
}

static	void	ftl_key_hook_scale(int keycode, t_env *e)
{
	if (keycode == KEY_KP_PLUS)
	{
		e->ftl_ptr->x1 *= 0.75;
		e->ftl_ptr->x2 *= 0.75;
		e->ftl_ptr->y1 *= 0.75;
		e->ftl_ptr->y2 *= 0.75;
		e->ftl_ptr->zoom_x = e->win_size_w / (e->ftl_ptr->x2 - e->ftl_ptr->x1);
		e->ftl_ptr->zoom_y = e->win_size_h / (e->ftl_ptr->y2 - e->ftl_ptr->y1);
	}
	else if (keycode == KEY_KP_MINUS)
	{
		e->ftl_ptr->x1 *= 1.25;
		e->ftl_ptr->x2 *= 1.25;
		e->ftl_ptr->y1 *= 1.25;
		e->ftl_ptr->y2 *= 1.25;
		e->ftl_ptr->zoom_x = e->win_size_w / (e->ftl_ptr->x2 - e->ftl_ptr->x1);
		e->ftl_ptr->zoom_y = e->win_size_h / (e->ftl_ptr->y2 - e->ftl_ptr->y1);
	}
}

static	void	ftl_key_hook_translation(int keycode, t_env *e)
{
	if (keycode == KEY_UP)
	{
		e->ftl_ptr->y1 += 10 / e->ftl_ptr->zoom_x;
		e->ftl_ptr->y2 += 10 / e->ftl_ptr->zoom_x;
	}
	else if (keycode == KEY_DOWN)
	{
		e->ftl_ptr->y1 -= 10 / e->ftl_ptr->zoom_y;
		e->ftl_ptr->y2 -= 10 / e->ftl_ptr->zoom_y;
	}
	else if (keycode == KEY_LEFT)
	{
		e->ftl_ptr->x1 += 10 / e->ftl_ptr->zoom_x;
		e->ftl_ptr->x2 += 10 / e->ftl_ptr->zoom_x;
	}
	else if (keycode == KEY_RIGHT)
	{
		e->ftl_ptr->x1 -= 10 / e->ftl_ptr->zoom_y;
		e->ftl_ptr->x2 -= 10 / e->ftl_ptr->zoom_y;
	}
}


int				ftl_mouse_hook(int button, int x,int y, t_env *e)
{
	// ft_putnbr((e->ftl_ptr->x2));
	// ft_putstr("x: ");
	// ft_putnbr(x);
	// ft_putstr("y: ");
	// ft_putnbr(y);

	if (button == KEY_MOUSE_UP)
	{
		e->ftl_ptr->x1 *= 0.75;
		e->ftl_ptr->x2 *= 0.75;
		e->ftl_ptr->y1 *= 0.75;
		e->ftl_ptr->y2 *= 0.75;
		//
		e->ftl_ptr->zoom_x = e->win_size_w / (e->ftl_ptr->x2 - e->ftl_ptr->x1);
		e->ftl_ptr->zoom_y = e->win_size_h / (e->ftl_ptr->y2 - e->ftl_ptr->y1);


// 		e->ftl_ptr->zoom_x += (double)e->ftl_ptr->x2 *
// 		((double)x / (double)e->win_size_w) ;
// 		e->ftl_ptr->zoom_y += (double)e->ftl_ptr->y2 *
// ((double)y / (double)e->win_size_h) ;
		// e->ftl_ptr->zoom_x = e->win_size_w / 0.1;
		// e->ftl_ptr->zoom_y = e->win_size_h / 0.1;

		// e->ftl_ptr->zoom_x = (e->ftl_ptr->x2 - e->ftl_ptr->x1) /e->ftl_ptr->zoom_x;
		// e->ftl_ptr->zoom_y = (e->ftl_ptr->y2 - e->ftl_ptr->y1) / e->ftl_ptr->zoom_x;

		// e->ftl_ptr->zoom_x +=  e->win_size_w / 2;
		// e->ftl_ptr->zoom_y +=  e->win_size_h / 2 ;

		// cx = (x - 320+xMove) / zoom;
		// cy = (y - 290+yMove) / zoom;

		// cx = ((x - 320) / zoom) + xMove;
		// cy = ((y - 290) / zoom) + yMove;
	}
	else if (button == KEY_MOUSE_DOWN)
	{
		e->ftl_ptr->x1 *= 1.25;
		e->ftl_ptr->x2 *= 1.25;
		e->ftl_ptr->y1 *= 1.25;
		e->ftl_ptr->y2 *= 1.25;
		e->ftl_ptr->zoom_x = e->win_size_w / (e->ftl_ptr->x2 - e->ftl_ptr->x1);
		e->ftl_ptr->zoom_y = e->win_size_h / (e->ftl_ptr->y2 - e->ftl_ptr->y1);

		// e->ftl_ptr->zoom_x *= e->ftl_ptr->zoom_x / 100 ;
		// e->ftl_ptr->zoom_y *= e->ftl_ptr->zoom_y / 100;
		// e->ftl_ptr->zoom_x = e->win_size_w / (e->win_size_w);
		// e->ftl_ptr->zoom_y = e->win_size_h / (e->win_size_h);

	}
			// zoom+=zoomIncrease;
			// zoomIncrease+=100;
			//
			// initialZoom = zoom;
			// zoom+=zoomIncrease;
			// zoomIncrease*=2;
			// xMove*=2;
			// yMove*=2;
	ftl_draw_reload(e);
	return (0);
}


#include <stdio.h>

int				ftl_motion_hook(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= e->win_size_w && y <= e->win_size_h
		&& e->stop_motion)
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
	else if (keycode == KEY_KP_0)
		e->stop_motion = !(e->stop_motion);
	else if (keycode == KEY_PAGE_UP)
		e->ftl_ptr->iter_max += 5;
	else if (keycode == KEY_PAGE_DOWN)
	{
		if ((e->ftl_ptr->iter_max - 5) <= 0)
			e->ftl_ptr->iter_max = 2;
		else
			e->ftl_ptr->iter_max -= 5;
	}
	else if (keycode == KEY_1)
		ftl_color_change(0, e);
	else if (keycode == KEY_2)
		ftl_color_change(1, e);
	else if (keycode == KEY_3)
		ftl_color_change(2, e);
	else if (keycode == KEY_4)
		ftl_color_change(3, e);
	// else if (keycodre == KEY_)
	// ft_putnbr(e->ftl_ptr->iter);
	ftl_key_hook_change_fractal(keycode, e);
	ftl_key_hook_scale(keycode, e);
	ftl_key_hook_translation(keycode, e);
	ftl_draw_reload(e);
	// key_hook_rotation(keycode, e);
	// key_hook_translation(keycode, e);
	// draw_reload(e);
	return (0);
}
