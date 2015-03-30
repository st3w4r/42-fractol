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

int	    key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	// key_hook_rotation(keycode, e);
	// key_hook_translation(keycode, e);
	// key_hook_scale(keycode, e);
	// draw_reload(e);
	return (0);
}
