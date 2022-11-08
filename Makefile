# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 19:13:43 by vfries            #+#    #+#              #
#    Updated: 2022/11/08 23:05:20 by vfries           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRCS =		ft_printf.c	\
			get_final_str.c

OBJS =		${SRCS:.c=.o}

FLAG =		-Wall -Wextra -Werror

HEADERS =	ft_printf.h

INCLUDES =	libft

LIBFT	=	libft/libft.a

.PHONY:		all clean fclean re

all:		${NAME}

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

%.o:		%.c ${HEADERS} Makefile ${LIBFT}
			cc ${FLAG} -I ${INCLUDES} -o ${LIBFT} -c $< -o $@

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
			rm -f ${NAME}

re:			fclean
			${MAKE} all
