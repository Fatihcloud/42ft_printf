# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbulut <fbulut@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 13:33:22 by fbulut            #+#    #+#              #
#    Updated: 2022/02/10 22:04:41 by fbulut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

	
OBJS=src/printf_utils.o src/ft_printf.o 


CC=gcc
CFLAGS=	-Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS)  -c $^ -o $@

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

norm:
	@norminette src/*.[ch]

re: fclean all

help :
	@echo "------------------------------------ <<HELP COMMAND>> ------------------------------------"
	@echo "make            --------- compiles all *.c files and create libftprintf.a library"
	@echo "make clean      --------- cleans all *.o files in sources"
	@echo "make fclean 	--------- cleans all *.o files in sources and libftprintf.a library"
	@echo "make re         --------- cleans all files and compiles again"
	@echo "make norm       --------- controls all *.c and *.h codes to norminette standart"
	@echo "                --------- if finds norminette error will break"

.PHONY: all clean fclean re	