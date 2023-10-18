#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef OS
#  if OS == Linux
#   define mlx_new_image mlx_new_image_alpha
#  endif
# endif

# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <libft.h>
# include <stdbool.h>
# include <stdlib.h>

typedef enum tile_type
{
	WALL,
	EMPTY,
	START,
	END,
	COLLECT,
    ERROR
}				e_tile_type;

typedef struct vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct map
{
	t_vector	size;
	e_tile_type	**map;
}				t_map;

#endif
