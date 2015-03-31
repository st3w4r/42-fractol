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

typedef struct	s_env {
	void	*mlx;
	void	*win;
	void	*img;
	char	*pixel_img;
	int		bpp;
	int		s_line;
	int		ed;
	int		win_size_h;
	int		win_size_w;
	int		zoom_x;
	int		zoom_y;
	int		iter_max;
}				t_env;

typedef struct	s_complexe {
	int		r;
	int		i;
}				t_complexe;

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
void			ftl_draw_windows(char *title, t_env *e);
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
int				ftl_fractal_mandelbrot(t_env *e, int x, int y);

/*
**	Name: Fractal
**	File: fdf_fractal.c
**	Desc: All fucntions fractal
*/
int				ftl_fractal_mandelbrot(t_env *e, int x, int y);


#endif
