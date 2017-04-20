# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qho <qho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:21:43 by qho               #+#    #+#              #
#    Updated: 2017/04/20 13:24:49 by qho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	my_database
# EXE		=	my_printf

# Flags and compiler
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

# Source and header files, and directory
INC		=	./inc/
FILES	=	ft_db	\
SRC		=	$(addprefix src/, $(addsuffix .c, $(FILES)))

# Object directory and files
OBJ	=	$(addsuffix .o, $(FILES))

.PHONY: clean fclean re norm

all: $(OBJ) $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib	$(NAME)
	@echo "\033[32m$(NAME) made\033[0m"

$(OBJ):	$(SRC)
	@$(CC) -c $(CFLAGS) $(SRC) -I$(INC)
	@echo "\033[32mObject files made\033[0m"

# test: $(NAME)
# 	@$(CC) -Wformat -I$(INC) $(NAME) random.c main.c -o $(EXE)

norm:
	@norminette $(SRC) $(INC)

clean:
	@/bin/rm -rf $(OBJ)
	@echo "\033[31mCleaning object files\033[0m"

fclean: clean
	@/bin/rm -f $(NAME) $(EXE)
	@echo "\033[31mCleaning $(NAME)\033[0m"

re: fclean all
