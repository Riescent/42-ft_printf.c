# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 19:13:43 by vfries            #+#    #+#              #
#    Updated: 2022/11/12 21:34:18 by vfries           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c		\
				get_final_str.c

DIR_OBJS	=	.objs/

OBJS		=	${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

FLAG		=	-Wall -Wextra -Werror

HEADERS		=	ft_printf.h	\
				${LIBFT_H}

INCLUDES	=	${LIBFT_PATH}

LIBFT_PATH	=	libft

LIBFT_A		=	${LIBFT_PATH}/libft.a

LIBFT_H		=	${LIBFT_PATH}/libft.h

CC			=	cc

RMF			=	rm -f

MAKE_LIBFT	=	cd ${LIBFT_PATH} && ${MAKE}

.PHONY:			all clean fclean re

all:			${DIR_OBJS}
			@${MAKE_LIBFT}
			@${MAKE} -j ${NAME}

${DIR_OBJS}:
			mkdir ${DIR_OBJS}

get_libft_objs_path:
			@${MAKE_LIBFT} echo_objs\
				| sed 's/^/ /'\
				| sed -e 's/ ./ ${LIBFT_PATH}/g'

$(NAME):		${OBJS}
			ar rcs ${NAME} ${OBJS} ${shell ${MAKE} get_libft_objs_path}

${DIR_OBJS}%.o:	%.c ${HEADERS} Makefile
			${CC} ${FLAG} -I ${INCLUDES} -c $< -o $@

clean:
			@${MAKE_LIBFT} clean
			${RMF} ${OBJS} ${OBJS_BONUS}

fclean:			clean
			${RMF} ${LIBFT_A}
			${RMF} ${NAME}

re:				fclean
			@${MAKE} all
