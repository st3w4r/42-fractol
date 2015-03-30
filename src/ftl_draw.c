/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 17:28:49 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/30 17:28:52 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

void	ftl_draw_windows(char *title, t_env *e)
{
	if (!(e->mlx = mlx_init()))
		ft_error_str_exit("error mlx init.");
	e->win = mlx_new_window(e->mlx, e->win_size_w, e->win_size_h, title);
}



/*
void	draw_reload(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WINDOW_SIZE_W + 100, WINDOW_SIZE_H + 100);
	e->pixel_img = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->ed));
	draw_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, -50, -50);
	mlx_destroy_image(e->mlx, e->img);
}
*/
