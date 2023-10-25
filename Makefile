FILES			= 	main.c \
					map_parsing.c \
					map_validating.c \
					render_map.c
SRC_DIR			= 	src
OBJ_DIR			= 	obj
SRC				= 	$(addprefix src/, $(FILES))
OBJ 			= 	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
CC = gcc

NAME			= 	so_long
MLX				= 	MLX42
MLX_LIB			= 	$(MLX)/build/
HEADER_DIR		= 	hfiles
LIBFT_DIR 		= 	libft
UNAME 			= 	$(shell uname -s)

ifeq ($(UNAME), Linux)
  OS_L_FLAGS	= 	-lmlx42 -lglfw -lm -ldl -pthread -lft
endif
ifeq ($(UNAME), Darwin)
  OS_L_FLAGS	= 	-framework Cocoa -framework OpenGL -framework IOKit -L"$(shell brew info glfw | grep files | cut -d " " -f1)/lib/" -lft -lglfw -lmlx42
endif
INCLUDES		= 	-I$(MLX)/include/ -I$(HEADER_DIR) -I$(LIBFT_DIR)
#ERROR_FLAGS 	= 	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): _mlx _libft $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -L$(MLX_LIB) -L$(LIBFT_DIR) $(OS_L_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(INCLUDES) $(ERROR_FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

_mlx:
	cmake $(MLX) -B $(MLX)/build
	make -C $(MLX)/build

_libft:
	make -C libft

clean:
	rm -f $(NAME)

fclean: clean
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX)/build clean

re: clean all

.PHONY: all, clean, fclean, re, libmlx

test:
	$(CC) $(OBJ) -L$(MLX_LIB) -L$(LIBFT_DIR) $(OS_L_FLAGS) -o $(NAME)
