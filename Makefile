# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/30 14:18:45 by ybarbier          #+#    #+#              #
#    Updated: 2015/03/30 14:18:49 by ybarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft/includes/

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast -I $(PATH_INC)

LIBS = -lm -L libft/ -lft -L/usr/X11/lib -lmlx -lXext -lX11

HEAD = fdf.h

SRC =	main.c \
		# parse_arg.c \
		# ftl_draw.c \
		# ftl_cal_matrice.c \
		# ftl_matrice.c \
		# ftl_error.c \
		# ftl_hook.c \
		# ftl_helper.c

OBJ = $(addprefix $(PATH_SRC), $(SRC:.c=.o))


all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

.PHONY: clean fclean

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
