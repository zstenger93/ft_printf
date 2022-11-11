# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:50:59 by zstenger          #+#    #+#              #
#    Updated: 2022/11/11 15:16:56 by zstenger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=cc

CFLAGS= -Wall -Wextra -Werror

SRC= ft_printf.c ft_check_format.c ft_print_hex.c ft_putnbr.c ft_putstr.c \
	 ft_putchar.c

OBJS=$(SRC:.c=.o)

RM=	rm -f

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
CYAN = \033[0;96m

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS) $?
	@echo "$(GREEN)Compilation successful.$(DEF_COLOR)"
	
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@echo "$(CYAN)Object files are successfully removed!$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(CYAN)All .o & .a files have been removed!$(DEF_COLOR)"

re: fclean all
	@echo "$(RED)Files have been cleaned and project has been rebuilt!$(DEF_COLOR)"

.PHONY: all clean fclean re