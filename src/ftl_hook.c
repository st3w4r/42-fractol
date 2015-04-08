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

#include <stdio.h>
static	void	ftl_key_hook_scale(int keycode, t_env *e)
{
	if (keycode == KEY_KP_PLUS)
	{
		e->ftl_ptr->x1 *= 0.75;
		e->ftl_ptr->x2 *= 0.75;
		e->ftl_ptr->y1 *= 0.75;
		e->ftl_ptr->y2 *= 0.75;
		e->ftl_ptr->zoom_x = e->win_size_w / (e->ftl_ptr->x2 - e->ftl_ptr->x1);
		e->ftl_ptr->zoom_y = e->win_size_w / (e->ftl_ptr->y2 - e->ftl_ptr->y1);
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
		e->ftl_ptr->y1 += 10 / e->ftl_ptr->zoom_y;
		e->ftl_ptr->y2 += 10 / e->ftl_ptr->zoom_y;
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
		e->ftl_ptr->x1 -= 10 / e->ftl_ptr->zoom_x;
		e->ftl_ptr->x2 -= 10 / e->ftl_ptr->zoom_x;
	}
}

#include <stdio.h>
int				ftl_mouse_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == KEY_MOUSE_UP || button == KEY_MOUSE_CLIC_L)
	{
		e->ftl_ptr->x1 += ((x - (e->win_size_w / 2.0)) / e->win_size_w);
		e->ftl_ptr->x2 += ((x - (e->win_size_w / 2.0)) / e->win_size_w);
		e->ftl_ptr->y1 += ((y - (e->win_size_h / 2.0)) / e->win_size_h);
		e->ftl_ptr->y2 += ((y - (e->win_size_h / 2.0)) / e->win_size_h);
		e->ftl_ptr->x1 *= 0.75;
		e->ftl_ptr->x2 *= 0.75;
		e->ftl_ptr->y1 *= 0.75;
		e->ftl_ptr->y2 *= 0.75;
		e->ftl_ptr->zoom_x = e->win_size_w / (e->ftl_ptr->x2 - e->ftl_ptr->x1);
		e->ftl_ptr->zoom_y = e->win_size_h / (e->ftl_ptr->y2 - e->ftl_ptr->y1);
	}
	else if (button == KEY_MOUSE_DOWN || button == KEY_MOUSE_CLIC_R)
	{
		e->ftl_ptr->x1 -= (((x - (e->win_size_w / 2.0)) / e->win_size_w));
		e->ftl_ptr->x2 -= (((x - (e->win_size_w / 2.0)) / e->win_size_w));
		e->ftl_ptr->y1 -= (((y - (e->win_size_h / 2.0)) / e->win_size_h));
		e->ftl_ptr->y2 -= (((y - (e->win_size_h / 2.0)) / e->win_size_h));
		e->ftl_ptr->x1 *= 1.25;
		e->ftl_ptr->x2 *= 1.25;
		e->ftl_ptr->y1 *= 1.25;
		e->ftl_ptr->y2 *= 1.25;
		e->ftl_ptr->zoom_x = e->win_size_w / (e->ftl_ptr->x2 - e->ftl_ptr->x1);
		e->ftl_ptr->zoom_y = e->win_size_h / (e->ftl_ptr->y2 - e->ftl_ptr->y1);
	}
	ftl_draw_reload(e);
	return (0);
}

int				ftl_motion_hook(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= e->win_size_w && y <= e->win_size_h
		&& e->stop_motion)
	{
		e->ftl_ptr->c.r = (double)x / (double)e->win_size_w * 4 - 2;
		e->ftl_ptr->c.i = (double)y / (double)e->win_size_h * 4 - 2;
		ftl_draw_reload(e);
	}
	return (0);
}

int				ftl_key_hook(int keycode, t_env *e)
{
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
	ftl_key_hook_change_color(keycode, e);
	ftl_key_hook_change_fractal(keycode, e);
	ftl_key_hook_scale(keycode, e);
	ftl_key_hook_translation(keycode, e);
	ftl_draw_reload(e);
	return (0);
}
