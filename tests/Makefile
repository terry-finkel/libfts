# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 14:21:40 by pguillie          #+#    #+#              #
#    Updated: 2019/04/05 15:25:36 by nfinkel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= test_libfts
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -I $(INCDIR)

LIBFTS := ../libfts.a

INCDIR := includes/
SRCDIR := sources/

INCLUDES = $(addprefix $(INCDIR), \
	libfts.h \
	tests.h \
)

SOURCES = $(addprefix $(SRCDIR), \
	main.c \
	test_bzero.c \
	test_cat.c \
	test_ctype.c \
	test_isalnum.c \
	test_isalpha.c \
	test_isascii.c \
	test_isdigit.c \
	test_isprint.c \
	test_memcmp.c \
	test_memcpy.c \
	test_memset.c \
	test_puts.c \
	test_strcat.c \
	test_strcmp.c \
	test_strdup.c \
	test_strlen.c \
	test_tolower.c \
	test_toupper.c \
)

OBJECTS = $(SOURCES:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFTS)
	@gcc -o $(NAME) $(OBJECTS) $(LIBFTS)

$(LIBFTS):
	@make -C $(dir $(LIBFTS))

$(OBJECTS): $(INCLUDES) Makefile

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
