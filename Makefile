# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 19:39:00 by antdelga          #+#    #+#              #
#    Updated: 2023/03/21 00:38:01 by antdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C	=	./src/client.a
NAME_S	=	./src/server.a

LIBFT_R = ./libft
LIBFT = ${LIBFT_R}/libft.a

SRCS_C	=	./src/main_client.c \

SRCS_S  =	./src/main_server.c \

OBJS_C	=	${SRCS_C:.c=.o}
OBJS_S	=	${SRCS_S:.c=.o}

CC		=	gcc
CFLAGS	=   -Wall -Wextra -Werror

all:	${LIBFT} ${NAME_C} ${NAME_S}

.c.o:	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${LIBFT_R}

${LIBFT}:	${LIBFT_R}/*.c
	make -C ${LIBFT_R}

${NAME_C}:	${OBJS_C} 
	@${CC} ${CFLAGS} ./libft/libft.a ./src/main_client.c -o client

${NAME_S}:	${OBJS_S}
	@${CC} ${CFLAGS} ./libft/libft.a ./src/main_server.c -o server

clean:
	make clean -C ${LIBFT_R}
	rm -f ${OBJS_C} ${OBJS_S} ${BONUS_OBJS}

fclean:	clean
	rm -f ${NAME_C}
	rm -f ${NAME_S}
	rm -f client
	rm -f server
	make fclean -C ${LIBFT_R}

re:	fclean all

.PHONY:	all clean fclean re libft
