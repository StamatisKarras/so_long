NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -ggdb3 -I. -g -Ofast

LIBS = ./Custom_Libft/libft.a $(LIB_MLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIB_MLX = ./MLX42
LIB_DIR = ./Custom_Libft
HEADER = -I . -I $(LIB_MLX)/include

SRC = so_long.c \
	  char_checks.c \
	  move.c \
	  free_game.c \
	  free.c \
	  helper.c \
	  map.c \
	  reachable.c \
	  render.c

OBJ = $(SRC:.c=.o)

.SILENT:

all: libmlx lib $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBS) $(HEADER) -o $(NAME)

lib:
	$(MAKE) -C $(LIB_DIR) -j4

libmlx:
	@cmake $(LIB_MLX) -B $(LIB_MLX)/build && make -C $(LIB_MLX)/build -j4

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(HEADER)

re: fclean all

clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C $(LIB_DIR)
fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIB_MLX)/build
	$(MAKE) fclean -C $(LIB_DIR)

.PHONY: all lib libmlx clean fclean re
