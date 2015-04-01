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

static	void	key_hook_change_fractal(int keycode, t_env *e)
{
	if (keycode == KEY_KP_1)
		e->ftl_ptr = &(e->ftl_arr[0]);
	else if (keycode == KEY_KP_2)
		e->ftl_ptr = &(e->ftl_arr[1]);
	else if (keycode == KEY_KP_3)
		e->ftl_ptr = &(e->ftl_arr[2]);
}


int	    ftl_key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	key_hook_change_fractal(keycode, e);
	ftl_draw_reload(e);
	// key_hook_rotation(keycode, e);
	// key_hook_translation(keycode, e);
	// key_hook_scale(keycode, e);
	// draw_reload(e);
	return (0);
}
