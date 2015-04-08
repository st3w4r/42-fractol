/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_fractal_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 20:27:42 by ybarbier          #+#    #+#             */
/*   Updated: 2015/04/08 20:27:43 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

int		ftl_fractal_carpet(t_env *e, t_fractal ftl, t_point *point)
{
	int x;
	int y;

	(void)ftl;
	x = point->x;
	y = point->y;
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (ftl_get_color(0, *(e->p_color_ptr)));
		y /= 3;
		x /= 3;
	}
	return (ftl_get_color(100, *(e->p_color_ptr)));
}
