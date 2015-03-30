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

void	ftl_cal_apply(t_env *e, int sx, int sy, int (*f)(int, int))
{
	int x;
	int y;
	int color_pix;

	y = 0;
	while (y < sx)
	{
		x = 0;
		while (y < sy)
		{
			color_pix = (*f)(y, x);
			++x;
		}
		++y;
	}
}
