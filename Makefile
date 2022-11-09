# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 16:27:34 by nhorta-g          #+#    #+#              #
#    Updated: 2022/10/08 16:27:37 by nhorta-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = 	src/so_long\
		src/initialize\
		src/errors\
		src/checks\
		src/utils\
		src/draw_map\
		src/moves\
		src/key_hook\
		gnl/get_next_line\

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I. -fsanitize=address
LINKS = -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX = ./mlx_linux/libmlx_Linux.a

all: $(NAME)

$(NAME): $(SRC:=.o) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC:=.o) $(LINKS) $(LIBFT) -o $(NAME)
	echo "So_long is ready!"

%.o: %.c
	$(CC) $(CFLAGS) -I /usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C mlx_linux

clean:
	$(RM) $(SRC:=.o)
	make clean -C libft
	echo "So_long files removed!"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	make clean -C mlx_linux
	make fclean -C libft
	echo "Totally clean!"

re: fclean all

.PHONY: all clean fclean re
