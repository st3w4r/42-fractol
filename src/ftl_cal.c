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

void	ftl_cal_apply(t_env *e, int (*f)(t_env*, int, int))
{
	int x;
	int y;
	int color_pix;

	y = 0;
	while (y < e->win_size_h)
	{
		x = 0;
		while (x < e->win_size_w)
		{
			color_pix = (*f)(e, x, y);
			++x;
		}
		++y;
	}
}
