# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberglun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 17:10:30 by mberglun          #+#    #+#              #
#    Updated: 2019/12/11 19:47:40 by mberglun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = valid.test

# Directories, library
SRC_DIR = ./
OBJ_DIR = objs/
LIB_DIR = ./libft/
LIB = $(LIB_DIR)libft.a

# Files, library
SRC_FILES = valid.c read.c validate.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES:.c=.o))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
MKDIR_P = mkdir -p

all: dirs $(LIB) $(NAME)

$(LIB):
	make -C $(LIB_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(LIB_DIR) -L./libft/ -lft

$(OBJS): $(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -g -o $@ -I $(LIB_DIR)

clean:
	-rm -rf $(OBJ_DIR)

fclean: clean
	-rm -f $(NAME)

re: fclean all

# Creates necessary directories as needed, ex. for objects.
dirs: $(OBJ_DIR)

$(OBJ_DIR):
	$(MKDIR_P) $(OBJ_DIR)
#end of file
