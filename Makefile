# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:50:59 by zstenger          #+#    #+#              #
#    Updated: 2022/11/07 14:13:49 by zstenger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=cc

CFLAGS= -Wall -Wextra -Werror

SRC= ft_printf.c ft_check_format.c ft_print_hex.c ft_putchar.c ft_putstr.c \
	 ft_putnbr.c

OBJS=$(SRC:.c=.o)

RM=	rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS) $?
	
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re