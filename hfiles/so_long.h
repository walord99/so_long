/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:53:47 by bplante           #+#    #+#             */
/*   Updated: 2023/10/29 21:45:00 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef enum e_tile_type
{
	WALL,
	EMPTY,
	START,
	END,
	COLLECT,
	ERROR
}				t_tile_type;

typedef struct s_map_data
{
	int			height;
	int			width;
	t_tile_type	**map;
}				t_map_data;

typedef struct s_collectible
{
	int			x;
	int			y;

}				t_collectible;

typedef struct s_images
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*start;
	mlx_image_t	*exit;
	mlx_image_t	*collect_hi;
	mlx_image_t	*player_frames[6];
}				t_images;

typedef struct s_game
{
	t_map_data	*map_data;
	mlx_t		*mlx;
	int			player_x;
	int			player_y;
	t_list		*collectables;
	t_images	*images;
}				t_game;

t_map_data		*parse_map(char *filepath);
int				render_map(t_game *game);
void			free_game(t_game *game);
t_collectible	*init_collectible(int x, int y);
void			init_game(t_game *game);
void			loop_hook(void *param);
void			load_images(mlx_t *mlx, t_images *images);

#endif
