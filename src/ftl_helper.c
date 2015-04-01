/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 21:04:20 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/31 21:04:22 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

int		ftl_rgb_to_hexa(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + ((b & 0xff)));
}

void	ftl_change_fractol(char *name_ftl, t_env *e)
{
	if (ft_strcmp("mandelbrot", name_ftl) == 0)
		e->ftl_ptr =  &(e->ftl_arr[0]);
	else if (ft_strcmp("julia", name_ftl) == 0)
		e->ftl_ptr =  &(e->ftl_arr[1]);
}
