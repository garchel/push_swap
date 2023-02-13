# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 11:09:55 by pauvicto          #+#    #+#              #
#    Updated: 2023/02/10 11:09:55 by pauvicto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
SRCDIR 	= src/
LIBDIR 	= libft/

SRCS 	= $(wildcard list/*.c movement/*.c src/*.c utils/*.c)
		
OBJ 	= $(SRCS:%.c=%.o)

FLAG_LEAK += --leak-check=full --show-leak-kinds=all --track-origins=yes
CFLAGS 	= -Wall -Wextra -Werror -Iincludes 

CC 		= cc
LIBFT 	= libft/libftprintf.a
REMOVE 	= rm -rf

all: $(NAME) 
$(NAME): $(OBJ)
	${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJ} ./libft/libft.a -o ${NAME}

clean: 
	${MAKE} -C ./libft fclean
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)
	
re: fclean
	make all

.PHONY: all clean fclean re