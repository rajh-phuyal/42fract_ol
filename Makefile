# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 14:29:34 by jalves-c          #+#    #+#              #
#    Updated: 2023/05/28 20:31:11 by rphuyal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
CC		=	@gcc
FLAGS	=	-fsanitize=address 
LFT		=	libft/libft.a
MLX 	=	mlx/libmlx.a
LIB		=	-L ./libft -lft -L ./mlx -L/usr/X11/lib -lmlx -lXext -lX11
INC		=	-I ./libft -I ./mlx
SRC		=	src/core/main.c \
			src/core/initializations.c \
			src/window/hooks.c \
			src/window/painter.c \
			src/window/colors.c \
			src/cache/hash_id.c \
			src/cache/crud.c \
			src/computes/helper.c \
			src/computes/julia.c \
			src/computes/mandelbrot.c \
			
OBJ		= 	$(patsubst src/%.c,obj/%.o,$(SRC))

#COLORS
RED =		\033[0;31m
GREEN =		\033[0;32m
YELLOW =	\033[0;33m
RESET =		\033[0m


all:		$(MLX) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling $(NAME)..."
			$(CC) $(FLAGS) -o $@ $^ $(LIB)
			@echo "[" "$(GREEN)OK$(RESET)" "] | $(NAME) ready!"

$(MLX):
			@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling minilibx..."
			@make -sC mlx > /dev/null 2>&1
			@echo "[" "$(GREEN)OK$(RESET)" "] | Minilibx ready!"

$(LFT):		
			@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling libft..."
			@make -sC libft
			@echo "[" "$(GREEN)OK$(RESET)" "] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o: 	src/%.c
			@mkdir -p $(dir $@)
			$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
			@make -sC libft clean
			@make -sC mlx clean > /dev/null
			@rm -rf $(OBJ) obj
			@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

fclean:		clean
			@make -sC libft fclean
			@rm -rf $(NAME)
			@echo "[" "$(GREEN)OK$(RESET)" "] | Binary file removed."


re:			fclean all