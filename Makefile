# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 14:36:24 by hucoulon          #+#    #+#              #
#    Updated: 2022/02/25 14:36:30 by hucoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS		= ./srcs/do_map.c \
				./srcs/get_next_line.c \
				./srcs/get_next_line_utils.c \
				./srcs/get_texture.c \
				./srcs/keyboard_actions.c \
				./srcs/main.c \
				./srcs/parser_map.c \
				./srcs/window_size.c \

OBJS		= ${SRCS:.c=.o}

NAME		= so_long

MLX_PATH	= ./mlx/
MLX_NAME	= $(MLX_PATH)libmlx_Linux.a

INC		= ./inc/

CC		= gcc -Wall -Werror -Wextra -g
RM		= rm -f

CFLAGS		= -lm -lmlx -lXext -lX11

all:		${NAME}

.c.o:
		${CC} -I${INC} -I${MLX_PATH} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		make -C ${MLX_PATH}
		${CC} ${OBJS} ${MLX_NAME} -L${MLX_PATH} -I${INC} -I${MLX_PATH} ${CFLAGS} -o${NAME}

clean:		
		make clean -C ${MLX_PATH}
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all
