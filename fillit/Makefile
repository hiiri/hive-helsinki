# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberglun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 17:10:30 by mberglun          #+#    #+#              #
#    Updated: 2019/12/13 18:47:49 by alcohen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fillit

# Directories, library
SRC_DIR = ./
OBJ_DIR = objs/
LIB_DIR = ./libft/
LIB = $(LIB_DIR)libft.a

## UNIT TESTS
## ================================
VALID_TEST_SRC = valid_test.c
VALID_TEST_OBJS = $(addprefix $(OBJ_DIR), $(VALID_TEST_SRC:.c=.o))
## ================================

# Files, library
SRC_FILES = fillit.c read.c validate.c map.c manager.c pieces.c solver.c
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
MKDIR_P = mkdir -p

all: dirs $(LIB) $(NAME)

$(LIB):
	make -C $(LIB_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(LIB_DIR) -L./libft/ -lft

$(OBJS): $(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -g -o $@ -I $(LIB_DIR)

## MAKE UNIT TEST BINARIES
## ================================
valid_test: all $(VALID_TEST_OBJS)
	$(CC) $(CFLAGS) $(VALID_TEST_OBJS) $(OBJ_DIR)read.o $(OBJ_DIR)validate.o -o valid.test -I $(LIB_DIR) -L./libft/ -lft


$(VALID_TEST_OBJS): $(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -g -o $@ -I $(LIB_DIR)
## ================================

clean:
	-rm -rf $(OBJ_DIR)

fclean: clean
	-rm -f $(NAME)
	-rm -f *.test

re: fclean all

# Creates necessary directories as needed, ex. for objects.
dirs: $(OBJ_DIR)

$(OBJ_DIR):
	$(MKDIR_P) $(OBJ_DIR)
#end of file
