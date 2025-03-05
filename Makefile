NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -ggdb3 -I. -g -Ofast

LIBS = ./Custom_Libft/libft.a $(LIB_MLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIB_MLX = ./MLX42
LIB_MLX_A = $(LIB_MLX)/build/libmlx42.a
LIB_DIR = ./Custom_Libft
LIB_A = $(LIB_DIR)/libft.a
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

all: $(LIB_MLX_A) $(LIB_A) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBS) $(HEADER) -o $(NAME)

$(LIB_A):
	$(MAKE) -C $(LIB_DIR) -j4

$(LIB_MLX_A):
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

.PHONY: all clean fclean re
