/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 14:57:33 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/30 14:57:34 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

static int		ftl_expose_hook(t_env *e)
{
	ftl_draw_reload(e);
	return (0);
}

static void		ftl_error_usage(void)
{
	ft_error_str_exit("usage: fractol [mandelbrot, julia]\n");
}

static void		ftl_check_params(int argc, char **argv)
{
	if (argc != 2)
		ftl_error_usage();
	if (ft_strcmp("mandelbrot", argv[1]) != 0 &&
		ft_strcmp("julia", argv[1]) != 0)
		ftl_error_usage();
}

int				main(int argc, char **argv)
{
	t_env *e;

	ftl_check_params(argc, argv);
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		ft_malloc_error();
	e->win_size_h = WINDOW_SIZE_H;
	e->win_size_w = WINDOW_SIZE_W;
	e->stop_motion = 1;
	// e->iter_max = ITERATION_MAX;
	ftl_draw_windows("42 Fractol", e);
	ftl_fractal_init(e);
	ftl_color_init(e);
	ftl_change_fractol(argv[1], e);
	mlx_expose_hook(e->win, ftl_expose_hook, e);
	mlx_mouse_hook(e->win, ftl_mouse_hook, e);
	mlx_hook(e->win, KEY_PRESS, KEY_PRESS_MASK, ftl_key_hook, e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, ftl_motion_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
