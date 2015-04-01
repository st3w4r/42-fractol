/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 15:06:53 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/30 15:06:55 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTL_H
# define FTL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "../libft/includes/libft.h"

# define FREE(x) { if (x) free(x); x = NULL; }
# define FREE_ARR(x) { if (x && *x) ft_arrfree(&x); }

# define WINDOW_SIZE_H 500
# define WINDOW_SIZE_W 500

# define ITERATION_MAX 50


/*
**	Key code
*/
# define KEY_ESC 53

# define KEY_KP_DOT 65
# define KEY_KP_ENTER 76
# define KEY_KP_0 82
# define KEY_KP_1 83
# define KEY_KP_2 84
# define KEY_KP_3 85
# define KEY_KP_4 86
# define KEY_KP_5 87
# define KEY_KP_6 88
# define KEY_KP_7 89
# define KEY_KP_8 91
# define KEY_KP_9 92
# define KEY_KP_PLUS 69
# define KEY_KP_MINUS 78

typedef struct	s_point {
	double	x;
	double	y;
}				t_point;

typedef struct	s_complexe {
	double	r;
	double	i;
}				t_complexe;

typedef struct	s_fractal {
	t_complexe	c;
	t_complexe	z;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom_x;
	double		zoom_y;
	double		tmp;
	int			iter;
	int			iter_max;
	void		*func;
}				t_fractal;

typedef struct	s_env {
	void		*mlx;
	void		*win;
	void		*img;
	char		*pixel_img;
	int			bpp;
	int			s_line;
	int			ed;
	int			win_size_h;
	int			win_size_w;
	// int			zoom_x;
	// int			zoom_y;
	// int		iter_max;
	t_fractal	*ftl_ptr;
	t_fractal	*ftl_arr;
}				t_env;

/*
** Name: ft_error
** File: ft_error.c
** Desc: Error Gestion
*/
void				ft_exit(void);
void				ft_malloc_error(void);
void				ft_error_str(char *str);
void				ft_error_str_exit(char *str);

/*
**	Name: Draw
**	File: fdf_draw.c
**	Desc: All function Draw
*/
// void			ftl_draw_fractal(t_env *e);
void			ftl_draw_windows(char *title, t_env *e);
void			ftl_draw_pixel_img(t_point *point, t_env *e, int color);
void			ftl_draw_reload(t_env *e);
// void				draw_reload(t_env *e);

/*
**	Name: Hook
**	File: fdf_hook.c
**	Desc: All Hook event
*/
int				ftl_key_hook(int keycode, t_env *e);

/*
**	Name: Calculate
**	File: fdf_cal.c
**	Desc: All functions calcul
*/
void			ftl_cal_apply(t_env *e, t_fractal *ftl, int (*f)(t_env*, t_fractal, t_point*));

/*
**	Name: Fractal
**	File: fdf_fractal.c
**	Desc: All fucntions fractal
*/
void			ftl_fractal_init(t_env *e);
int				ftl_fractal_mandelbrot(t_env *e, t_fractal ftl, t_point *point);
int				ftl_fractal_julia(t_env *e, t_fractal ftl, t_point *point);

/*
**	Name: Helper
**	File ftl_helper.c
**	Desc: Function Helpers
*/
int				ftl_rgb_to_hexa(int r, int g, int b);

#endif
