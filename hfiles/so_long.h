#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef OS
#  if OS == Linux
#   define mlx_new_image mlx_new_image_alpha
#  endif
# endif

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_game {
	void	*mlx;
	void	*win;
}		t_game;

#endif
