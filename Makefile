# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qho <qho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:21:43 by qho               #+#    #+#              #
#    Updated: 2017/05/02 23:05:02 by qho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	my_database
# EXE		=	my_printf

# Flags and compiler
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

# Source and header files, and directory
INC		=	./inc/
FILES	=	ft_db ft_fork ft_strsplit ft_insert ft_update ft_delete ft_print	\
			ft_save ft_utils ft_insert_row ft_insert_col	\

T_FILES	=	ft_fork ft_strsplit	ft_test	\

SRC		=	$(addprefix src/, $(addsuffix .c, $(FILES)))
T_SRC		=	$(addprefix src/, $(addsuffix .c, $(T_FILES)))
# SRC		=	src/ft_db.c

# Object directory and files
OBJ	=	$(addsuffix .o, $(FILES))

.PHONY: clean fclean re norm

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) -I$(INC) $(SRC) -o $(NAME)
# 	@ar rc $(NAME) $(OBJ)
# 	@ranlib	$(NAME)
# 	@echo "\033[32m$(NAME) made\033[0m"

# $(OBJ):	$(SRC)
# 	@$(CC) -c $(CFLAGS) $(SRC) -I$(INC)
# 	@echo "\033[32mObject files made\033[0m"

test:
	@$(CC) -I$(INC) $(T_SRC) -o $(NAME)

norm:
	@norminette $(SRC) $(INC)

clean:
	@/bin/rm -rf $(OBJ)
	@echo "\033[31mCleaning object files\033[0m"

fclean: clean
	@/bin/rm -f $(NAME) $(EXE)
	@echo "\033[31mCleaning $(NAME)\033[0m"

re: fclean all
