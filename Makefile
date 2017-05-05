# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qho <qho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:21:43 by qho               #+#    #+#              #
#    Updated: 2017/05/05 13:27:00 by qho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	my_database
# EXE		=	my_printf

# Flags and compiler
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

# Libraries
LIBFT	=	libft/ -lft

# Source and header files, and directory
INC		=	./inc/
FILES	=	main ft_db ft_insert ft_update ft_delete ft_print_all \
			ft_save ft_insert_row ft_insert_col	ft_load_db \
			ft_print_handler ft_print_s ft_help

T_FILES	=	ft_fork ft_strsplit	ft_test	\

SRC		=	$(addprefix src/, $(addsuffix .c, $(FILES)))
T_SRC		=	$(addprefix src/, $(addsuffix .c, $(T_FILES)))
# SRC		=	src/ft_db.c

# Object directory and files
OBJ	=	$(addsuffix .o, $(FILES))

.PHONY: clean fclean re norm

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft
	@echo "\033[32mCompiled libft\033[0m"
	@$(CC) -g -I$(INC) -L $(LIBFT) $(SRC) -o $(NAME)
	@echo "\033[32m$(NAME) compiled\033[0m"
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
	@make -C libft clean

fclean: clean
	@/bin/rm -f $(NAME) $(EXE)
	@echo "\033[31mCleaning $(NAME)\033[0m"
	@make -C libft fclean

re: fclean all
