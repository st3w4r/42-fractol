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
		e->ftl_ptr = &(e->ftl_arr[0]);
	else if (ft_strcmp("julia", name_ftl) == 0)
		e->ftl_ptr = &(e->ftl_arr[1]);
}

void	ftl_color_change(int num, t_env *e)
{
	if (num >= 0 && num <= 1)
		e->p_color_ptr = &(e->p_color_arr[num]);
	else
		e->p_color_ptr = &(e->p_color_arr[0]);
}

void	ftl_color_init(t_env *e)
{
	if (!(e->p_color_arr = (t_palette*)malloc(sizeof(t_palette) * 2)))
		ft_malloc_error();
	e->p_color_ptr = NULL;
	e->p_color_arr[0] = (t_palette){0x7AE0F2, 0xECF20F, 0x1FBF06, 0xA63C7F,
		0x262473, 0x0A3BB0, 0xD94A39, 0x403231, 0x8C5AA6, 0x8BB16C, 0xD9C860};
	e->p_color_arr[1] = (t_palette){0x7AE0F2, 0x752859, 0xF29CD4, 0xA65A8B,
		0x25591F, 0x62A65A, 0x78EDF2, 0x337073, 0xA65A8B, 0x7AF2B5, 0x337352};
	e->p_color_ptr = &(e->p_color_arr[0]);
}

int		ftl_get_color(int z, t_palette palette)
{
	int color;

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
	else if (z >= 50 && z < 70)
		color = palette.color_5;
	else if (z >= 70 && z < 100)
		color = palette.color_6;
	else if (z >= 70 && z < 100)
		color = palette.color_7;
	else if (z >= 70 && z < 100)
		color = palette.color_8;
	else if (z >= 70)
		color = palette.color_9;
	else
		color = palette.color_default;
	return (color);
}
