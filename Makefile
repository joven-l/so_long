NAME = so_long
CC=gcc
CFLAGS=-Wall -Wextra -Werror -g -O0
# CC=cc
# CFLAGS=-Wall -Wextra -Werror
INC_DIR = includes
IFLAGS = -I$(INC_DIR)
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a
SRC_DIR = src
MLX= -lmlx -lXext -lX11 -lm -lz
SOURCES= \
$(SRC_DIR)/background.c \
$(SRC_DIR)/conv_sprites.c \
$(SRC_DIR)/enemy.c \
$(SRC_DIR)/game.c \
$(SRC_DIR)/init.c \
$(SRC_DIR)/input.c \
$(SRC_DIR)/map.c \
$(SRC_DIR)/shorten.c \
$(SRC_DIR)/so_long_utils.c \
$(SRC_DIR)/so_long.c 

all: $(NAME)

OBJECTS = $(SOURCES:.c=.o)

$(NAME) : $(OBJECTS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJECTS) $(LIBFT_A) $(MLX) -o $(NAME) 

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re