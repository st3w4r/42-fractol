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
	if (num >= 0 && num <= 2)
		e->p_color_ptr = &(e->p_color_arr[num]);
	else
		e->p_color_ptr = &(e->p_color_arr[0]);
}

void	ftl_color_init(t_env *e)
{
	if (!(e->p_color_arr = (t_palette*)malloc(sizeof(t_palette) * 3)))
		ft_malloc_error();
	e->p_color_ptr = NULL;
	e->p_color_arr[0] = (t_palette){0x7AE0F2, 0x1e2a66, 0x1FBF06, 0xA63C7F,
		0x262473, 0x0A3BB0, 0xD94A39, 0x403231, 0x8C5AA6, 0x8BB16C, 0xD9C860};
	e->p_color_arr[1] = (t_palette){0x7AE0F2, 0x752859, 0xF29CD4, 0xA65A8B,
		0x25591F, 0x62A65A, 0x78EDF2, 0x337073, 0xA65A8B, 0x7AF2B5, 0x337352};
	// e->p_color_arr[2] = (t_palette){0x3042a1, 0x3042a1, 0x3042a1, 0x3042a1,
		// 0x3042a1, 0x3042a1, 0x3042a1, 0x3042a1, 0x3042a1, 0x3042a1, 0x3042a1};

		e->p_color_arr[2] = (t_palette){
		0x346699,
		0x2e5b89,
		0x29517a,
		0x24476b,
		0x346699,
		0x4875a3,
		0x5c84ad,
		0x7093b7,
		0x85a3c1,
		0x99b2cc};
	e->p_color_ptr = &(e->p_color_arr[0]);
}
/*
int		ftl_get_color(int z, t_palette palette)
{
	int color;

	if (z < 0)
		color = ftl_color_fade(z, palette.color_0,  palette.color_1);
	else if (z >= 0 && z < 10)
		color = ftl_color_fade(z, palette.color_1,  palette.color_2);
	else if (z >= 0 && z < 10)
		color = ftl_color_fade(z, palette.color_2,  palette.color_3);
	else if (z >= 10 && z < 20)
		color = ftl_color_fade(z, palette.color_3,  palette.color_4);
	else if (z >= 20 && z < 50)
		color = ftl_color_fade(z, palette.color_4,  palette.color_5);
	else if (z >= 50 && z < 60)
		color = ftl_color_fade(z, palette.color_5,  palette.color_6);
	else if (z >= 60 && z < 70)
		color = ftl_color_fade(z, palette.color_6,  palette.color_7);
	else if (z >= 70 && z < 80)
		color = ftl_color_fade(z, palette.color_7,  palette.color_8);
	else if (z >= 80 && z < 90)
		color = ftl_color_fade(z, palette.color_8,  palette.color_9);
	else if (z >= 90)
		color = palette.color_9;
	else
		color = palette.color_default;
	return (color);
}*/

int		ftl_get_color(int z, t_palette palette)
{
	int color;

	// ft_putnbr(z);
	// ft_putstr(" ");

	if (z < 0)
		color =  palette.color_0;
	else if (z >= 0 && z < 10)
		color =  palette.color_1;
	else if (z >= 0 && z < 10)
		color =  palette.color_2;
	else if (z >= 10 && z < 20)
		color =  palette.color_3;
	else if (z >= 20 && z < 50)
		color =  palette.color_4;
	else if (z >= 50 && z < 60)
		color =  palette.color_5;
	else if (z >= 60 && z < 70)
		color =  palette.color_6;
	else if (z >= 70 && z < 80)
		color =  palette.color_7;
	else if (z >= 80 && z < 90)
		color =  palette.color_8;
	else if (z >= 90)
		color = palette.color_9;
	else
		color = palette.color_default;
	return (color);
}

int		ftl_color_fade(int z, int color1, int color2)
{
	int r1;
	int g1;
	int b1;

	int r2;
	int g2;
	int b2;

	int dr;
	int dg;
	int db;

	r1 = color1;
	g1 = color1 >> 8;
	b1 = color1 >> 16;

	r2 = color2;
	g2 = color2 >> 8;
	b2 = color2 >> 16;

	// dr = (r2 - r1) / 255;
	// dg = (g2 - g1) / 255;
	// db = (b2 - b1) / 255;

	dr = (z * 255) / 100;
	dg = (z * 255) / 100;
	db = (z * 255) / 100;

	dr = r1;
	dg = g1;
	db = b1;

	// dr = r1  / 255;
	// dg = 0;
	// dg = g1 / 255;
	// db = 0;
	// db = b1 / 255;
	return ftl_create_rgb(dr, dg, db);
}
