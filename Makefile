# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 19:39:00 by antdelga          #+#    #+#              #
#    Updated: 2023/03/22 20:07:10 by antdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	./src/minitalk.a

LIBFT_R = ./libft
LIBFT = ${LIBFT_R}/libft.a

SRCS	=	./src/main_client.c \
			./src/main_server.c \

OBJS	=	${SRCS:.c=.o}

BONUS	=	./src/main_client_bonus.c \
			./src/main_server_bonus.c \

BONUS_OBJS	=	${BONUS:.c=.o}

CC		=	gcc
CFLAGS	=   -Wall -Wextra -Werror

all:	${LIBFT} ${NAME}

.c.o:	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${LIBFT_R}

${LIBFT}:	${LIBFT_R}/*.c
	make -C ${LIBFT_R}

${NAME}:	${OBJS}
	cp ${LIBFT} ${NAME}
	ar crs ${NAME} ${OBJS}
	${CC} ${CFLAGS} ./src/minitalk.a ./src/main_client.c -o client
	${CC} ${CFLAGS} ./src/minitalk.a ./src/main_server.c -o server

bonus:	${BONUS_OBJS}
	make -C ${LIBFT_R}
	cp ${LIBFT} ${NAME}
	ar crs ${NAME} ${BONUS_OBJS}
	${CC} ${CFLAGS} ./src/minitalk.a ./src/main_client_bonus.c -o client
	${CC} ${CFLAGS} ./src/minitalk.a ./src/main_server_bonus.c -o server

clean:
	make clean -C ${LIBFT_R}
	rm -f ${OBJS} ${OBJS} ${BONUS_OBJS}

fclean:	clean
	rm -f ${NAME}
	rm -f client
	rm -f server
	make fclean -C ${LIBFT_R}

re:	fclean all

.PHONY:	all clean fclean re libft
