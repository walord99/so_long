FILES		= main.c
SRC_DIR		= src
OBJ_DIR		= obj
SRC = $(addprefix src/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
CC = gcc
#ERROR_FLAGS = -Wall -Werror -Wextra

NAME			= so_long
MLX_LINUX		= minilibx-linux
MLX_MAC			= minilibx-mac
HEADER_DIR		= hfiles
LIBFT_DIR 		= libft
UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
  CC_FLAGS	= $(ERROR_FLAGS) -I$(MLX_LINUX)
  L_FLAGS	= $(ERROR_FLAGS) ./$(MLX_LINUX)/libmlx.a -lXext -lX11 -lm -lXrender
endif
ifeq ($(UNAME), Darwin)
  CC_FLAGS	= $(ERROR_FLAGS) -I$(MLX_MAC)
  L_FLAGS	= $(ERROR_FLAGS) -L$(MLX_MAC) -l$(MLX_MAC) -framework OpenGL -framework AppKit
endif

ALL: $(NAME)

$(NAME): _mlx _libft $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(L_FLAGS) ./$(LIBFT_DIR)/libft.a -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) -I$(HEADER_DIR) -I$(LIBFT_DIR) -D OS=$(UNAME) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

_mlx:
ifeq ($(UNAME), Linux)
	make -C $(MLX_LINUX)
endif
ifeq ($(UNAME), Darwin)
	make -C $(MLX_MAC)
endif

_libft:
	make -C libft

clean:
	rm -f $(NAME)

fclean: clean
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) fclean
ifeq ($(UNAME), Linux)
	make -C $(MLX_LINUX) clean
endif
ifeq ($(UNAME), Darwin)
	make -C $(MLX_MAC) clean
endif


