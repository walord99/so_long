#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
# include <errno.h>
# include <fcntl.h>
# include <libft.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define SQ_SIZE 100

typedef enum tile_type
{
	WALL,
	EMPTY,
	START,
	END,
	COLLECT,
	ERROR
}				e_tile_type;

typedef struct map_data
{
	int			height;
	int			width;
	e_tile_type	**map;
	float		size_ratio;
}				t_map_data;

typedef struct game
{
	t_map_data	*map_data;
	mlx_t		*mlx;
}				t_game;

t_map_data		*parse_map(char *filepath);
int				render_map(t_game *game);
void			free_game(t_game *game);

#endif
