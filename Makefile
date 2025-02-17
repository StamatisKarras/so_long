NAME = game
CC = cc
FLAGS = -Wall -Wextra -Werror -ggdb3 -I. -g

LIB = ./Custom_Libft/libft.a
LIB_DIR = ./Custom_Libft
HEADER = so_long.h

SRC = main.c \
	  map_validity.c \
	  parse_map.c \
	  map_structure.c \
	  reachable.c \
	  free.c

OBJ = $(SRC:.c=.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJ) lib
	$(CC) $(FLAGS) $(OBJ) -L$(LIB_DIR) -lft -o $(NAME)

lib:
	$(MAKE) -C $(LIB_DIR)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C $(LIB_DIR)
fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)

.PHONY: all lib clean fclean re
