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

# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "../libft/includes/libft.h"

# define FREE(x) { if (x) free(x); x = NULL; }
# define FREE_ARR(x) { if (x && *x) ft_arrfree(&x); }

# define WINDOW_SIZE_H 729
# define WINDOW_SIZE_W 729

# define ITERATION_MAX 50

/*
**	Key code
*/
# define KEY_ESC 53

# define KEY_MOUSE_CLIC_L 1
# define KEY_MOUSE_CLIC_R 2
# define KEY_MOUSE_UP 5
# define KEY_MOUSE_DOWN 4
# define KEY_MOUSE_LEFT 7
# define KEY_MOUSE_RIGHT 6

# define KEY_0 29
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 26
# define KEY_8 28
# define KEY_9 25

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

# define KEY_PAGE_UP 116
# define KEY_PAGE_DOWN 121

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

/*
** Key event, Key mask
*/
# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6
# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2

typedef struct	s_point {
	double	x;
	double	y;
}				t_point;

typedef struct	s_complexe {
	double	r;
	double	i;
}				t_complexe;

typedef struct	s_palette {
	int			color_default;
	int			color_0;
	int			color_1;
	int			color_2;
	int			color_3;
	int			color_4;
	int			color_5;
	int			color_6;
	int			color_7;
	int			color_8;
	int			color_9;
}				t_palette;

typedef struct	s_fractal {
	t_complexe	c;
	t_complexe	z;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom_x;
	double		zoom_y;
	double		zoom_ratio;
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
	int			stop_motion;
	t_fractal	*ftl_ptr;
	t_fractal	*ftl_arr;
	t_palette	*p_color_ptr;
	t_palette	*p_color_arr;
}				t_env;

/*
** Name: ft_error
** File: ft_error.c
** Desc: Error Gestion
*/
void			ft_exit(void);
void			ft_malloc_error(void);
void			ft_error_str(char *str);
void			ft_error_str_exit(char *str);

/*
**	Name: Draw
**	File: fdf_draw.c
**	Desc: All function Draw
*/
void			ftl_draw_windows(char *title, t_env *e);
void			ftl_draw_pixel_img(t_point *point, t_env *e, int color);
void			ftl_draw_reload(t_env *e);

/*
**	Name: Hook
**	File: fdf_hook.c
**	Desc: All Hook event
*/
int				ftl_mouse_hook(int button, int x, int y, t_env *e);
int				ftl_motion_hook(int x, int y, t_env *e);
int				ftl_key_hook(int keycode, t_env *e);

/*
**	Name: Calculate
**	File: fdf_cal.c
**	Desc: All functions calcul
*/
void			ftl_cal_apply(t_env *e, t_fractal *ftl,
				int (*f)(t_env*, t_fractal, t_point*));

/*
**	Name: Fractal
**	File: fdf_fractal.c
**	Desc: Inti fractal, Fucntions fractal
*/
void			ftl_fractal_init(t_env *e);
int				ftl_fractal_mandelbrot(t_env *e, t_fractal ftl, t_point *point);
int				ftl_fractal_mandelbar(t_env *e, t_fractal ftl, t_point *point);
int				ftl_fractal_julia(t_env *e, t_fractal ftl, t_point *point);
int				ftl_fractal_b_ship(t_env *e, t_fractal ftl, t_point *point);

/*
**	Name: Fractal 2
**	File: fdf_fractal.c
**	Desc: Mpre fucntions fractal
*/
int				ftl_fractal_carpet(t_env *e, t_fractal ftl, t_point *point);

/*
**	Name: Helper
**	File ftl_helper.c
**	Desc: Function Helpers
*/
int				ftl_create_rgb(int r, int g, int b);
void			ftl_change_fractol(char *name_ftl, t_env *e);
void			ftl_key_hook_change_fractal(int keycode, t_env *e);
void			ftl_key_hook_change_color(int keycode, t_env *e);

/*
**	Name: Color
**	File ftl_color.c
**	Desc: Function colors
*/
void			ftl_color_init(t_env *e);
void			ftl_color_change(int num, t_env *e);
int				ftl_get_color(int z, t_palette palette);

#endif
