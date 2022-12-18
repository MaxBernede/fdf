# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 18:33:53 by kyuuh             #+#    #+#              #
#    Updated: 2022/12/16 15:27:24 by kyuuh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	:= 		starting.c\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c\

RM 		:= 		rm -f

NAME	:=		fdf

#CFLAGS	:=		-Wall -Werror -Wextra

CC		:= 		cc

OBJ 	:= 		${SRCS:.c=.o}

AR 		:= 		ar	-rs

$(NAME): arc $(OBJ)
	@$(CC) -o $@ -I -L./libft/libft -l./libft/libft.a $(OBJ)

arc :
	@make -C ./libft/

all : ${NAME}

clean: 
	${RM} ${OBJ} && make clean -C ./libft

fclean: 	clean
	${RM} ${NAME} && make fclean -C ./libft

re: 	fclean all

.PHONY:		all clean fclean re
