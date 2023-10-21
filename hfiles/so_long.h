#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef OS
#  if OS == Linux
#   define mlx_new_image mlx_new_image_alpha
#  endif
# endif

# include <MLX42/MLX42.h>
# include <errno.h>
# include <fcntl.h>
# include <libft.h>
# include <stdbool.h>
# include <stdio.h>
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

typedef struct game
{
	t_map		*map;
	mlx_t		*mlx;
}				t_game;

t_map			*parse_map(char *filepath);
int				render_map(t_game *game);

#endif
