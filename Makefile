FILES		= main.c
SRC_DIR		= src
OBJ_DIR		= obj
SRC = $(addprefix src/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
CC = gcc

NAME			= so_long
MLX				= MLX42
MLX_LIB			= $(MLX)/build/libmlx42.a
HEADER_DIR		= hfiles
LIBFT_DIR 		= libft
UNAME 			= $(shell uname -s)
GLFW			= $(shell brew info glfw | grep files | cut -d " " -f1)/lib/
ifeq ($(UNAME), Linux)
  L_FLAGS	= -lXext -lX11 -lm
endif
ifeq ($(UNAME), Darwin)
  L_FLAGS	= -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"$(GLFW)"
endif
CC_FLAGS	= -I$(MLX)/include/ $(ERROR_FLAGS)
#ERROR_FLAGS = -Wall -Werror -Wextra

ALL: $(NAME)

$(NAME): _mlx _libft $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(L_FLAGS) $(MLX_LIB) ./$(LIBFT_DIR)/libft.a -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) $(ERROR_FLAGS) -I$(HEADER_DIR) -I$(LIBFT_DIR) -c $< -o $@

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
