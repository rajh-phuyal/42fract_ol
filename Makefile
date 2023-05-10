# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/22 23:12:10 by pbondoer          #+#    #+#              #
#    Updated: 2023/05/09 16:14:28 by rphuyal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

INC     = /usr/local/include

LIBFT   = ./libft
LIBMLX  = ./miniLibX

UNAME   := $(shell uname) # get the OS name

CFLAGS  = -Wall -Werror -Wextra -O3 -g -I$(INC) -I${INCFT} -Iinclude

LFLAGS  = -L$(LIBMLX) -L${LIBFT} -lft

SRC     = $(wildcard src/*.c) # list of source files

OBJDIR  = ./obj
OBJ     = $(SRC:.c=.o) # convert source files to binary list

# ifeq ($(UNAME), Darwin) # iMac / iOS
# 	CC = gcc
# 	LFLAGS += -framework OpenGL -framework AppKit
# else ifeq ($(UNAME), FreeBSD) # FreeBSD
# 	CC = clang
# else #Linux and others...
# 	CC = gcc
# 	LFLAGS += -lbsd -lXext -lX11 -lm
# endif

all: $(NAME)

$(NAME): createlibft $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

createlibft:
	make -C libft --no-print-directory

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC			: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"
