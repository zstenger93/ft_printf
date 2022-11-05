# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:50:59 by zstenger          #+#    #+#              #
#    Updated: 2022/11/05 11:56:35 by zstenger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_printf.c

OBJS	=	$(SRC:.c=.o)

CC		=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

all:	$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	$(NAME)

.PHONY: all clean fclean re