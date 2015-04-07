/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 17:00:49 by ybarbier          #+#    #+#             */
/*   Updated: 2015/04/03 17:00:51 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

void	ftl_color_change(int num, t_env *e)
{
	if (num >= 0 && num <= 3)
		e->p_color_ptr = &(e->p_color_arr[num]);
	else
		e->p_color_ptr = &(e->p_color_arr[0]);
}

void	ftl_color_init(t_env *e)
{
	if (!(e->p_color_arr = (t_palette*)malloc(sizeof(t_palette) * 4)))
		ft_malloc_error();
	e->p_color_ptr = NULL;
	e->p_color_arr[0] = (t_palette){0x7AE0F2, 0x1e2a66, 0x1FBF06, 0xA63C7F,
		0x262473, 0x0A3BB0, 0xD94A39, 0x403231, 0x8C5AA6, 0x8BB16C, 0xD9C860};
	e->p_color_arr[1] = (t_palette){0x7AE0F2, 0x752859, 0xF29CD4, 0xA65A8B,
		0x25591F, 0x62A65A, 0x78EDF2, 0x337073, 0xA65A8B, 0x7AF2B5, 0x337352};
	e->p_color_arr[2] = (t_palette){0x000000, 0x090132, 0x04044A, 0x000865,
		0x0B2C89, 0x1752B0, 0x88B4E3, 0xD4EBFB, 0xF1EABE, 0xF6CB5A, 0xFFAA00};
	e->p_color_arr[3] = (t_palette){0xFFFFFF, 0xEEEEEE, 0x000000, 0xCCCCCC,
		0xBBBBBB, 0xAAAAAA, 0x999999, 0x888888, 0x777777, 0x666666, 0x555555};
	e->p_color_ptr = &(e->p_color_arr[0]);
}

int		ftl_get_color(int z, t_palette palette)
{
	int color;

	z = sin(z) * 100;
	color = palette.color_default;
	if (z < 0)
		color = palette.color_0;
	else if (z >= 0 && z < 10)
		color = palette.color_1;
	else if (z >= 0 && z < 10)
		color = palette.color_2;
	else if (z >= 10 && z < 20)
		color = palette.color_3;
	else if (z >= 20 && z < 50)
		color = palette.color_4;
	else if (z >= 50 && z < 60)
		color = palette.color_5;
	else if (z >= 60 && z < 70)
		color = palette.color_6;
	else if (z >= 70 && z < 80)
		color = palette.color_7;
	else if (z >= 80 && z < 90)
		color = palette.color_8;
	else if (z >= 90)
		color = palette.color_9;
	return (color);
}
