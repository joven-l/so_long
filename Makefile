NAME = so_long
# CC=gcc
# CFLAGS=-Wall -Wextra -Werror -ggdb3
CC=cc
CFLAGS=-Wall -Wextra -Werror
INC_DIR = includes
IFLAGS = -I$(INC_DIR)
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX_A = $(MLX_DIR)/libmlx.a
SRC_DIR = src
MLX= -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
SOURCES= \
$(SRC_DIR)/game.c \
$(SRC_DIR)/init.c \
$(SRC_DIR)/input.c \
$(SRC_DIR)/map.c \
$(SRC_DIR)/so_long_utils.c \
$(SRC_DIR)/so_long.c 

all: $(NAME)

OBJECTS = $(SOURCES:.c=.o)

$(NAME) : $(OBJECTS) $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(IFLAGS) -Iminilibx-linux $(OBJECTS) $(LIBFT_A) $(MLX) $(MLX_A) -o $(NAME) 

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR) all

$(MLX_A):
	$(MAKE) -C $(MLX_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) $(IFLAGS) -Iminilibx-linux -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re