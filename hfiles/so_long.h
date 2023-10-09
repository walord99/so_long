#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef OS
#  if OS == Linux
#   define mlx_new_image mlx_new_image_alpha
#  endif
# endif

# include <mlx.h>
# include <stdlib.h>

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;


#endif
