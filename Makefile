# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrubin <nrubin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 11:40:37 by nrubin            #+#    #+#              #
#    Updated: 2021/09/15 12:07:24 by nrubin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRC	=	map_check.c \

OBJ		=	$(SRC:.c=.o)

CC		=	clang -Wall -Werror -Wextra

.c.o:
		@$(CC) -c $< -o ${<:.c=.o}

all:	$(NAME)

$(NAME):	$(OBJ)
			make -s -C ./libft
			$(CC) $(OBJ) -Llibft -lft -o $(NAME)

clean:
		make -s clean -C ./libft
		rm -f $(OBJ)

fclean:	clean
		make -s fclean -C ./libft
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re