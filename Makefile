# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasi-moh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 16:32:56 by fasi-moh          #+#    #+#              #
#    Updated: 2021/11/17 16:33:53 by fasi-moh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		./srcs/main.c\
					./srcs/parser_map.c\
					./srcs/window_size.c\
					./srcs/get_texture.c\
					./srcs/do_map.c\
					./srcs/keyboard_actions.c\
					./srcs/get_next_line.c\
					./srcs/get_next_line_utils.c\

OBJS 		= ${SRCS:.c=.o}

UNAME		:= $(shell uname)
PATH_MLX	= mlx
CC 			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all
