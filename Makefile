# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 10:45:43 by mbernede          #+#    #+#              #
#    Updated: 2023/01/05 16:42:17 by kyuuh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	:= 		main.c\
				second.c\
				grid.c\
				coordcolors.c

RM 		:= 		rm -f

NAME	:=		fdf

#CFLAGS	:=		-Wall -Werror -Wextra

CC		:= 		cc

OBJ_DIR	:=		./objs/

SRC_DIR	:=		./srcs/

LIBA	:=	libft/libft.a
LIBH	:=	libft/libft.h

LIBMLX	:=	MLX42/libmlx42.a
MLXFLAG	:=	-ldl -lglfw -lm -pthread -I MLX42/include

OBJ 	:= 		$(addprefix ${OBJ_DIR},${SRCS:.c=.o})

${NAME}:	${OBJ}
	@make -C libft
	@$(CC) -o $@ $^ $(LIBA) $(LIBMLX) $(MLXFLAG) 
	@echo "SUCCESS"

all : ${NAME}

${OBJ_DIR}%.o:	${SRC_DIR}%.c $(LIBH) fdf.h
	@${CC} ${CFLAGS} -o $@ -c $<

clean: 
	@make -C libft clean
	@${RM} ${OBJ}
	@echo "test cleaned"

fclean: 	clean
	@make -C libft fclean
	@${RM} ${NAME}
	@echo "full clean done"

re: 	fclean all

.PHONY:		all clean fclean re
