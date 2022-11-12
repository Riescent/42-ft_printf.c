# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 19:13:43 by vfries            #+#    #+#              #
#    Updated: 2022/11/12 22:33:14 by vfries           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c		\
				get_final_str.c	\
				formating/format.c

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

MKDIR		=	mkdir -p

.PHONY:			all get_libft_objs_path clean fclean re

all:			${DIR_OBJS}
			@${MAKE_LIBFT}
			@${MAKE} -j ${NAME}

${DIR_OBJS}:
			echo ${OBJS} | tr ' ' '\n'\
				| sed 's|\(.*\)/.*|\1|'\
				| sed 's/^/${MKDIR} /'\
				| sh -s
			# Prints all OBJS. 1 per line
				# Removes the .o file names
				# Adds mkdir -p at start of the line
				# Executes the script (Creates all folders)

get_libft_objs_path:
			@${MAKE_LIBFT} echo_objs\
				| sed 's/^/ /'\
				| sed -e 's/ ./ ${LIBFT_PATH}/g'

$(NAME):		${OBJS}
			ar rcs ${NAME} ${OBJS} ${shell ${MAKE} get_libft_objs_path}

${DIR_OBJS}%.o:	%.c ${HEADERS} Makefile
			${CC} ${FLAG} -I ${INCLUDES} -c $< -o $@

clean:
			${MAKE_LIBFT} clean
			${RMF} ${OBJS} ${OBJS_BONUS}

fclean:			clean
			${RMF} ${LIBFT_A}
			${RMF} ${NAME}

re:				fclean
			${MAKE} all
