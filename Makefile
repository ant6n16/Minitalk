# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 19:39:00 by antdelga          #+#    #+#              #
#    Updated: 2023/03/10 23:46:12 by antdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C	=	./src/client.a
NAME_S	=	./src/server.a

LIBFT_R = ./libft
LIBFT = ${LIBFT_R}/libft.a

SRCS	=	./src/main_client.c \
			./src/main_server.c \

OBJS	=	${SRCS:.c=.o}

CC		=	gcc
CFLAGS	=   -Wall -Wextra -Werror

.c.o:	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${LIBFT_R}

all:	${LIBFT} ${NAME_C}
		${LIBFT} ${NAME_S}

${LIBFT}:	${LIBFT_R}/*.c
	make -C ${LIBFT_R}

${NAME}:	${OBJS}
	cp ${LIBFT} ${NAME_C}
	cp ${LIBFT} ${NAME_S}
	ar crs ${NAME_C} ${OBJS}
	ar crs ${NAME_S} ${OBJS}
	${CC} ${CFLAGS} ./src/client.a ./src/main_client.c -o client
	${CC} ${CFLAGS} ./src/server.a ./src/main_server.c -o server

clean:
	make clean -C ${LIBFT_R}
	rm -f ${OBJS} ${BONUS_OBJS}

fclean:	clean
	rm -f ${NAME}
	rm -f client
	rm -f server
	make fclean -C ${LIBFT_R}

re:	fclean all

.PHONY:	all clean fclean re libft
