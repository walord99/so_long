#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef OS
#  if OS == Linux
#   define mlx_new_image mlx_new_image_alpha
#  endif
# endif

# include <MLX42/MLX42.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
}			t_game;

#endif
