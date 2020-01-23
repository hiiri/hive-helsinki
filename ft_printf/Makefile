# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 16:52:55 by alcohen           #+#    #+#              #
#    Updated: 2020/01/14 20:17:48 by alcohen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

INCLUDES = libft/

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I $(INCLUDES) -L./libft/ -lft
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	/bin/rm -f $(OBJS)
	make -C $(INCLUDES) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(INCLUDES) fclean

re: fclean all
