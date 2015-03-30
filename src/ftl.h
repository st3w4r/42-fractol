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
**	Draw
**	\file fdf_draw.c
*/
void			ftl_draw_windows(char *title, t_env *e);
// void				draw_reload(t_env *e);

/*
**	Hook
**	\file fdf_hook.c
*/
int				ftl_key_hook(int keycode, t_env *e);

#endif
