# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 21:26:23 by rphuyal           #+#    #+#              #
#    Updated: 2023/07/04 01:55:46 by rphuyal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = fractol

OS    = $(shell uname)

CC    = @gcc

FLAGS = -g -fsanitize=address

LFT   = libft/libft.a

INC   = -I./libft -I./mlx -I./mlx_mac

SRC   = src/core/main.c \
			src/core/initializations.c \
			src/window/hooks.c \
			src/window/painter.c \
			src/window/zoom.c \
			src/computes/helper.c \
			src/computes/julia.c \
			src/computes/mandelbrot.c \
			src/computes/burningship.c

OBJ   = $(patsubst src/%.c, obj/%.o, $(SRC))

ifeq ($(OS), Darwin)
    MLX = mlx_mac/libmlx.a
	INC_MLX = mlx_mac
    LIB = -L./libft -lft -L./mlx_mac -lmlx -framework OpenGL -framework AppKit
else
    MLX = mlx/libmlx.a
	INC_MLX = mlx
    LIB = -L./libft -lft -L./mlx -lmlx -lXext -lX11
endif

# COLORS
CBOLD   = \033[0;1m
RED     = \033[0;41m
GREEN   = \033[0;42m
BLUE   = \033[0;44m
YELLOW  = \033[0;43m
RESET   = \033[0m

all: $(LFT) $(MLX) obj $(NAME)

$(NAME): $(OBJ)
	@echo "$(CBOLD)$(YELLOW)  Compiling $(NAME) $(RESET)"
	$(CC) $(FLAGS) -o $@ $^ $(LIB)
	@echo "$(CBOLD)$(GREEN)    $(NAME) ready!  $(RESET)"

$(MLX):
	@echo "$(CBOLD)$(YELLOW) Compiling Minilibx $(RESET)"
	@make -sC $(INC_MLX) > /dev/null 2>&1
	@echo "$(CBOLD)$(GREEN)   Minilibx ready!  $(RESET)\n ↪"

$(LFT):
	@echo "$(CBOLD)$(YELLOW)  Compiling Libft   $(RESET)"
	@make -sC ./libft
	@echo "$(CBOLD)$(GREEN)    Libft ready!    $(RESET)\n ↪"

obj:
	@mkdir -p obj

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@make -sC libft clean
	@make -sC $(INC_MLX) clean > /dev/null
	@rm -rf $(OBJ) obj
	@echo "$(CBOLD)$(BLUE)  Objects removed!  $(RESET)"

fclean: clean
	@make -sC libft fclean
	@rm -rf $(NAME)
	@echo "$(CBOLD)$(BLUE)  Binaries removed! $(RESET)"

re: fclean all

.PHONY: all