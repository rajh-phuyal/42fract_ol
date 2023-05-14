# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 19:37:52 by rphuyal           #+#    #+#              #
#    Updated: 2023/05/14 13:40:58 by rphuyal          ###   ########.fr        #
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

ifeq ($(UNAME), Darwin) # macOS
    CC = gcc
	LFLAGS += -L./minilibx -lmlx -framework OpenGL -framework AppKit
else #Linux and others...
    CC = gcc
	LFLAGS += -L./minilibx -lmlx -lbsd -lXext -lX11 -lm
endif

SRC     = src/main.c # list of source files

OBJ     = $(SRC:%.c=%.o) # convert source files to binary list

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@  # convert source files to binary list

# $(OBJDIR)/%.o: %.c
#     $(CC) $(CFLAGS) -c $< -o $@

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