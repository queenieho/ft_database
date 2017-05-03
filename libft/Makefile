
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apineda <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 14:51:31 by apineda           #+#    #+#              #
#    Updated: 2016/10/05 16:19:15 by apineda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILENAMES_1 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strcpy.c \
			ft_strncpy.c ft_strdup.c ft_strcat.c ft_strncat.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_atoi.c ft_strstr.c ft_strcmp.c \
			ft_strncmp.c ft_strnstr.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c
FILENAMES_2 = ft_memalloc.c	ft_putstr.c ft_putchar.c ft_memdel.c ft_strnew.c \
			  ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
			  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
			  ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putendl.c ft_putnbr.c \
			  ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c 
FILENAMES_3 = ft_back_white.c ft_front_white.c ft_absval.c ft_lstnew.c \
			  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
			  ft_isupper.c ft_islower.c ft_itoa_base.c get_next_line.c

CC = gcc
AR = ar

SOURCES_1 = $(FILENAMES_1)
OBJECTS_1 = $(addprefix build1/, $(FILENAMES_1:.c=.o))

SOURCES_2 = $(FILENAMES_2)
OBJECTS_2 = $(addprefix build2/, $(FILENAMES_2:.c=.o))

SOURCES_3 = $(FILENAMES_3)
OBJECTS_3 = $(addprefix build3/, $(FILENAMES_3:.c=.o))

CCFLAGS ?= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS_1) $(OBJECTS_2) $(OBJECTS_3)
	@$(AR) rc $@ $^
	@ranlib $@

build1:
	@mkdir $@

build2:
	@mkdir $@

build3:
	@mkdir $@

build1/%.o: %.c | build1
	@$(CC) $(CCFLAGS) -c $^ -o $@

build2/%.o: %.c | build2
	@$(CC) $(CCFLAGS) -c $^ -o $@

build3/%.o: %.c | build3
	@$(CC) $(CCFLAGS) -c $^ -o $@

clean:
	@rm -rf build1
	@rm -rf build2
	@rm -rf build3

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
