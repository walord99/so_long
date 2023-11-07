FILES			= 	main.c \
					add_images_window.c \
					free_game.c \
					init.c \
					loop_hook.c \
					game_logic.c \
					\
					load_images/load_images.c \
					load_images/texture_loading.c \
					\
					map/parsing.c \
					map/validating.c \
					map/flood.c
SRC_DIR			= 	src
OBJ_DIR			= 	obj
SRC				= 	$(addprefix src/, $(FILES))
OBJ 			= 	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
CC				 = gcc

NAME			= 	so_long
MLX_DIR			= 	MLX42
MLX_BUILD_DIR	= 	$(MLX_DIR)/build
MLX				=	$(MLX_BUILD_DIR)/libmlx42.a
HEADER_DIR		= 	hfiles
LIBFT_DIR 		= 	libft
LIBFT			= 	$(LIBFT_DIR)/libft.a
UNAME 			= 	$(shell uname -s)

ifeq ($(UNAME), Linux)
  OS_L_FLAGS	= 	$(L_DEBUG) -lmlx42 -lglfw -lm -ldl -pthread -lft
endif
ifeq ($(UNAME), Darwin)
  OS_L_FLAGS	= 	-framework Cocoa -framework OpenGL -framework IOKit -L"$(shell brew info glfw | grep files | cut -d " " -f1)/lib/" -lft -lglfw -lmlx42
endif
INCLUDES		= 	-I$(MLX_DIR)/include/ -I$(HEADER_DIR) -I$(LIBFT_DIR)
#CC_DEBUG 		= 	-fsanitize=address -fno-omit-frame-pointer
#L_DEBUG		=	-lasan
ERROR_FLAGS 	= 	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -L$(MLX_BUILD_DIR) -L$(LIBFT_DIR) $(OS_L_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CC_DEBUG) -O1 $(INCLUDES) $(ERROR_FLAGS) -c $< -o $@ -g

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/load_images
	mkdir -p $(OBJ_DIR)/map

$(MLX):
	cmake $(MLX_DIR) -B $(MLX_BUILD_DIR)
	make -C $(MLX_BUILD_DIR)

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_BUILD_DIR) clean

re: clean all

valgrind:
	valgrind --leak-check=full ./so_long maps/test.ber

.PHONY: all, clean, fclean, re
