/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_cal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 19:22:12 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/30 19:22:14 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

void	ftl_cal_apply(t_env *e, int (*f)(t_env*, t_point*))
{
	t_point	point;
	int		color_pix;

	point.y = 0;
	while (point.y < e->win_size_h)
	{
		point.x = 0;
		while (point.x < e->win_size_w)
		{
			color_pix = (*f)(e, &point);
			ftl_draw_pixel_img(&(point), e, color_pix);
			++point.x;
		}
		++point.y;
	}
}
